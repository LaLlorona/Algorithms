#include <bits/stdc++.h>


using namespace std;

const int MAX = 100;
int height, width;

int dct_y[4] = {0, -1, 0, 1};
int dct_x[4] = {-1, 0, 1, 0};

bool board[MAX][MAX];
bool future_board[MAX][MAX];
bool visited[MAX][MAX];
bool is_adjacent_air[MAX][MAX];

bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 & x < width);
}

void UpdateAir(int y, int x) {
	is_adjacent_air[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int next_y = y + dct_y[i];
		int next_x = x + dct_x[i];
		if (IsInBound(next_y, next_x) && board[next_y][next_x] == 0 && is_adjacent_air[next_y][next_x] == false) {
			UpdateAir(next_y, next_x);
		}
	}
}

void Dfs(int y, int x, bool board[][MAX]) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int next_y = y + dct_y[i];
		int next_x = x + dct_x[i];
		if (board[next_y][next_x] && !visited[next_y][next_x]) {
			Dfs(next_y, next_x, board);
		}
	}
}


void UpdateBoard() {
	UpdateAir(0, 0);
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			for (int i = 0; i < 4; i++) {
				int next_y = y + dct_y[i];
				int next_x = x + dct_x[i];
				if (IsInBound(next_y, next_x) && board[next_y][next_x] == 0 && is_adjacent_air[next_y][next_x]) {
					future_board[y][x] = 0;
				}
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
	
	while (cin >> height >> width) {
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				cin >> board[y][x];
				future_board[y][x] = board[y][x];
			}
		}
		int current_hour = 0;
		
		
		while (true) {
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					board[y][x] = future_board[y][x];
				}
			}
			memset(is_adjacent_air, 0, sizeof(is_adjacent_air));
			UpdateBoard();
			// cout << current_hour << "\n";
			// for (int y = 0; y < height; y++) {
			// 	for (int x = 0; x < width; x++) {
			// 		cout << board[y][x] << " ";
			// 	}
			// 	cout << "\n";
			// }
			int future_chunk = 0;
			int current_chunk = 0;
			
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					if (board[y][x]) {
						current_chunk++;
					}
				}
			}
			if (current_chunk == 0) {
				cout << current_hour << "\n";
				cout << current_chunk << "\n";
				break;
			}
			current_hour++;
			
			memset(visited, 0, sizeof(visited));
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					if (future_board[y][x] && !visited[y][x]) {
						future_chunk++;
						Dfs(y, x, future_board);
					}
				}
			}
			if (future_chunk == 0) {
				cout << current_hour << "\n";
				cout << current_chunk << "\n";
				break;
			}
			
		}
		
	}
    

    return 0;
}

