#include <bits/stdc++.h>


using namespace std;

int n;
const int INF = 987654321;
int board[126][126];
vector<pair<int, int> > graph[126 * 126];
int dct_y[4] = {-1, 0, 0, 1};
int dct_x[4] = {0, -1, 1, 0};

bool IsInBound(int y, int x) {
	return (y >= 0 && y < n && x >= 0 && x < n);
}
void MakeGraph() {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			for (int i = 0; i < 4; i++) {
				int next_y = y + dct_y[i];
				int next_x = x + dct_x[i];
				if (IsInBound(next_y, next_x)) {
					graph[y * n + x].push_back({board[next_y][next_x], next_y * n + next_x });
				}
			}
		}
	}
}

vector<int> Dijkstra(int src) {
	vector<int> dist(n * n, INF);
	dist[src] = board[0][0]; 
	priority_queue<pair<int, int>, vector<pair<int ,int > >, greater<pair<int ,int > > > pq;
	pq.push(make_pair(board[0][0], src));
	while(!pq.empty()) {
		int closest = pq.top().second;
		int weight_closest = pq.top().first;
		pq.pop();
		if (weight_closest > dist[closest]) {
			continue;
		}
		for (int i = 0; i < graph[closest].size(); i++) {
			int next = graph[closest][i].second;
			int weight_next = graph[closest][i].first;
			if (dist[next] > dist[closest] + weight_next) {
				dist[next] = dist[closest] + weight_next;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
	return dist;
}

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	int problem_count = 1;
	while (cin >> n) {
		for (int i = 0 ; i < 126 * 126; i++) {
			graph[i].clear();
		}
		
		if (n == 0) {
			break;
		}
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cin >> board[y][x];
			}
		}
		MakeGraph();
		vector<int> distance_from_begin = Dijkstra(0);
		// for (int y = 0; y < n; y++) {
		// 	for (int x = 0; x < n; x++) {
		// 		cout << distance_from_begin[y * n + x] << " ";
		// 	}
		// 	cout << "\n";
		// }
		cout << "Problem " << problem_count << ": ";
		cout << distance_from_begin[n * n - 1] << "\n";
		++problem_count;
		
		
	}
    

    return 0;
}

