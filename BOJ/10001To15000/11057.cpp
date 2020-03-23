#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <cstddef>
#include <algorithm>
#include <cstring>

using namespace std;

long long cache[1001][10];

const long long MOD = 10007;
long long StairNum() {
	memset(cache, 0, sizeof(cache));
	for (int i = 0; i < 10; i++) {
		cache[1][i] = 1;
	}
	
	for (int i = 2; i < 1001; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				cache[i][j] = (cache[i][j] + cache[i - 1][j - k]) % MOD;
			}
			
		}
	}
	int n;
	cin >> n;
	long long ret = 0;
	for (int i = 0; i < 10; i++) {
		ret  = (ret + cache[n][i]) % MOD;
	}
	
	
	
	return ret;
}

int main()
{
	
	
	
	cout << StairNum() << '\n';
	
	
    return 0;
}

