#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

const ll MAX = 1000001;
const ll MOD = 1000000009;
ll num_comb[MAX + 1];

void FillNumComb() {
	num_comb[0] = 0;
	num_comb[1] = 1;
	num_comb[2] = 2;
	num_comb[3] = 4;
	for (ll i = 4; i < MAX; i++) {
		num_comb[i] = (num_comb[i - 1] + num_comb[i - 2] + num_comb[i - 3]) % MOD;
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
	
	FillNumComb();
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		int num;
		cin >> num;
		cout << num_comb[num] << "\n";
	}
    

    return 0;
}

