#include <bits/stdc++.h>


using namespace std;

int num_vertice;
int num_edge;
const int INF = 987654321;
vector<pair<int, int> > graph[20001];

vector<int> dijkstra(int src) {
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
		for (int i = 0; i < 20001; i++) {
			graph[i].clear();
		}
		int start_point;
		int from;
		int to;
		int weight;
		cin >> start_point;
		--start_point;
		for (int i = 0; i < num_edge; i++) {
			cin >> from >> to >> weight;
			--from;
			--to;
			graph[from].push_back(make_pair(weight, to));
		}
		vector<int> distance_from_src = dijkstra(start_point);
		for (int i = 0; i < num_vertice; i++) {
			if (distance_from_src[i] == INF) {
				cout << "INF\n";
			}
			else {
				cout << distance_from_src[i] << "\n";
			}
		}
	}
    

    return 0;
}

