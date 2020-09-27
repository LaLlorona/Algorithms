#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> pii;

const int INF = 987654321;

int map_size;
int is_land[100][100]; // 0 : water, 1: land. does not change
int land_type[100][100]; // 0 : water, 1: not reached land 2: current land. keep change
int current_time_reach[100][100];

bool is_this_island_checked[100][100];

int dct_y[4] = {0, -1, 0, 1};
int dct_x[4] = {-1, 0, 1, 0};
queue<pii> bfs_queue;


bool IsInBound(int y, int x) {
	return (y >= 0 && y < map_size && x >= 0 && x < map_size);
}

void Dfs(int y, int x) {
	land_type[y][x] = 2;
	bfs_queue.push({y, x});
	current_time_reach[y][x] = 0;
	is_this_island_checked[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int next_y = y + dct_y[i];
		int next_x = x + dct_x[i];
		if (IsInBound(next_y, next_x) && land_type[next_y][next_x] == 1) {
			Dfs(next_y, next_x);
		}
	}
	
}
int MinTimeReach(int current_y, int current_x) {
	memset(current_time_reach, -1, sizeof(current_time_reach));
	for (int y = 0; y < map_size; y++) {
		for (int x = 0; x < map_size; x++) {
			land_type[y][x] = is_land[y][x];
		}
	}
	while (!bfs_queue.empty()) {
		bfs_queue.pop();
	}
	Dfs(current_y, current_x);
	
	while (!bfs_queue.empty()) {
		int here_y = bfs_queue.front().first;
		int here_x = bfs_queue.front().second;
		int current_bridge_len = current_time_reach[here_y][here_x];
		bfs_queue.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = here_y + dct_y[i];
			int next_x = here_x + dct_x[i];
			if (IsInBound(next_y, next_x) && land_type[next_y][next_x] != 2) {
				if (land_type[next_y][next_x] == 1) {//reached another island
					return current_bridge_len;
				}
				else if (land_type[next_y][next_x] == 0) { // need to expand
					land_type[next_y][next_x] = 2;
					current_time_reach[next_y][next_x] = current_bridge_len + 1;
					bfs_queue.push({next_y, next_x});
				}
			}
		}
	}
	return INF;
}



int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> map_size) {
		memset(is_this_island_checked, 0, sizeof(is_this_island_checked));
		for (int y = 0; y < map_size; y++) {
			for (int x = 0; x < map_size; x++) {
				cin >> is_land[y][x];
				land_type[y][x] = is_land[y][x];
			}
		}
		int min_cand = INF;
		for (int y = 0; y < map_size; y++) {
			for (int x = 0; x < map_size; x++) {
				if (!is_this_island_checked[y][x] && is_land[y][x]) {
					int result = MinTimeReach(y, x);
					min_cand = min(min_cand, result);
					// cout << y << " " << x << " " << result << "\n";
					// for (int i = 0; i < map_size; i++) {
					// 	for (int j = 0; j < map_size; j++) {
					// 		if (current_time_reach[i][j] == -1) {
					// 			cout << current_time_reach[i][j] << " ";
					// 		}
					// 		else {
					// 			cout << current_time_reach[i][j] << "  ";
					// 		}
					// 	}
					// 	cout << "\n";
					// }
					// cout << "\n";
				}
			}
		}
		cout << min_cand << "\n";
	}
	
	
    

    return 0;
}

