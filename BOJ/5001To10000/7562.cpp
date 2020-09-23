#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> pii;

int board_size;
int night_move_y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int night_move_x[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int num_move[301][301]; //initial value : -1

int from_y, from_x, to_y, to_x;

bool IsInBound(int y, int x) {
	return (y >= 0 && y < board_size && x >= 0 && x < board_size);
}
int FindMinMove() {
	queue<pii> bfs_queue;
	num_move[from_y][from_x] = 0;
	bfs_queue.push({from_y, from_x});
	
	while (!bfs_queue.empty()) {
		int current_y = bfs_queue.front().first;
		int current_x = bfs_queue.front().second;
		bfs_queue.pop();
		for (int i = 0; i < 8; i++) {
			int next_y = current_y + night_move_y[i];
			int next_x = current_x + night_move_x[i];
			if (IsInBound(next_y, next_x) && num_move[next_y][next_x] == -1) {
				num_move[next_y][next_x] = num_move[current_y][current_x] + 1;
				bfs_queue.push({next_y, next_x});
			}
		}
		if (num_move[to_y][to_x] != -1) {
			return num_move[to_y][to_x];
		}
	}
	return 987654321;
	
}


int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		memset(num_move, -1, sizeof(num_move));
		cin >> board_size >> from_y >> from_x >> to_y >> to_x;
		cout << FindMinMove() << "\n";
	}
    

    return 0;
}

