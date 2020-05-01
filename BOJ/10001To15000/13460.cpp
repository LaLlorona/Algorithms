#include <bits/stdc++.h>


using namespace std;
const int INF = 987654321;

int dct_x[4] = {0, -1, 1, 0};
int dct_y[4] = {-1, 0, 0, 1};
int width, height;
int initial_blue_y, initial_blue_x, initial_red_y, initial_red_x;
int board[11][11];

bool visited[11][11][11][11];
int moves[11][11][11][11];

bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 && x < width);
}

int BFS() {
	queue<pair<pair<int, int>, pair<int, int> > > bfs_queue;
	
	visited[initial_blue_y][initial_blue_x][initial_red_y][initial_red_x] = true;
	moves[initial_blue_y][initial_blue_x][initial_red_y][initial_red_x] = 0;
	bfs_queue.push(make_pair(make_pair(initial_blue_y, initial_blue_x), make_pair(initial_red_y, initial_red_x)));
	
	
	while (!bfs_queue.empty()) {
		bool failed = false;
		
		int current_blue_y = bfs_queue.front().first.first;
		int current_blue_x = bfs_queue.front().first.second;
		int current_red_y = bfs_queue.front().second.first;
		int current_red_x = bfs_queue.front().second.second;
		
		if (moves[current_blue_y][current_blue_x][current_red_y][current_red_x] >= 10) {
			return -1;
		}
		
		bfs_queue.pop();
		for (int i = 0; i < 4; i++) {
			failed = false;
			int next_blue_y = current_blue_y;
			int next_blue_x = current_blue_x;
			int next_red_y = current_red_y;
			int next_red_x = current_red_x;
		
			while (IsInBound(next_blue_y + dct_y[i], next_blue_x + dct_x[i]) && board[next_blue_y + dct_y[i]][next_blue_x + dct_x[i]] != 4) {
				next_blue_y += dct_y[i];
				next_blue_x += dct_x[i];
				if (board[next_blue_y][next_blue_x] == 0) {
					failed = true;
					break;
				}
			}
			if (failed) {
				continue;
			}
			while (IsInBound(next_red_y + dct_y[i], next_red_x + dct_x[i]) && board[next_red_y + dct_y[i]][next_red_x + dct_x[i]] != 4) {
				next_red_y += dct_y[i];
				next_red_x += dct_x[i];
				if (board[next_red_y][next_red_x] == 0) {
					return moves[current_blue_y][current_blue_x][current_red_y][current_red_x] + 1;
				}
			}
			//movement finished. Check whether positions are same
			if (next_blue_y == next_red_y && next_blue_x == next_red_x) {
				if (i == 0) { //up
					if (current_blue_y < current_red_y) { // 초기 위치가 blue 가 위쪽임
						next_red_y++;
					}
					else{
						next_blue_y++;
					}
				}
				if (i == 1) { // left
					if (current_blue_x < current_red_x) {
						next_red_x++;
					}
					else {
						next_blue_x++;
					}
					
				}
				if (i == 2) { // right
					if (current_blue_x < current_red_x) {
						next_blue_x--;
					}
					else {
						next_red_x--;
					}
				}
				if (i == 3) { // down
					if (current_blue_y < current_red_y) {
						next_blue_y--;
					}
					else{
						next_red_y--;
					}
				}
			}
			// cout << "RED : " << next_red_y << "," << next_red_x << " And BLUE " << next_blue_y << "," << next_blue_x << "\n";
			if (moves[next_blue_y][next_blue_x][next_red_y][next_red_x] == INF) {
				moves[next_blue_y][next_blue_x][next_red_y][next_red_x] = moves[current_blue_y][current_blue_x][current_red_y][current_red_x] + 1;
				bfs_queue.push(make_pair(make_pair(next_blue_y, next_blue_x), make_pair(next_red_y, next_red_x)));
				// cout << "RED : " << next_red_y << "," << next_red_x << " And BLUE " << next_blue_y << "," << next_blue_x << "\n";
			}
			
		}
		
		
	}
	return -1;
	
	
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> height >> width) {
		for (int y = 0; y < height; y++) {
			string one_line;
			cin >> one_line; 
			for (int x = 0; x < width; x++) {
				if (one_line[x] == 'O') {
					board[y][x] = 0;
				}
				if (one_line[x] == '.') {
					board[y][x] = 1;
				}
				if (one_line[x] == 'R') {
					board[y][x] = 1;
					initial_red_y = y;
					initial_red_x = x;
				}
				if (one_line[x] == 'B') {
					board[y][x] = 1;
					initial_blue_y = y;
					initial_blue_x = x;
				}
				if (one_line[x] == '#') {
					board[y][x] = 4;
				}
			}
		}
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				for (int k = 0; k < 11; k++) {
					for (int l = 0; l < 11; l++) {
						moves[i][j][k][l] = INF;
					}
				}
			}
		}
		// int answer;
		// cin >> answer;
		// if (answer != BFS()) {
		// 	cout << "failed\n";
		// }
		// else {
		// 	cout << "accepted\n";
		// }
		cout << BFS() << "\n";
	
	}
    

    return 0;
}

