#include <bits/stdc++.h>


using namespace std;

int num_cards;
int deck_left[2001];
int deck_right[2001];
int max_score_from[2001][2001];
const int INF = 987654321;

int CalcMaxScoreFrom(int left_index, int right_index) {
	if (left_index == num_cards || right_index == num_cards) {
		return 0;
	}
	int& ret = max_score_from[left_index][right_index];
	if (ret != -1) {
		return ret;
	}
	ret = -INF;
	// 1. abandon only left card
	ret = max(ret, CalcMaxScoreFrom(left_index + 1, right_index));
	
	
	// 2. abandon both num_cards
	ret = max(ret, CalcMaxScoreFrom(left_index + 1, right_index + 1));
	
	// 3. if the card on the right side is smaller then the card on the left side, abandon only right card and get a score with abandoned right num_cards
	if (deck_left[left_index] > deck_right[right_index]) {
		ret = max(ret, deck_right[right_index] + CalcMaxScoreFrom(left_index, right_index + 1));
	}
	return ret;
}




int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	while (cin >> num_cards) {
		memset(max_score_from, -1, sizeof(max_score_from));
		for (int i = 0; i < num_cards; i++) {
			cin >> deck_left[i];
		}
		for (int i = 0; i < num_cards; i++) {
			cin >> deck_right[i];
		}
		cout << CalcMaxScoreFrom(0, 0) << "\n";
		
	}
    

    return 0;
}

