#include <bits/stdc++.h>


using namespace std;

const long long INF = 922337203685477580;
long long num_vertex, num_edge;
vector<pair<long long ,long long> > graph[500]; // weight, adjacent vertex
bool visited[500];

void Dfs(long long src) {
	visited[src] = true;
	for (long long i = 0; i < graph[src].size(); i++) {
		long long there = graph[src][i].second;
		if (!visited[there]) {
			Dfs(there);
		}
	}
}

vector<long long> BellmanFord(long long src) {
	vector<long long> upper(num_vertex, INF);
	upper[src] = 0;
	for (long long iter = 0; iter < num_vertex - 1; iter++) {
		for (long long here = 0; here < num_vertex; here++) {
			for (long long i = 0; i < graph[here].size(); i++) {
				long long there = graph[here][i].second;
				long long weight_between = graph[here][i].first;
				if (upper[there] > upper[here] + weight_between) {
					upper[there] = upper[here] + weight_between;
				}
			}
		}
	}
	for (long long here = 0; here < num_vertex; here++) {
		for (long long i = 0; i < graph[here].size(); i++) {
			long long there = graph[here][i].second;
			long long weight_between = graph[here][i].first;
			if (upper[there] > upper[here] + weight_between) { //negative cycle is found
				if (visited[here]) {
					upper.clear();
					return upper;
				}
			}
		}
	}
	return upper;
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
// 	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
// 	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_vertex >> num_edge) {
		for (long long i = 0; i < 500; i++) {
			graph[i].clear();
		}
		memset(visited, 0, sizeof(visited));
		for (long long i = 0; i < num_edge; i++) {
			long long from, to, weight;
			cin >> from >> to >> weight;
			from--;
			to--;
			graph[from].push_back({weight, to});
		}
		Dfs(0);
		vector<long long> distance_from = BellmanFord(0);
		if (distance_from.size() == 0) {
			cout << -1 << "\n";
		}
		else {
			for (long long i = 1; i < distance_from.size(); i++) {
				if (!visited[i]) {
					cout << "-1\n";
				}
				else {
					cout << distance_from[i] << "\n";
				}
			}
		}
		
	}
    

    return 0;
}

