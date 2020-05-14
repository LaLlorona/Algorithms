#include <bits/stdc++.h>


using namespace std;

int n;
const int MAX_V = 402;
const int INF = 987654321;
int capacity[402][402];
int flow[402][402];

int num_cow, num_stable;

int FordFulkerson(int source, int sink) {
	
	int ret = 0;
	memset(flow, 0, sizeof(flow));
	while (true) {
		vector<int> parent(MAX_V, -1);
		queue<int> bfs_queue;
		
		bfs_queue.push(source);
		parent[source] = source;
		
		while (!bfs_queue.empty() && parent[sink] == -1) {
			int v = bfs_queue.front();
			bfs_queue.pop();
			
			for (int i = 0; i < MAX_V; i++) {
				if (capacity[v][i] - flow[v][i] > 0 && parent[i] == -1) {
					bfs_queue.push(i);
					parent[i] = v;
				}
			}
		}
		
		if (parent[sink] == -1) {
			
			break;
		}
		
		int current_vertex = sink;
		int max_flow = INF;
		
		while (current_vertex != source) {
			int parent_current_vertex = parent[current_vertex];
			max_flow = min(max_flow, capacity[parent_current_vertex][current_vertex] - flow[parent_current_vertex][current_vertex]);
			current_vertex = parent_current_vertex;
		}
		
		current_vertex = sink;
		
		while (current_vertex != source) {
			int parent_current_vertex = parent[current_vertex];
			flow[parent_current_vertex][current_vertex] += max_flow;
			flow[current_vertex][parent_current_vertex] -= max_flow;
			current_vertex = parent_current_vertex;
			
		}
		ret += max_flow;
		
		
		
	}
	return ret;
}

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	int num_wanted_stable;
	int wanted_stable;
	while (cin >> num_cow >> num_stable) {
		for (int i = 0; i < num_cow; i++) {
			cin >> num_wanted_stable;
			for (int j = 0; j < num_wanted_stable; j++) {
				cin >> wanted_stable;
				capacity[i + 2][wanted_stable + num_cow + 1] = 1;
			}
			capacity[0][2 + i] = 1;
		}
		for (int i = 0; i < num_stable; i++) {
			capacity[2 + num_cow + i][1] = 1;
		}
		cout << FordFulkerson(0, 1) << "\n";
		
		
	}
    

    return 0;
}

