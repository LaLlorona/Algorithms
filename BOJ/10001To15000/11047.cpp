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

int type_coins;
int target_money;
vector<int> coins;
int FindBestCoin(int current_money) {
	int len = coins.size();
	for (int i = len - 1; i >= 0; i--) {
		if (coins[i] <= current_money) {
			return coins[i];
		}
	}
	return 1;
	
}
int MinimumCoins(int total_money) {
	int left_money = total_money;
	int coin_count = 0;
	while (left_money != 0) {
		int choice = FindBestCoin(left_money);
		coin_count += left_money / choice;
		left_money %= choice;
	}
	return coin_count;
}
int main()
{
	// std::ios_base::sync_with_stdio(false); 
	// std::cin.tie(NULL); 
	// std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> type_coins) {
		cin >> target_money;
		coins.clear();
		for (int i = 0; i < type_coins; i++) {
			int money_unit;
			cin >> money_unit;
			coins.push_back(money_unit);
		}
		cout << MinimumCoins(target_money) << "\n";
	}
    

    return 0;
}

