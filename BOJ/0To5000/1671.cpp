#include <bits/stdc++.h>


using namespace std;


const int MAX_V = 102;
const int INF = 987654321;
int capacity[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];

int shark_size[50];
int shark_speed[50];
int shark_intel[50];

int num_shark;



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
	
	
	int graph_source = 0;
	int graph_sink = 101;
	int eaten_bias = 50;
	while (cin >> num_shark) {
		memset(capacity, 0, sizeof(capacity));
		memset(flow, 0, sizeof(flow));
		for (int i = 0; i < num_shark; i++) {
			cin >> shark_size[i] >> shark_speed[i] >> shark_intel[i];
		}
		for (int i = 0; i < num_shark; i++) {
			for (int j = 0; j < num_shark; j++) {
				if (i != j) {
					int flag = 0;
					if (shark_size[i] == shark_size[j]) {
						flag++;
					}
					if (shark_speed[i] == shark_speed[j]) {
						flag++;
					}
					if (shark_intel[i] == shark_intel[j]) {
						flag++;
					}
					
					if (flag == 3 && i < j) {
						capacity[i + 1][j + 1 + eaten_bias] = 1;
					}
					else if (flag != 3 && shark_size[i] >= shark_size[j] && shark_speed[i] >= shark_speed[j] && shark_intel[i] >= shark_intel[j]) {
						capacity[i + 1][j + 1 + eaten_bias] = 1;
					}
					
				}
			}
		}
		for (int i = 1; i <= num_shark; i++) {
			capacity[graph_source][i] = 2;
		}
		for (int i = 51; i <= num_shark + eaten_bias; i++) {
			capacity[i][graph_sink] = 1;
		}
		
		// for (int i = 0; i < MAX_V; i++) {
		// 	for (int j = 0; j < MAX_V; j++) {
		// 		if (capacity[i][j] > 0) {
		// 			cout << i << "," << j << " ";
		// 		}
		// 	}
		// }
		
		cout << num_shark - FordFulkerson(graph_source, graph_sink, capacity) << "\n";
		
		
	}
    

    return 0;
}

