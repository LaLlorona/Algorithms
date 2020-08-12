#include <bits/stdc++.h>


using namespace std;


const int MAX = 302;
const int INF = 987654321;
int capacity[MAX][MAX];
int flow[MAX][MAX];
vector<int> graph[MAX];
int num_people, num_food, food_limit;


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

void AddEdge(int from, int to, int amount) {
	capacity[from][to] = amount;
	graph[from].push_back(to);
	graph[to].push_back(from);
}

int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
// 	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
// 	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_people >> food_limit >> num_food) {
		memset(capacity, 0, sizeof(capacity));
		memset(flow, 0, sizeof(flow));
		for (int i = 0; i < MAX; i++) {
			graph[i].clear();
		}
		for (int i = 1; i <= num_food; i++) {
			int num;
			cin >> num;
			AddEdge(i + 200, 301, num);
		}
		for (int i = 1; i <= num_people; i++) {
			AddEdge(0, i, food_limit);
			int possible_bring;
			cin >> possible_bring;
			for (int j = 0; j < possible_bring; j++) {
				int food;
				cin >> food;
				AddEdge(i, food + 200, 1);
			}
		}
		cout << FoldFulkerson(0, 301) << "\n";
		
		
		
		
	}
    

    return 0;
}

