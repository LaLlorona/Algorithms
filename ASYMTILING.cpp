#include <iostream>
#include <cstring>

using namespace std;
int cache[101];
const int MOD = 1000000007;
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
    
    ret = (Tiling(width - 1) + Tiling(width - 2)) % MOD;
    
    return ret;
}

int AymTiling(int width) {
    if (width <= 2) {
        return 0;
    }
    if (width % 2 == 1) {
        return (Tiling(width) - Tiling(width / 2) + MOD) % MOD;
    }
    else{
        int ret = (Tiling(width) - Tiling(width / 2) + MOD) % MOD;
        ret = (ret + MOD - Tiling((width - 2) / 2)) % MOD;
        return ret;
    }
}
int main()
{
    int num_testcase;
    cin >> num_testcase;
    int n;
    memset(cache,-1,sizeof(cache));
    for (int i = 0; i < num_testcase; i++){
        cin >> n;
        cout << AymTiling(n) << endl;
    }
    
    
    
    

    return 0;
}
