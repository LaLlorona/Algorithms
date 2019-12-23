
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int original_array[100];

int partial_sum[100];
int partial_square_sum[100];

int cache[100][10];

int len_original_array;
int num_chunk;

void FillPartialSum() {
    for (int i = 0; i < len_original_array; i++) {
        if (i == 0) {
            partial_sum[i] = original_array[i];
            partial_square_sum[i] = original_array[i] * original_array[i];
        }
        else{
            partial_sum[i] = partial_sum[i - 1] + original_array[i];
            partial_square_sum[i] = partial_square_sum[i - 1] + original_array[i] * original_array[i];
        }
    }
}

int MinError(int index_from, int index_to) {
    int sum = partial_sum[index_to] - (index_from == 0 ? 0 : partial_sum[index_from - 1]);
    int square_sum = partial_square_sum[index_to] - (index_from == 0 ? 0 : partial_square_sum[index_from - 1]);
    int average = int(0.5+ double(sum / (index_to - index_from + 1)));
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
    
    for (int size = 1; size < len_original_array - index_quantize_from; size++) {
        ret = min(MinError(index_quantize_from, index_quantize_from + size - 1) + Quantize(index_quantize_from + size, num_leftchunk - 1));
    }
    return ret;
}

int main()
{
    cout<<"Hello World";

    return 0;
}
