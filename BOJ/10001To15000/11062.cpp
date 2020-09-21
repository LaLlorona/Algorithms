#include <bits/stdc++.h>


using namespace std;

const int my_turn = 0;
int cards[1001];
int num_card;
int max_score_at[1001][1001][2]; // [left][right][turn] : calculate possible max score to earn

int CalcMaxScore(int left, int right, int turn) {
	if (left == right) {
		if (turn == my_turn) {
			return cards[left]; 
		}
		else {
			return 0;
		}
	}
	int& ret = max_score_at[left][right][turn];
	if (ret != -1) {
		return ret;
	}
	if (turn == my_turn) {
		ret = max(cards[left] + CalcMaxScore(left + 1, right, turn ^ 1), cards[right] + CalcMaxScore(left, right - 1, turn ^ 1));
	}
	else {
		ret = min(CalcMaxScore(left + 1, right, turn ^ 1), CalcMaxScore(left, right - 1, turn ^ 1));
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
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		memset(max_score_at, -1, sizeof(max_score_at));
		cin >> num_card;
		for (int i = 0; i < num_card; i++) {
			cin >> cards[i];
		}
		cout << CalcMaxScore(0, num_card - 1, my_turn) << "\n";
	}
    

    return 0;
}

