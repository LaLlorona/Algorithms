#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int LIS[1001] = {1,};
int seq[1001] = {0,};

int CalcLIS() {
	LIS [n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			if (seq[i] < seq[j]) {
				LIS[i] = max(LIS[i], 1 + LIS[j]);
			}
		}
	}
	int ret = 0;
	
	for (int i = 0; i < n; i++) {
		ret = max(ret, LIS[i]);
	}
	
	return ret;
}

int main()
{
	
	
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
 
	cin >> n;
	for (int i = 0; i < n; i++) {
		LIS[i] = 1;
		cin >> seq[i]; 
	}
	cout << CalcLIS() << endl;

    return 0;
}

