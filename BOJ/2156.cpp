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
int consecutive_sum[10001];
int input_sequence[10001];
int n;

int CalcConsecutiveSum() {
	if (n == 1) {
		return input_sequence[0];
	}
	else if (n == 2) {
		return input_sequence[0] + input_sequence[1];
	}
	else if (n == 3) {
		return max(input_sequence[0] + input_sequence[2], max(input_sequence[0] + input_sequence[1], input_sequence[1]+ input_sequence[2]));
	}
	else{
		consecutive_sum[0] = input_sequence[0];
		consecutive_sum[1] = input_sequence[0] + input_sequence[1];
		consecutive_sum[2] = max(input_sequence[0] + input_sequence[2], max(input_sequence[0] + input_sequence[1], input_sequence[1]+ input_sequence[2]));
		for (int i = 3; i < n; i++) {
			consecutive_sum[i] = max(consecutive_sum[i - 1], max(consecutive_sum[i - 2] + input_sequence[i], consecutive_sum[i - 3] + input_sequence[i] + input_sequence[i - 1]));
		}	
		return consecutive_sum[n - 1];
	}
	
}
int main()
{
	
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input_sequence[i];
	}
	
	cout << CalcConsecutiveSum();
	
	
 
	

    return 0;
}

