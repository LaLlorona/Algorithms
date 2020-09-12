#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
int n;

const ll MOD = 1000000009;

ll num_comb[100001][4]; // num_comb[i][j] : number of combination to make i when the last used number if j

void FillNumComb() {
	memset(num_comb, 0, sizeof(num_comb));
	
	num_comb[1][1] = 1;
	
	num_comb[2][2] = 1;
	
	num_comb[3][3] = 1;
	num_comb[3][2] = 1;
	num_comb[3][1] = 1;
	
	for (int i = 4; i <= 100000; i++) {
		num_comb[i][1] = (num_comb[i - 1][2] + num_comb[i - 1][3]) % MOD;
		num_comb[i][2] = (num_comb[i - 2][1] + num_comb[i - 2][3]) % MOD;
		num_comb[i][3] = (num_comb[i - 3][1] + num_comb[i - 3][2]) % MOD;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	FillNumComb();
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		int num;
		cin >> num;
		ll result = 0;
		for (int i = 1; i <= 3; i++) {
			result += num_comb[num][i];
		}
		cout << result % MOD << "\n";
	}
    

    return 0;
}

