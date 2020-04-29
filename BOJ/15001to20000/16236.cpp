#include <bits/stdc++.h>


using namespace std;
const int INF = 987654321;
int n;
int current_size;
int current_y, current_x;
int current_ate_fish;
int total_time;
bool visited[21][21];
int fishes[21][21];
int found_time[21][21];

int direct_x[4] = {0, -1, 1, 0};
int direct_y[4] = {-1, 0, 0, 1};

bool IsInBound(int y, int x) {
	return (y >= 0 && y < n && x >= 0 && x < n);
}

bool BFS() {
	queue<pair<int, int> > bfs_queue;
	vector<pair<int, pair<int , int> > > possible_positions; // second, y, x
	
	found_time[current_y][current_x] = 0;
	visited[current_y][current_x] = true;
	int min_cnad_found_time = INF;
	
	bfs_queue.push(make_pair(current_y, current_x));
	
	while (!bfs_queue.empty()) {
		// cout << "graph traverse is running \n";
		int here_y = bfs_queue.front().first;
		int here_x = bfs_queue.front().second;
		
		bfs_queue.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = here_y + direct_y[i];
			int next_x = here_x + direct_x[i];
			if (IsInBound(next_y, next_x) && !visited[next_y][next_x] && fishes[next_y][next_x] <= current_size) {
				if (fishes[next_y][next_x] == current_size) { // 먹지는 못하고 지나갈수만 있을 대
					bfs_queue.push(make_pair(next_y, next_x));
					found_time[next_y][next_x] = found_time[here_y][here_x] + 1;
					visited[next_y][next_x] = true;
				}
				else if (fishes[next_y][next_x] != 0){ // 먹을 수 있고 지나갈 수도 있을 때 
					
					
					bfs_queue.push(make_pair(next_y, next_x));
					found_time[next_y][next_x] = found_time[here_y][here_x] + 1;
					possible_positions.push_back(make_pair(found_time[here_y][here_x], make_pair(next_y, next_x)));
					visited[next_y][next_x] = true;
				}
				else { // 물고기가 없고 지나갈 수만 있을 때 
					bfs_queue.push(make_pair(next_y, next_x));
					found_time[next_y][next_x] = found_time[here_y][here_x] + 1;
					visited[next_y][next_x] = true;
				}
			}
		}
	}
	if (possible_positions.size() >= 1) {
		sort(possible_positions.begin(), possible_positions.end());
		fishes[current_y][current_x] = 0;
		current_y = possible_positions[0].second.first;
		current_x = possible_positions[0].second.second;
		total_time += found_time[current_y][current_x];
		// cout << current_y << "," << current_x << "\n";
		++current_ate_fish;
		if (current_ate_fish == current_size) {
			current_ate_fish = 0;
			++current_size;
		}
		
		fishes[current_y][current_x] = 0;
		return true;
	}
	else{
		return false;
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
	
	while (cin >> n) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cin >> fishes[y][x];
				if (fishes[y][x] == 9) {
					current_y = y;
					current_x = x;
				}
			}
		}
		total_time = 0;
		current_size = 2;
		current_ate_fish = 0;
		while (true) {
			memset(visited, 0, sizeof(visited));
			memset(found_time, 0, sizeof(found_time));
			// cout << "BFS is running \n";
			if (!BFS()) {
				break;
			}
		}
		cout << total_time << "\n";
	}
    

    return 0;
}

