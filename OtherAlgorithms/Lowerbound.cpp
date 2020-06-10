//#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int arr[10] = {1,2,2,3,3,4,4,5,5,78};
int LowerBound(int from, int to, int target) {
	int lo = from;
	int hi = to;
	int mid = lo;
	int ret = hi;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (arr[mid] >= target) {
			ret = mid;
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	return ret;
	
}

int main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	for (int i = 0; i < 99; i++) {
		cout << "lower bound of " << i << " is " << LowerBound(0, 9, i) << "\n";
	}
	
	
	
	return 0;
}


