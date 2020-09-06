#include <bits/stdc++.h>


using namespace std;

int possible_comb_until[100001][3];
const int MOD = 9901;

void FillPossibleComb() {
	possible_comb_until[1][0] = 1;
	possible_comb_until[1][1] = 1;
	possible_comb_until[1][2] = 1;
	
	for (int i = 2; i < 100001; i++) {
		possible_comb_until[i][0] = (possible_comb_until[i - 1][0] + possible_comb_until[i - 1][1] + possible_comb_until[i - 1][2]) % MOD;
		possible_comb_until[i][1] = (possible_comb_until[i - 1][0] + possible_comb_until[i - 1][2]) % MOD;
		possible_comb_until[i][2] = (possible_comb_until[i - 1][0] + possible_comb_until[i - 1][1]) % MOD;
	}
}



int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	memset(possible_comb_until, 0, sizeof(possible_comb_until));
	FillPossibleComb();
	
	int num;
	while (cin >> num) {
		cout << (possible_comb_until[num][0] + possible_comb_until[num][1] + possible_comb_until[num][2]) % MOD << "\n";
	}
	
    

    return 0;
}

