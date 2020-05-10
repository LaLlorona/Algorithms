#include <bits/stdc++.h>


using namespace std;

int num_vertice;
int num_edge;
int num_destination_cand;
int start_point;
int middle1;
int middle2;
int dest;
bool visited[2001][2001];

const int INF = 987654321;
vector<pair<int, int> > graph[2001];
vector<pair<int, int> > trace[2001];


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
			
			else if (dist[next] == distance_next) {
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
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		for (int i = 0; i < 2001; i++) {
			graph[i].clear();
			trace[i].clear();
		}
		cin >> num_vertice >> num_edge >> num_destination_cand;
		
		cin >> start_point >> middle1 >> middle2;
		--start_point;
		--middle1;
		--middle2;
		
		
		for (int i = 0; i < num_edge; i++) {
			int from;
			int to;
			int weight;
			cin >> from >> to >> weight;
			--from;
			--to;
			graph[from].push_back({weight, to});
			graph[to].push_back({weight, from});
		}
		vector<int> destination_candidates;
		for (int i = 0; i < num_destination_cand; i++) {
			cin >> dest;
			--dest;
			destination_candidates.push_back(dest);
		}
		Dijkstra(start_point);
		
		
		sort(destination_candidates.begin(), destination_candidates.end());
		
		for (int i = 0; i < destination_candidates.size(); i++) {
			
			bool found = false;
			memset(visited, 0 , sizeof(visited));
			
			queue<int> shortest_path;
			shortest_path.push(destination_candidates[i]);
			while(!shortest_path.empty() && !found) {
				int to = shortest_path.front();
				
				shortest_path.pop();
				for (int i = 0; i < trace[to].size(); i++) {
					int here = trace[to][i].second;
					if (visited[here][to]) {
						continue;
					}
					visited[here][to] = true;
					for (int j = 0; j < graph[here].size(); j++) {
						if (graph[here][j].second == to) {
							if ((middle1 == here && middle2 == to) || (middle1 == to && middle2 == here)) {
								found = true;
							}
						}
					}
					shortest_path.push(here);
				}
			}
			if (found) {
				cout << destination_candidates[i] + 1 << " ";
			}
		}
		cout << "\n";
	}
    

    return 0;
}

