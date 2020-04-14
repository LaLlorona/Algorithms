#include <bits/stdc++.h>



using namespace std;

const int INF = 987654321;
int maze[100][100];
int min_break = INF;
bool visited[100][100];
int width, height;

int direct_y[4] = {-1, 0, 0, 1};
int direct_x[4] = {0, -1, 1, 0};

bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 && x < width);
}

void UpdateMinBreak() {
	int break_cand = 0;
	for (int x = 0; x < width; x++) {
		if (maze[0][x] == 1) {
			break_cand++;
		}
	}
	for (int y = 0; y < height; y++) {
		if (maze[y][width - 1] == 1) {
			break_cand++;
		}
	}
	min_break = break_cand;
}

void DFS(int y, int x, int num_break) {
	if (y == height - 1 && x == width - 1) { 
		min_break = min(min_break, num_break);
	}
	else {
		if (num_break < min_break) {
			for (int i = 0; i < 4; i++) {
				int next_y = y + direct_y[i];
				int next_x = x + direct_x[i];
				if (IsInBound(next_y, next_x) && !visited[next_y][next_x]) {
					visited[next_y][next_x] = true;
					if (maze[next_y][next_x] == 1) {
						DFS(next_y, next_x, num_break + 1);
					}
					else {
						DFS(next_y, next_x, num_break);
					}
					visited[next_y][next_x] = false;
				}
			}
		}
	}
}

void BFS(int start_y, int start_x) {
	priority_queue< pair<int, pair<int, int> >, vector< pair<int, pair<int, int> > >, greater< pair<int, pair<int, int> > > > pq;
	pq.push(make_pair(0, make_pair(start_y, start_x)));
	visited[start_y][start_x] = true;
	
	bool finished = false;
	while (!pq.empty() && !finished) {
		pair<int, pair<int, int> > to_visit = pq.top();
		pq.pop();
		int num_break = to_visit.first;
		int y = to_visit.second.first;
		int x = to_visit.second.second;
		
		if (y == height - 1 && x == width - 1) {
			finished = true;
			min_break = num_break;
		}
		
		for (int i = 0; i < 4; i++) {
			int next_y = y + direct_y[i];
			int next_x = x + direct_x[i];
			if (IsInBound(next_y, next_x) && !visited[next_y][next_x]) {
				visited[next_y][next_x] = true;
				if (maze[next_y][next_x] == 1) {
					pq.push(make_pair(num_break + 1, make_pair(next_y, next_x)));
				}
				else {
					pq.push(make_pair(num_break, make_pair(next_y, next_x)));
				}
			}
		}
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
	
	while (cin >> width >> height) {
		string one_line;
		memset(visited, 0 ,sizeof(visited));
		min_break = INF;
		for (int y = 0; y < height; y++) {
			cin >> one_line;
			for (int x = 0; x < width; x++) {
				maze[y][x] = one_line[x] - '0';
			}
		}
		//UpdateMinBreak();
		//DFS(0, 0, 0);
		BFS(0, 0);
		cout << min_break << "\n";
	}
    

    return 0;
}

