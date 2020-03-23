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

int cache[1001];
const int INF = 987654321;
int Tiling(int n) {
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 3;
	}
	int& ret = cache[n];
	
	if (ret != -1 ) {
		return ret;
	}
	ret = (Tiling(n - 1) + 2 * Tiling (n - 2)) % 10007;
	
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	
	
	int n;
	cin >> n;
	cout << Tiling(n);
    return 0;
}

