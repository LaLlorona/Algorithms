
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int INF = 987654321;
int original_array[100];

int partial_sum[100];
int partial_square_sum[100];

int cache[100][10];

int len_original_array;
int num_chunk;

void FillPartialSum() {
    sort(original_array, original_array + len_original_array);
    partial_sum[0] = original_array[0];
    partial_square_sum[0] = original_array[0] * original_array[0];
    for (int i = 0; i < len_original_array; i++) {
        partial_sum[i] = partial_sum[i - 1] + original_array[i];
        partial_square_sum[i] = partial_square_sum[i - 1] + original_array[i] * original_array[i];
    }
}

int MinError(int index_from, int index_to) {
    int sum = partial_sum[index_to] - (index_from == 0 ? 0 : partial_sum[index_from - 1]);
    int square_sum = partial_square_sum[index_to] - (index_from == 0 ? 0 : partial_square_sum[index_from - 1]);
    int average = int(double(sum / (index_to - index_from + 1)) + 0.5);
    int ret = square_sum - 2 * average * sum + average * average * (index_to - index_from + 1);
}

int Quantize(int index_quantize_from, int num_leftchunk) {
    if (index_quantize_from == len_original_array) {
        return 0;
    }
    
    if (num_leftchunk == 0) {
        return INF;
    }
    
    int& ret = cache[index_quantize_from][num_leftchunk];
    
    if (ret != -1) {
        return ret;
    }
    
    ret = INF;
    
    for (int size = 1; size + index_quantize_from <= len_original_array; size++) {
        ret = min(ret, MinError(index_quantize_from, index_quantize_from + size - 1) + Quantize(index_quantize_from + size, num_leftchunk - 1));
    }
    return ret;
}

int main()
{
    int num_testcase;
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++) {
        cin >> len_original_array;
        cin >> num_chunk;
        memset(cache,-1,sizeof(cache));
        for (int j = 0; j < len_original_array; j++) {
            cin >> original_array[j];
        }
        FillPartialSum();
        cout << Quantize(0, num_chunk) << endl;
    }
    

    return 0;
}
