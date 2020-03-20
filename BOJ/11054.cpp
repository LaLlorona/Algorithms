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
int LDS[1001];
int LIS_unitl[1001];
int seq[1001];

void CalcLDS() {
	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			if (seq[i] > seq[j]) {
				LDS[i] = max(LDS[i], 1 + LDS[j]);
			}
		}
	}
}

void CalcLISUntil() {
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (seq[i] > seq[j]) {
				LIS_unitl[i] = max(LIS_unitl[i], 1 + LIS_unitl[j]);
			}
		}
	}
}


int main()
{
	
	
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
 
	cin >> n;
	for (int i = 0; i < n; i++) {
		LDS[i] = 1;
		LIS_unitl[i] = 1;
		cin >> seq[i]; 
	}
	CalcLDS();
	CalcLISUntil();
	int ret = 0;
	for (int i = 0; i < n; i++) {
		ret = max(ret, LIS_unitl[i] + LDS[i] - 1 );
	}
	cout << ret << endl;

    return 0;
}

