#include <bits/stdc++.h>


using namespace std;

int board_colorblind[100][100];// 0 rg 1 b 3 visited
int board_normal[100][100]; // 0 r 1 g 2 b 3 visited
int board_size;

int dct_y[4] = {-1, 0, 1, 0};
int dct_x[4] = {0, 1, 0, -1};

bool IsInBound(int y, int x) {
	return (y >= 0 && y < board_size && x >= 0 && x < board_size);
}
void FillSafeZone(int current_y, int current_x, int color, int board[][100]) {
	board[current_y][current_x] = 3;
	for (int i = 0; i < 4; i++) {
		int next_y = current_y + dct_y[i];
		int next_x = current_x + dct_x[i];
		if (IsInBound(next_y, next_x) && board[next_y][next_x] == color) {
			FillSafeZone(next_y, next_x, color, board);
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
	while (cin >> board_size) {
		for (int y = 0; y < board_size; y++) {
			for (int x = 0; x < board_size; x++) {
				char color;
				cin >> color;
				if (color == 'R') {
					board_colorblind[y][x] = 0;
					board_normal[y][x] = 0;
				}
				else if (color == 'G') {
					board_colorblind[y][x] = 0;
					board_normal[y][x] = 1;
				}
				else {
					board_colorblind[y][x] = 1;
					board_normal[y][x] = 2;
				}
			}
		}
		int num_area_blind = 0;
		int num_area_normal = 0;
		for (int y = 0; y < board_size; y++) {
			for (int x = 0; x < board_size; x++) {
				int current_color_normal = board_normal[y][x];
				int current_color_blind = board_colorblind[y][x];
				if (current_color_normal != 3) {
					num_area_normal++;
					FillSafeZone(y, x, current_color_normal, board_normal);
				}
				if (current_color_blind != 3) {
					num_area_blind++;
					FillSafeZone(y, x, current_color_blind, board_colorblind);
				}
			}
		}
		cout << num_area_normal << " " << num_area_blind << "\n";
		
	}
	
    

    return 0;
}

