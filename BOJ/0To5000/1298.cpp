#include <bits/stdc++.h>


using namespace std;

int n;
const int MAX_V = 202;
const int INF = 987654321;
int capacity[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];

int num_people, num_expectation;

int FordFulkerson(int source, int sink, int capacity[MAX_V][MAX_V]) {
	
	int ret = 0;
	memset(flow, 0, sizeof(flow));
	while (true) {
		vector<int> parent(MAX_V, -1);
		queue<int> bfs_queue;
		
		bfs_queue.push(source);
		parent[source] = source;
		
		while (!bfs_queue.empty() && parent[sink] == -1) {
			int v = bfs_queue.front();
			// cout << v;
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
	

	while (cin >> num_people >> num_expectation) {
		memset(capacity, 0, sizeof(capacity));
		memset(flow, 0, sizeof(flow));
		int person, expect;
		for (int i = 0; i < num_expectation; i++) {
			cin >> person >> expect;
			capacity[person][expect + 100] = 1;
		}
		for (int i = 0; i < num_people; i++) {
			capacity[0][i + 1] = 1;
			capacity[i + 101][201] = 1;
		}
		// for (int i = 0; i < 202; i++) {
		// 	for (int j = 0; j < 202; j++) {
		// 		if (capacity[i][j] == 1) {
		// 			cout << i << "," << j << " ";
		// 		}
		// 	}
		// }
		cout << FordFulkerson(0, 201, capacity);
		
		
	}
    

    return 0;
}

