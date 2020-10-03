#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> pii;
const int MAX = 100;
int height, width;

int dct_y[4] = {0, -1, 0, 1};
int dct_x[4] = {-1, 0, 1, 0};

int current_cheese[MAX][MAX];
int next_cheese[MAX][MAX];
bool touched_air[MAX][MAX];

bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 & x < width);
}

void UpdateTouchedAir(int y, int x) {
	// it should be memset-ed to 0
	touched_air[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int next_y = y + dct_y[i];
		int next_x = x + dct_x[i];
		if (IsInBound(next_y, next_x) && !touched_air[next_y][next_x] && current_cheese[next_y][next_x] == 0) {
			UpdateTouchedAir(next_y, next_x);
		}
	}
}

void UpdateNextCheese() {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int adjacent_air = 0;
			for (int i = 0; i < 4; i++) {
				int next_y = y + dct_y[i];
				int next_x = x + dct_x[i];
				if (IsInBound(next_y, next_x) && touched_air[next_y][next_x]) {
					adjacent_air++;
				}
			}
			if (adjacent_air >= 2 || current_cheese[y][x] == 0) {
				next_cheese[y][x] = 0;
			}
			else {
				next_cheese[y][x] = 1;
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
	// for (int y = 0; y < height; y++) {
	// 	for (int x = 0; x < width; x++) {
			
	// 	}
	// }
	while (cin >> height >> width) {
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				cin >> current_cheese[y][x];
				next_cheese[y][x] = current_cheese[y][x];
			}
		}
		int melt_time = 0;
		while (true) {
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					current_cheese[y][x] = next_cheese[y][x];
				}
			}
			int current_chunk = 0;
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					//cout << current_cheese[y][x] << " ";
					if (current_cheese[y][x] == 1) {
						current_chunk++;
					}
				}
				//cout << "\n";
			}
			//cout << "\n";
			if (current_chunk == 0) {
				cout << melt_time << "\n";
				break;
			}

			memset(touched_air, 0, sizeof(touched_air));
			UpdateTouchedAir(0, 0);
			UpdateNextCheese();
			melt_time++;
		}
		
		
		
		
	}
    

    return 0;
}

