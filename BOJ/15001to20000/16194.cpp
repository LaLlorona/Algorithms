#include <bits/stdc++.h>


using namespace std;

int target_cards;
const int INF = 987654321;

int min_cost[1001];
int card_pack_price[1001];

int CalcMinCost(int cards) {
	if (cards < 0 ){
		return INF;
	}
	if (cards == 0) {
		return 0;
	}
	int& ret = min_cost[cards];
	if (ret != -1) {
		return ret;
	}
	ret = INF;
	for (int i = 1; i <= cards; i++) {
		ret = min(ret, CalcMinCost(cards - i) + card_pack_price[i]);
	}
	return ret;
}



int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> target_cards) {
		memset(min_cost, -1, sizeof(min_cost));
		for (int i = 1; i <= target_cards; i++) {
			cin >> card_pack_price[i]; 
		}
		cout << CalcMinCost(target_cards) << "\n";
	}
    

    return 0;
}

