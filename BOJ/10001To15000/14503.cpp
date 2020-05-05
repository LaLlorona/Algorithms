#include <bits/stdc++.h>


using namespace std;

int width, height;
int initial_y, initial_x;
int direction;
int board[51][51];
int dct_y[4] = {-1, 0, 1, 0};
int dct_x[4] = {0, 1, 0, -1};


int LeftDirection(int dct) {
	if (dct != 0) {
		return dct - 1;
	}
	else {
		return 3;
	}
}

bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 && x < width);
}

void Clean() {
	board[initial_y][initial_x] = 2;
	int rotate_count = 0;
	int current_y = initial_y;
	int current_x = initial_x;
	while (true) {
		board[current_y][current_x] = 2;
		int left_direction = LeftDirection(direction);
		int next_y = current_y + dct_y[left_direction];
		int next_x = current_x + dct_x[left_direction];
		
		if (IsInBound(next_y, next_x) && board[next_y][next_x] == 0) {
			current_y = next_y;
			current_x = next_x;
			direction = left_direction;
			rotate_count = 0;
		}
		else if (rotate_count != 4) {
			rotate_count++;
			direction = left_direction;
		}
		else {
			rotate_count = 0;
			next_y = current_y + dct_y[LeftDirection(left_direction)];
			next_x = current_x + dct_x[LeftDirection(left_direction)];
			if (!IsInBound(next_y, next_x) || board[next_y][next_x] == 1) {
				break;
			}
			else {
				current_y = next_y;
				current_x = next_x;
			}
			
		}
	}
}


int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> height >> width >> initial_y >> initial_x >> direction) {
		int cleaned = 0;
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				cin >> board[y][x];
			}
		}
		Clean();
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				if (board[y][x] == 2) {
					cleaned++;
				}
			}
		}
		cout << cleaned << "\n";
	}
    

    return 0;
}

