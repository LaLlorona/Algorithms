#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> pii;

const int INF = 987654321;
const int MAX = 1000;
int height, width;

int dct_y[4] = {0, -1, 0, 1};
int dct_x[4] = {-1, 0, 1, 0};

int fire_board[MAX][MAX];// INF: unreached empty space. INF + 1: wall. integer : time to reach specific place
int human_board[MAX][MAX];
int human_begin_y, human_begin_x;

queue<pii> bfs_queue;

bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 & x < width);
}

void SpreadFire() {
	while (!bfs_queue.empty()) {
		int here_y = bfs_queue.front().first;
		int here_x = bfs_queue.front().second;
		int here_time = fire_board[here_y][here_x];
		bfs_queue.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = here_y + dct_y[i];
			int next_x = here_x + dct_x[i];
			if (IsInBound(next_y, next_x) && fire_board[next_y][next_x] == INF) {
				fire_board[next_y][next_x] = here_time + 1;
				bfs_queue.push({next_y, next_x});
			}
		}
	}
}

void SpreadHuman() {
	bfs_queue.push({human_begin_y, human_begin_x});
	while (!bfs_queue.empty()) {
		int here_y = bfs_queue.front().first;
		int here_x = bfs_queue.front().second;
		int here_time = human_board[here_y][here_x];
		bfs_queue.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = here_y + dct_y[i];
			int next_x = here_x + dct_x[i];
			if (IsInBound(next_y, next_x) && human_board[next_y][next_x] == INF && fire_board[next_y][next_x] > here_time + 1) {
				human_board[next_y][next_x] = here_time + 1;
				bfs_queue.push({next_y, next_x});
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
	// }
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		cin >> width >> height;
		
		for (int y = 0; y < height; y++) {
			string one_line;
			cin >> one_line;
			for (int x = 0; x < width; x++) {
				if (one_line[x] == '#') { // wall
					fire_board[y][x] = INF + 1;
					human_board[y][x] = INF + 1;
				}
				else if (one_line[x] == '*') {//fire
					fire_board[y][x] = 0;
					human_board[y][x] = INF + 1;
					bfs_queue.push({y, x});
				}
				else if (one_line[x] == '@') {//begin_position
					fire_board[y][x] = INF;
					human_board[y][x] = 0;
					human_begin_y = y;
					human_begin_x = x;
					
				}
				else {//empty space
					fire_board[y][x] = INF;
					human_board[y][x] = INF;
				}
			}
		}
		// for (int y = 0; y < height; y++) {
		// 	for (int x = 0; x < width; x++) {
		// 		cout << fire_board[y][x] << " ";
		// 	}
		// 	cout << "\n";
		// }
		// cout << "\n";
		// for (int y = 0; y < height; y++) {
		// 	for (int x = 0; x < width; x++) {
		// 		cout << human_board[y][x] << " ";
		// 	}
		// 	cout << "\n";
		// }
		SpreadFire();
		SpreadHuman();
		// for (int y = 0; y < height; y++) {
		// 	for (int x = 0; x < width; x++) {
		// 		cout << fire_board[y][x] << " ";
		// 	}
		// 	cout << "\n";
		// }
		// cout << "\n";
		// for (int y = 0; y < height; y++) {
		// 	for (int x = 0; x < width; x++) {
		// 		cout << human_board[y][x] << " ";
		// 	}
		// 	cout << "\n";
		// }
		
		int min_cand = INF + 1;
		for (int x = 0; x < width; x++) {
			min_cand = min(min_cand, human_board[0][x]);
			min_cand = min(min_cand, human_board[height - 1][x]);
		}
		for (int y = 0; y < height; y++) {
			min_cand = min(min_cand, human_board[y][0]);
			min_cand = min(min_cand, human_board[y][width - 1]);
		}
		if (min_cand >= INF) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			cout << min_cand + 1 << "\n";
		}
		
	}
    

    return 0;
}

