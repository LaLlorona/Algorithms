#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

const int NEG_INF = -987654321;
int consecutive_sum[100001];
int input_sequence[100001];
int n;

void CalcConsecutiveSum() {
	for (int i = 1; i < n; i++) {
		consecutive_sum[i] = max(consecutive_sum[i - 1] , 0) + input_sequence[i];
	}
}
int main()
{
	
	
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input_sequence[i];
		consecutive_sum[i] = input_sequence[i];
	}
	CalcConsecutiveSum();
 	int ret = NEG_INF;
	for (int i = 0; i < n; i++) {
		ret = max(ret, consecutive_sum[i]);
	}
	cout << ret << '\n';
 
	

    return 0;
}

