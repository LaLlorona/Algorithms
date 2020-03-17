#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits>   
using namespace std;

int len_input_array_first;
int len_input_array_second;
int input_array_first[100];
int input_array_second[100];
int cache[101][101];

long long NEGINF = numeric_limits<long long>::min();

int JLIS (int index_start_first, int index_start_second) { // returns maximum length of JointLongestIncreasingSubsequence 
    
    
    int& ret = cache[index_start_first + 1][index_start_second + 1];
    
    if (ret != -1) {
        return ret;
    }
    
    ret = 0;
    
    long long a = (index_start_first == -1 ? NEGINF : input_array_first[index_start_first]);
    long long b = (index_start_second == -1 ? NEGINF : input_array_second[index_start_second]);
    long long threshold = max(a,b) ;
    
    for (int i = index_start_first + 1; i < len_input_array_first; i++) {
        if (input_array_first[i] > threshold) {
            ret = max(ret, JLIS(i,index_start_second) + 1);
        }
    }   
    for (int j = index_start_second + 1; j < len_input_array_second; j++) {
        if (input_array_second[j] > threshold) {
            ret = max(ret, JLIS(index_start_first,j) + 1);
        }
    }
        
    
    
    return ret;
}

int main()
{
    int num_testcase;
    int length_JLIS;
    cin >> num_testcase;
    for (int a = 0; a < num_testcase; a++) {
        cin >> len_input_array_first;
        cin >> len_input_array_second;
        length_JLIS = 0;
        memset(cache,-1,sizeof(cache));
        for (int b = 0; b < len_input_array_first; b++) {
            cin >> input_array_first[b];
        }
        for (int c = 0; c < len_input_array_second; c++) {
            cin >> input_array_second[c];
        }
        
        for(int m = -1; m < len_input_array_first; m++) {
            for (int n = -1; n < len_input_array_second; n++) {
                length_JLIS = max(length_JLIS, JLIS(m, n));
            }
        }
        // length_JLIS = JLIS(-1, -1);
        cout << length_JLIS << endl;
    }
    

    return 0;
}
