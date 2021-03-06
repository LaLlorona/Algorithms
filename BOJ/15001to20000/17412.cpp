#include <bits/stdc++.h>

using namespace std;

const int MAX = 401;
int num_city, num_path;
int capacity[401][401];
int flow[401][401];
vector<int> graph[401];

const int INF = 987654321;

int FoldFulkerson (int source, int sink) {
	int total_flow = 0;
	while (true) {
		vector<int> parent(num_city + 1, -1);
		queue<int> bfs_queue;
		parent[source] = source;
		bfs_queue.push(source);
		while (!(bfs_queue.empty() || parent[sink] != -1)) {
			int here = bfs_queue.front();
			bfs_queue.pop();
			
			for (int i = 0; i < graph[here].size(); i++) {
				int there = graph[here][i];
				if (parent[there] == -1 && capacity[here][there] - flow[here][there] > 0) {
					parent[there] = here;
					bfs_queue.push(there);
				}
			}
		}
		if (parent[sink] == -1) {
			break;
		}
		int current_flow = INF;
		for (int i = sink; i != source; i = parent[i]) {
			current_flow = min(current_flow, capacity[parent[i]][i] - flow[parent[i]][i]);
		}
		for (int i = sink; i != source; i = parent[i]) {
			flow[parent[i]][i] += current_flow;
			flow[i][parent[i]] -= current_flow;
		}
		total_flow += current_flow;
		
	}
	return total_flow;
}


int main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	while (cin >> num_city >> num_path) {
		memset(flow, 0, sizeof(flow));
		memset(capacity, 0 , sizeof(capacity));
		for (int i = 0; i <= MAX; i++) {
			graph[i].clear();
		}
		for (int i = 0; i < num_path; i++) {
			int from, to;
			cin >> from >> to;
			capacity[from][to] = 1;
			graph[from].push_back(to);
			graph[to].push_back(from);
		}
		cout << FoldFulkerson(1, 2) << "\n";
	}
	
	
	
	return 0;
}



