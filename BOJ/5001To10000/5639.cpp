#include <bits/stdc++.h>
//#include <iostream>

using namespace std;

int input_arr[10001];
int FindTarget(int from, int to, int target) {
	int lo = from;
	int hi = to;
	int mid;
	int ret = -1;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (input_arr[mid] > target) {
			ret = mid;
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	return ret;
}

void PostOrder(int from, int to) {
	//cout << from << " " << to << "\n";
	if (from > to) {
		return;
	}
	int begin_right = FindTarget(from, to, input_arr[from]);
	//cout << begin_right << "\n";
	if (begin_right == -1) { //when there is no right child of the root
		PostOrder(from + 1, to);
		cout << input_arr[from] << "\n";
	}
	else {
		PostOrder(from + 1, begin_right - 1);
		PostOrder(begin_right, to);
		cout << input_arr[from] << "\n";
	}
}
int main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	int count, num;
	count = 0;
	while (cin >> num) {
		input_arr[count] = num;
		count++;
	}
	PostOrder(0, count - 1);
	
	
	
	
	
	
	return 0;
}
