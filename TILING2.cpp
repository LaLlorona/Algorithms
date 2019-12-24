/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstring>

using namespace std;
int cache[101];
int Tiling(int width) {
    if (width == 1) {
        return 1;
    }
    
    if (width == 2) {
        return 2;
    }
    
    int& ret = cache[width];
    
    if (ret != -1) {
        return ret;
    }
    
    ret = (Tiling(width - 1) + Tiling(width - 2)) % 1000000007;
    
    return ret;
}
int main()
{
    int num_testcase;
    cin >> num_testcase;
    int n;
    memset(cache,-1,sizeof(cache));
    for (int i = 0; i < num_testcase; i++){
        cin >> n;
        cout << Tiling(n) << endl;
    }
    
    
    
    

    return 0;
}
