#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
long long remain_number_and_sum[201][201]; // remain number and sum 
int MAX_NUM = 201;
const int MOD =  1000000000;
int n;

void CalcRemainSumAndNumber() {
	for (int i = 0; i < MAX_NUM; i++) {
		remain_number_and_sum[1][i] = 1; // 숫자를 1개만 써서 i 를 만드는 경우는 한가지 뿐 
	}
	for (int i = 1; i < MAX_NUM; i++) { // 숫자를 몇개 쓰는지
		for (int j = 0; j < MAX_NUM; j++) { // 총 합이 몇인지
			for (int k = 0; k <= j; k++) {
				remain_number_and_sum[i][j] = (remain_number_and_sum[i][j] + remain_number_and_sum[i - 1][j - k]) % MOD;
			}
		}
	}
	
	
	
}

int main()
{
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	// memset(remain_number_and_sum, 0, sizeof(remain_number_and_sum));
	
	// int sum;
	// int k;
	// CalcRemainSumAndNumber();
	// while (cin >> sum >> k) {
	// 	cout << remain_number_and_sum[k][sum] << "\n";
	// }
	int sum;
	int k;
	cin >> sum >> k;
	cout << remain_number_and_sum[k][sum] << "\n";
	
	
	
    return 0;
}


