#include <bits/stdc++.h>


using namespace std;

int num_vertex, num_edge, a, b, c;
const int INF = 987654321;
vector<int> graph[200001];

void BFS(int start, vector<int> &distance_from) {
	queue<int> bfs_queue;
	bfs_queue.push(start);
	distance_from[start] = 0;
	while (!bfs_queue.empty()) {
		int from = bfs_queue.front();
		bfs_queue.pop();
		for (int i = 0; i < graph[from].size(); i++) {
			int to = graph[from][i];
			if (distance_from[to] == INF) {
				distance_from[to] = distance_from[from] + 1;
				bfs_queue.push(to);
			}
		}
	}
}

long long Solve() {
	for (int i = 0; i < 200001; i++) {
		graph[i].clear();
	}
	cin >> num_vertex >> num_edge >> a >> b >> c;
	a--;
	b--;
	c--;
	vector<int> distance_from_a(num_vertex, INF);
	vector<int> distance_from_b(num_vertex, INF);
	vector<int> distance_from_c(num_vertex, INF);
	
	vector<long long> possible_distances(num_edge + 1);
	
	for (int i = 1; i <= num_edge; i++) {
		cin >> possible_distances[i];
	}
	
	for (int i = 0; i < num_edge; i++) {
		int here;
		int to;
		cin >> here >> to;
		--here;
		--to;
		graph[here].push_back(to);
		graph[to].push_back(here);
	}
	
	sort(possible_distances.begin(), possible_distances.end());
	for (int i = 0; i < possible_distances.size(); i++) {
		possible_distances[i + 1] += possible_distances[i];
	}

	BFS(a, distance_from_a); 
	BFS(b, distance_from_b);
	BFS(c, distance_from_c);
	
	long long  min_cand = 1e11;
	
	for (int i = 0; i < num_vertex; i++) {
		long long total_length = distance_from_a[i] + distance_from_b[i] + distance_from_c[i];
		if (total_length > num_edge) {
			continue;
		}
		min_cand = min(min_cand, possible_distances[total_length] + possible_distances[distance_from_b[i]]);
		
	}
	return min_cand;
	
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
	cin >> num_testcase;
	while (num_testcase--) {
		cout << Solve() << "\n";
	}
    

    return 0;
}

