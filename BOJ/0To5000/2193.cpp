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

long long cache[91][2];
long long PinaryNumber(int n, int last_num) {
	
	if (n == 1 && last_num == 1) {
		return 1;
	}
	else if (n == 1 && last_num == 0) {
		return 0;
	}
	else if (n == 2 && last_num == 1) {
		return 0;
	}
	else if (n == 2 && last_num == 0) {
		return 1;
	}
	
	long long& ret = cache[n][last_num];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	
	if (last_num == 1) {
		ret = PinaryNumber(n - 1 , 0);
	}
	else if (last_num == 0) {
		ret = PinaryNumber(n - 1, 0) + PinaryNumber(n - 1, 1);
	}
	
	return ret;
	
	
	
}

int main()
{
	
	
	int n;
	cin >> n;
	memset(cache, -1 ,sizeof(cache));
	cout << PinaryNumber(n, 1) + PinaryNumber(n, 0);
	
	
}

