#include <bits/stdc++.h>


using namespace std;
typedef pair<int, pair<int, int> > piii;

const int MAX = 200;
const int INF = 987654321;
int height, width;
int max_horse_jump;

int dct_y[4] = {0, -1, 0, 1};
int dct_x[4] = {-1, 0, 1, 0};
int horse_y[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int horse_x[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int board[31][MAX][MAX];

bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 & x < width);
}

void FillBoard() {
	queue<piii> bfs_queue;
	bfs_queue.push({0, {0, 0}});
	board[0][0][0] = 0;
	while (!bfs_queue.empty()) {
		int num_used = bfs_queue.front().first;
		int here_y = bfs_queue.front().second.first;
		int here_x = bfs_queue.front().second.second;
		bfs_queue.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = here_y + dct_y[i];
			int next_x = here_x + dct_x[i];
			if (IsInBound(next_y, next_x) && board[num_used][next_y][next_x] == INF) {
				board[num_used][next_y][next_x] = board[num_used][here_y][here_x] + 1;
				bfs_queue.push({num_used, {next_y, next_x}});
			}
		}
		for (int i = 0; i < 8; i++) {
			int next_y = here_y + horse_y[i];
			int next_x = here_x + horse_x[i];
			if (IsInBound(next_y, next_x) && num_used + 1 <= max_horse_jump && board[num_used + 1][next_y][next_x] == INF) {
				board[num_used + 1][next_y][next_x] = board[num_used][here_y][here_x] + 1;
				bfs_queue.push({num_used + 1, {next_y, next_x}});
			}
			
		}
	}
}





int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
// 	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
// 	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> max_horse_jump >> width >> height) {
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				int here;
				cin >> here;
				if (here == 0) {
					for (int i = 0; i < 31; i++) {
						board[i][y][x] = INF;
					}
					
				}
				else if (here == 1) {
					for (int i = 0; i < 31; i++) {
						board[i][y][x] = INF + 1;
					}
				}
			}
		}
		FillBoard();
		int min_cand = INF;
		for (int i = 0; i < 31; i++) {
			min_cand = min(min_cand, board[i][height - 1][width - 1]);
		}
		if (min_cand == INF) {
			cout << "-1\n";
		}
		else {
			cout << min_cand << "\n";
		}
		
	}
    

    return 0;
}

