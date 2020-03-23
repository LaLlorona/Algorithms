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

int min_squre_sum[100001];
const int MAX_NUM = 100000;
const int INF = 987654321;
int n;

void CalcMinSquareSum() {
	min_squre_sum[0] = 0;
	min_squre_sum[1] = 1;
	min_squre_sum[2] = 2;
	for (int i = 3; i <= MAX_NUM; i++) {
		for (int j = 1; j <= sqrt(i); j++) {
			min_squre_sum[i] = min(min_squre_sum[i], min_squre_sum[i - j * j] + 1);
		}
	}
}
	

int main()
{
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	cin >> n;
	for (int i = 0; i < 100001; i++) {
		min_squre_sum[i] = INF;
	}
	
	CalcMinSquareSum();
	
	cout << min_squre_sum[n];
	
		
		
	
	
 
	

    return 0;
}


