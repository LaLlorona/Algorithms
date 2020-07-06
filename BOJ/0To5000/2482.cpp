#include <bits/stdc++.h>


using namespace std;

int dp[1001][1001]; // N color, K choose;
int num_total, num_choose;
const int MOD = 1000000003;

int Combination(int n, int k) {
	for (int i = 0; i <= 1000; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	for (int i = 2; i <= 1000; i++) {
		for (int j = 2; j <= 1000; j++) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
	return (dp[n - 3][k - 1] + dp[n - 1][k]) % MOD;

	
}

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_total >> num_choose) {
		memset(dp, 0, sizeof(dp));
		cout << Combination(num_total, num_choose) << "\n";
	}
    

    return 0;
}

