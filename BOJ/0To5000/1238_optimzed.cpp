#include <bits/stdc++.h>


using namespace std;

int num_vertice;
int num_edge;
const int INF = 987654321;
vector<pair<int, int> > graph[1001];
vector<pair<int, int> > reverse_graph[1001];

vector<int> dijkstra(vector<pair<int, int> > graph[], int src) {
	vector<int> dist(num_vertice, INF);
	dist[src] = 0; 
	priority_queue<pair<int, int>, vector<pair<int ,int > >, greater<pair<int ,int > > > pq;
	pq.push(make_pair(0, src));
	while(!pq.empty()) {
		int closest = pq.top().second;
		int weight_closest = pq.top().first;
		pq.pop();
		if (weight_closest > dist[closest]) {
			continue;
		}
		for (int i = 0; i < graph[closest].size(); i++) {
			int next = graph[closest][i].second;
			int weight_next = graph[closest][i].first;
			if (dist[next] > dist[closest] + weight_next) {
				dist[next] = dist[closest] + weight_next;
				pq.push(make_pair(dist[next], next));
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
		int party_place;
		int start;
		int from;
		int to;
		int weight;
		cin >> party_place;
		--party_place;
		for (int i = 0; i < num_edge; i++) {
			cin >> from >> to >> weight;
			--from;
			--to;
			graph[from].push_back({weight, to});
			reverse_graph[to].push_back({weight, from});
			
		}
		int max_cand = 0;
		vector<int> distance_from_party = dijkstra(graph, party_place);
		vector<int> distance_to_party = dijkstra(reverse_graph, party_place);
		for (int i = 0; i < num_vertice; i++) {
			max_cand = max(max_cand, distance_to_party[i] + distance_from_party[i]);
		}
		cout << max_cand << "\n";
	}
    

    return 0;
}

