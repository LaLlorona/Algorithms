#include <bits/stdc++.h>


using namespace std;

int num_vertice;
int num_edge;
int start_point;
int end_point;
const int INF = 987654321;
vector<pair<int, int> > graph[1001];
int parent[1001];


vector<int> Dijkstra(int src) {
	vector<int> dist(num_vertice, INF);
	dist[src] = 0; 
	priority_queue<pair<int, int>, vector<pair<int ,int > >, greater<pair<int ,int > > > pq;
	pq.push({0, src});
	while(!pq.empty()) {
		int closest = pq.top().second;
		int weight_closest = pq.top().first;
		pq.pop();
		
		if (weight_closest > dist[closest]) {
			continue;
		}
		for (int i = 0; i < graph[closest].size(); i++) {
			int next = graph[closest][i].second;
			int distance_next = graph[closest][i].first + dist[closest];
			if (graph[closest][i].first == -1) {
				continue;
			}
			if (dist[next] > distance_next) {
				dist[next] = distance_next;
				pq.push({distance_next, next});
				parent[next] = closest;
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
	while (cin >> num_vertice >> num_edge) {
		
		
		
		for (int i = 0; i < 1001; i++) {
			graph[i].clear();
		}
		memset(parent, -1, sizeof(parent));
		for (int i = 0; i < num_edge; i++) {
			int from;
			int to;
			int weight;
			cin >> from >> to >> weight;
			from--;
			to--;
			graph[from].push_back({weight, to});
			graph[to].push_back({weight, from});
		}
		
		Dijkstra(0);
		cout << num_vertice - 1 << "\n";
		for (int i = 1; i < num_vertice; i++) {
			cout << i + 1 << " " << parent[i] + 1 << "\n";
		}
		
		
	}
    

    return 0;
}

