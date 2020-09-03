#include <bits/stdc++.h>


using namespace std;

const int INF = 987654321;
int num_coin_type;
int target_value;
int coin_value[100];
int min_coin_use[10001];

int CalcMinCoinUse(int value) {
	for (int i = 0; i < num_coin_type; i++) {
		if (value == coin_value[i]) {
			return 1;
		}
	}
	
	if (value < coin_value[0]) { // impossible to make 
		return INF; 
	}
	
	
	else {
		int& ret = min_coin_use[value];
		if (ret != -1) {
			return ret;
		}
		
		int min_cand = INF;
		for (int i = 0; i < num_coin_type; i++) {
			min_cand = min(min_cand, CalcMinCoinUse(value - coin_value[i]) + 1);
		}
		return ret = min_cand;
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
	
	while (cin >> num_coin_type >> target_value) {
		
		memset(min_coin_use, -1, sizeof(min_coin_use));
		for (int i = 0; i < num_coin_type; i++) {
			cin >> coin_value[i];
		}
		sort(coin_value, coin_value + num_coin_type);
		int result = CalcMinCoinUse(target_value);
		if (result >= INF) {
			cout << -1;
		}
		else {
			cout << result;
		}
	}
    

    return 0;
}

