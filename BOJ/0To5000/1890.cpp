#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

int board_size;

const int MAX = 101;
int board[MAX][MAX];
ll possible_path[MAX][MAX];

bool IsInBound(int y, int x) {
	return (y >= 0 && y < board_size && x >= 0 && x < board_size);	
}

ll CalcPath(int y, int x) {
	if (y == 0 && x == 0) {
		return 1;
	}
	else {
		ll& ret = possible_path[y][x];
		if (ret != -1) {
			return ret;
		}
		ret = 0;
		for (int i = 1; i <= 9; i++) {
			if (IsInBound(y - i, x) && board[y - i][x] == i) {
				ret += CalcPath(y - i, x);
			}
			if (IsInBound(y, x - 1) && board[y][x - i] == i) {
				ret += CalcPath(y, x - i);
			}
		}
		return ret;
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
	
	while (cin >> board_size) {
		memset(possible_path, -1, sizeof(possible_path));
		for (int y = 0; y < board_size; y++) {
			for (int x = 0; x < board_size; x++) {
				cin >> board[y][x];
			}
		}
		cout << CalcPath(board_size - 1, board_size - 1);
	}
    

    return 0;
}

