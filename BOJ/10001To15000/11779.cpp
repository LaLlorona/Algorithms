#include <bits/stdc++.h>


using namespace std;

int num_vertice;
int num_edge;
int start_point;
int end_point;
const int INF = 987654321;
vector<pair<int, int> > graph[1000];
vector<pair<int, int> > trace[1000];


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
				
				trace[next].clear();
				trace[next].push_back({distance_next, closest});
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
	
// 	std::ifstream in("in.txt");
// 	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
// 	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	while (cin >> num_vertice >> num_edge) {
		if (num_vertice == 0 && num_edge == 0) {
			break;
		}
	
		
		for (int i = 0; i < 501; i++) {
			graph[i].clear();
			trace[i].clear();
		}
		for (int i = 0; i < num_edge; i++) {
			int from;
			int to;
			int weight;
			cin >> from >> to >> weight;
			from--;
			to--;
			graph[from].push_back({weight, to});
		}
		cin >> start_point >> end_point;
		start_point--;
		end_point--;
		vector<int> distance_from = Dijkstra(start_point);
		
		queue<int> shortest_path;
		vector<int> shortest_path_log;
		shortest_path.push(end_point);
		while(!shortest_path.empty()) {
			int to = shortest_path.front();
			shortest_path.pop();
			shortest_path_log.push_back(to);
			for (int i = 0; i < trace[to].size(); i++) {
				int here = trace[to][i].second;
				for (int j = 0; j < graph[here].size(); j++) {
					if (graph[here][j].second == to) {
						graph[here][j].first = -1;
					}
				}
				shortest_path.push(here);
			}
		}
		cout << distance_from[end_point] << "\n";
		cout << shortest_path_log.size() << "\n";
		reverse(shortest_path_log.begin(), shortest_path_log.end());
		for (int i = 0; i < shortest_path_log.size(); i++) {
			cout << shortest_path_log[i] + 1 << " ";
		}
		
	
	}
    

    return 0;
}

