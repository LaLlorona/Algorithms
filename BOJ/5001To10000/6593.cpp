#include <bits/stdc++.h>
//erase this 
// for (int z = 0; z < level; z++) {
// 	for (int y = 0; y < height; y++) {
// 		for (int x = 0; x < width; x++) {
				
// 		}
// 	}
// }

using namespace std;

const int MAX = 30;
const int INF = 987654321;
int height, width, level;

int dct_y[6] = {0, -1, 0, 1, 0, 0};
int dct_x[6] = {-1, 0, 1, 0, 0, 0};
int dct_z[6] = {0, 0, 0, 0, 1, -1};

int board[MAX][MAX][MAX];

int begin_z, begin_y, begin_x, end_z, end_y, end_x;

struct Coordinate {
	int z;
	int y;
	int x;
	Coordinate(int _z, int _y, int _x) {
		z = _z;
		y = _y;
		x = _x;
	}
};

bool IsInBound(int z, int y, int x) {
	return (y >= 0 && y < height && x >= 0 & x < width && z >= 0 && z < level);
}

void FillBoard() {
	queue<Coordinate> bfs_queue;
	bfs_queue.push(Coordinate(begin_z, begin_y, begin_x));
	board[begin_z][begin_y][begin_x] = 0;
	while (!bfs_queue.empty()) {
		int here_z = bfs_queue.front().z;
		int here_y = bfs_queue.front().y;
		int here_x = bfs_queue.front().x;
		bfs_queue.pop();
		for (int i = 0; i < 6; i++) {
			int there_z = here_z + dct_z[i];
			int there_y = here_y + dct_y[i];
			int there_x = here_x + dct_x[i];
			if (IsInBound(there_z, there_y, there_x) && board[there_z][there_y][there_x] == INF) {
				board[there_z][there_y][there_x] = board[here_z][here_y][here_x] + 1;
				bfs_queue.push({there_z, there_y, there_x});
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
	while (cin >> level >> height >> width) {
		if (level == 0 && height == 0 && width == 0) {
			break;
		}
		for (int z = 0; z < level; z++) {
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					char here;
					cin >> here;
					if (here == 'S') {
						begin_z = z;
						begin_y = y;
						begin_x = x;
						board[z][y][x] = INF;
					}
					else if (here == 'E') {
						end_z = z;
						end_y = y;
						end_x = x;
						board[z][y][x] = INF;
					}
					else if (here == '.') {
						board[z][y][x] = INF;
					}
					else {
						board[z][y][x] = INF + 1;
					}
				}
			}
		}
		FillBoard();
		if (board[end_z][end_y][end_x] == INF) {
			cout << "Trapped!\n";
		}
		else {
			cout << "Escaped in " << board[end_z][end_y][end_x] << " minute(s).\n";
		}
	}
    

    return 0;
}

