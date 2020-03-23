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

long long cache[101][10];
const int INF = 987654321;
const long long MOD = 1000000000;
long long StairNum() {
	memset(cache, 0, sizeof(cache));
	for (int i = 1; i < 10; i++) {
		cache[1][i] = 1;
	}
	
	for (int i = 2; i < 101; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				cache[i][j] = cache[i - 1][1] % MOD;
			}
			else if (j == 9) {
				cache[i][j] = cache[i - 1][8] % MOD;
			}
			else{
				cache[i][j] = (cache[i - 1][j - 1]  + cache[i - 1][j + 1]) % MOD;
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

