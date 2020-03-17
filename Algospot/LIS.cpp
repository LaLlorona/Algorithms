/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int len_input_array;
int input_array [500];
int cache[501];

int LIS (int index_start) { // returns maximum length of LongestIncreasingSubsequence
    if (index_start == len_input_array - 1) {
        return 1;
    }
    int& ret = cache[index_start];
    
    if (ret != -1) {
        return ret;
    }
    
    ret = 1;
    
    for (int i = index_start + 1; i < len_input_array; i++) {
        if (input_array[i] > input_array[index_start]) {
            ret = max(ret, LIS(i) + 1);
        }
    }
    
    return ret;
}

int main()
{
    int num_testcase;
    int length_LIS;
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++) {
        cin >> len_input_array;
        length_LIS = 0;
        memset(cache,-1,sizeof(cache));
        for (int j = 0; j < len_input_array; j++) {
            cin >> input_array[j];
        }
        
        for (int k = 0; k < len_input_array; k++) {
            length_LIS = max(length_LIS, LIS(k));
        }
        cout << length_LIS << endl;
    }
    

    return 0;
}
