#include <bits/stdc++.h>


using namespace std;

const int MAX = 2001;
const int MAX_V = 1002;
const int INF = 987654321;
int capacity[1002][1002];
int flow[1002][1002];

int input_nums[50];
int num_input;
bool is_prime[2001];

void Eratosthenes() {
	int square = (int)sqrt(MAX);
	for (int i = 2; i <= square; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= MAX; j += i) {
				is_prime[j] = false;
			}
		}
	}
}

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
	
	memset(is_prime, 1, sizeof(is_prime));
	memset(capacity, 0 ,sizeof(capacity));
	memset(flow, 0, sizeof(flow));
	Eratosthenes();
	
	int source = 0;
	int sink = 1001;
	
	
	while (cin >> num_input) {
		memset(flow, 0, sizeof(flow));
		memset(capacity, 0 , sizeof(capacity));
		for (int i = 0; i < num_input; i++) {
			cin >> input_nums[i];
		}
		for (int i = 0; i < num_input; i++) {
			for (int j = 0; j < num_input; j++) {
				if (is_prime[input_nums[i] + input_nums[j]] && input_nums[i] != input_nums[j]) {
					if (input_nums[i] % 2 == 1) {
						capacity[input_nums[i]][input_nums[j]] = 1;
					}
				}
			}
		}
		
		for (int i = 0; i < num_input; i++) {
			if (input_nums[i] % 2 == 1) {
				capacity[source][input_nums[i]] = 1;
			}
			else {
				capacity[input_nums[i]][sink] = 1;
			}
		}
		// for (int i = 0; i < MAX_V; i++) {
		// 	for (int j = 0; j < MAX_V; j++) {
		// 		if (capacity[i][j] == 1) {
		// 			cout << i << "," << j << " ";
		// 		}
		// 	}
		// }
		int max_flow = FordFulkerson(0, 1001, capacity);
		// cout << max_flow << "\n";
		if (max_flow != num_input / 2) {
			cout << -1 << "\n"; 
			
		}
		// else {
		// 	cout << "found matching!\n";
		// }
		else {
			vector<int> ans(0);
			int smallest = input_nums[0];
			sort(input_nums, input_nums + num_input);
			
			int changed_capacity[MAX_V][MAX_V];

			for (int i = 0; i < num_input; i++) {
				if (is_prime[smallest + input_nums[i]] && smallest != input_nums[i]) {

					memset(flow, 0, sizeof(flow));
					for (int y = 0; y < MAX_V; y++) {
						for (int x = 0; x < MAX_V; x++) {
							changed_capacity[y][x] = capacity[y][x];
						}
					}
					for (int j = 0; j < MAX_V; j++) {
						changed_capacity[j][smallest] = 0;
						changed_capacity[smallest][j] = 0;
						changed_capacity[j][input_nums[i]] = 0;
						changed_capacity[input_nums[i]][j] = 0;
					}
					int updated_flow = FordFulkerson(0, 1001, changed_capacity);
					if (updated_flow == num_input / 2 - 1) {
						ans.push_back(input_nums[i]);
					}

				}
			}
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i] << " ";
			}
			cout << "\n";
			}
		
	} 
    

    return 0;
}

