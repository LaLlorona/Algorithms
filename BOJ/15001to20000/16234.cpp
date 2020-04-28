#include <bits/stdc++.h>


using namespace std;

int N, L, R;

bool visited[51][51];
int population[51][51];
bool changed;

int direct_x[4] = {0, -1, 1, 0};
int direct_y[4] = {-1, 0, 0, 1};

bool IsInBound(int y, int x) {
	return (y >= 0 && y < N && x >= 0 && x < N);
}

void BFS(int start_y, int start_x) {
	queue<pair<int, int> > bfs_queue;
	vector<pair<int, int> > connected;
	
	visited[start_y][start_x] = true;
	int connected_population = population[start_y][start_x];
	int connected_village = 1;
	bfs_queue.push(make_pair(start_y, start_x));
	connected.push_back(make_pair(start_y, start_x));
		
	while(!bfs_queue.empty()) {
		int current_y = bfs_queue.front().first;
		int current_x = bfs_queue.front().second;
		bfs_queue.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = current_y + direct_y[i];
			int next_x = current_x + direct_x[i];
			if (IsInBound(next_y, next_x) && !visited[next_y][next_x]) {
				int difference = abs(population[current_y][current_x] - population[next_y][next_x]);
				if (difference <= R && difference >= L) {
					changed = true;
					visited[next_y][next_x] = true;
					connected_population += population[next_y][next_x];
					connected_village++;
					bfs_queue.push(make_pair(next_y, next_x));
					connected.push_back(make_pair(next_y, next_x));
				}
			}
		}
	}
	for (int i = 0; i < connected.size(); i++) {
		population[connected[i].first][connected[i].second] = connected_population / connected_village;
	}
	
}
int Solve() {
	int num_changed = 0;
	changed = true;
	while (changed) {
		changed = false;
		memset(visited, 0, sizeof(visited));
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (!visited[y][x]) {
					BFS(y, x);
				}
			}
		}
		if (changed) {
			num_changed++;
			// for (int y = 0; y < N; y++) {
			// 	for (int x = 0; x < N; x++) {
			// 		cout << population[y][x] << " ";
			// 	}
			// 	cout << "\n";
			// }
		}
		
	}
	return num_changed;
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
//     std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//     std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	while (cin >> N >> L >> R) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cin >> population[y][x];
			}
		}
		cout << Solve() << "\n";
	}
    

    return 0;
}

