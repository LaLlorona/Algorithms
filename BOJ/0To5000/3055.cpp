#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii; // weight, y, x

int dct_y[4] = {0, -1, 0, 1};
int dct_x[4] = {-1, 0, 1, 0};

int water_board[51][51]; //
int animal_board[51][51];
int height, width;
int start_y, start_x, end_y, end_x;

queue<piii> bfs_queue_water;
queue<piii> bfs_queue_animal;

bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 && x < width);
}

void FillBoard() {
	while (!bfs_queue_water.empty()) {
		int current_time = bfs_queue_water.front().first;
		int current_y = bfs_queue_water.front().second.first;
		int current_x = bfs_queue_water.front().second.second;
		bfs_queue_water.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = current_y + dct_y[i];
			int next_x = current_x + dct_x[i];
			if (IsInBound(next_y, next_x) && water_board[next_y][next_x] == -1) {
				water_board[next_y][next_x] = current_time + 1;
				bfs_queue_water.push({current_time + 1,{next_y, next_x}});
			}
		}
	}
	while (!bfs_queue_animal.empty()) {
		int current_time = bfs_queue_animal.front().first;
		int current_y = bfs_queue_animal.front().second.first;
		int current_x = bfs_queue_animal.front().second.second;
		bfs_queue_animal.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = current_y + dct_y[i];
			int next_x = current_x + dct_x[i];
			if (IsInBound(next_y, next_x) && animal_board[next_y][next_x] == -1 && (current_time + 1 < water_board[next_y][next_x] || water_board[next_y][next_x] == -2 || water_board[next_y][next_x] == -1)) {
				animal_board[next_y][next_x] = current_time + 1;
				bfs_queue_animal.push({current_time + 1, {next_y, next_x}});
			}
		}	
	}
	
	if (animal_board[end_y][end_x] != -1) {
		cout << animal_board[end_y][end_x] << "\n";
	}
	else {
		cout << "KAKTUS\n";
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
		while (!bfs_queue_water.empty()) {
			bfs_queue_water.pop();
		}
		while (!bfs_queue_animal.empty()) {
			bfs_queue_animal.pop();
		}
		
		for (int y = 0; y < height; y++) {
			string one_line;
			cin >> one_line;
			for (int x = 0; x < width; x++) {
				if (one_line[x] == '.') { // empty
					water_board[y][x] = -1;
					animal_board[y][x] = -1;
				}
				else if (one_line[x] == '*') { // water source
					water_board[y][x] = 0;
					bfs_queue_water.push({0, {y, x}});
					
					animal_board[y][x] = -2;
					
				}
				else if (one_line[x] == 'X') { // stone
					water_board[y][x] = -2;
					animal_board[y][x] = -2;
					
				}
				else if (one_line[x] == 'D') { // endpoint
					water_board[y][x] = -2;
					animal_board[y][x] = -1;
					
					end_y = y;
					end_x = x;
				}
				else {//'S', start point
					water_board[y][x] = -1;
					animal_board[y][x] = 0;
					bfs_queue_animal.push({0, {y, x}});
				}
			}
		}
		FillBoard();
		// for (int y = 0; y < height; y++) {
		// 	for (int x = 0; x < width; x++) {
		// 		cout << water_board[y][x] << " ";
		// 	}
		// 	cout << "\n";
		// }
		// for (int y = 0; y < height; y++) {
		// 	for (int x = 0; x < width; x++) {
		// 		cout << animal_board[y][x] << " ";
		// 	}
		// 	cout << "\n";
		// }
	}
	
	
    

    return 0;
}

