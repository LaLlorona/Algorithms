#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> pii;
const int MAX_VALUE = 10000;
int num_coin_type;
int num_combinations[10001];
vector<pii> coins;
int target_price;


void FillNumCombinations() {
	
	num_combinations[0] = 1;
	
	
	// fill the base case
	for (int j = 0; j < num_coin_type; j++) {
		int coin_value = coins[j].first;
		int coin_num = coins[j].second;
		for (int i = target_price; i >= 0; i--) {
			for (int k = 1; k <= coin_num && i - coin_value * k >= 0; k++) {
				num_combinations[i] += num_combinations[i - coin_value * k];
			}
		}
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
	
	
	while (cin >> target_price) {
		cin >> num_coin_type;
		coins.clear();
		memset(num_combinations, 0, sizeof(num_combinations));
		for (int i = 0; i < num_coin_type; i++) {
			int coin_price, coin_num;
			cin >> coin_price >> coin_num;
			coins.push_back({coin_price, coin_num});
		}
		sort(coins.begin(), coins.end());
		FillNumCombinations();
		cout << num_combinations[target_price] << "\n";
	}
	
    

    return 0;
}

