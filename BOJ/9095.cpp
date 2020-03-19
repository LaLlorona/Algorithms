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

int cache[12];
const int INF = 987654321;
int Counting(int n) {
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}
	
	if (n == 3) {
		return 4;
	}
	int& ret = cache[n];
	
	if (ret != -1 ) {
		return ret;
	}
	ret = Counting(n - 1) + Counting(n - 2) + Counting(n - 3);
	
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	
	int num_testcase;
	int n;
	cin >> num_testcase;
	for (int i = 0; i < num_testcase; i++) {
		cin >> n;
		cout << Counting(n) << '\n';
	}
	
    return 0;
}

