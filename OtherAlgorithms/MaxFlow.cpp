#include <bits/stdc++.h>

using namespace std;

const int MAX = 801;
int num_city, num_path;
int capacity[MAX][MAX];
int flow[MAX][MAX];
vector<int> graph[MAX];

const int INF = 987654321;

int FoldFulkerson (int source, int sink) {
	int total_flow = 0;
	while (true) {
		vector<int> parent(MAX + 1, -1);
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

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	

    

    return 0;
}

