#include <bits/stdc++.h>


using namespace std;

int num_vertice;
int num_edge;
int start_point;
int end_point;
const int INF = 987654321;
vector<pair<int, int> > graph[10001];



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
			if (dist[next] > distance_next) {
				dist[next] = distance_next;
				pq.push({distance_next, next});
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
		
		cin >> num_vertice >> num_edge >> start_point;
		--start_point;
		
		for (int i = 0; i < 10001; i++) {
			graph[i].clear();
		}
		
		for (int i = 0; i < num_edge; i++) {
			int from;
			int to;
			int weight;
			cin >> to >> from >> weight;
			from--;
			to--;
			graph[from].push_back({weight, to});
		}
		vector<int> distance_from = Dijkstra(start_point);
		int max_cand = 0 ;
		int num_affected_pc = 0;
		for (int i = 0; i < distance_from.size(); i++) {
			if (distance_from[i] != INF) {
				max_cand = max(max_cand, distance_from[i]);
				++num_affected_pc;
			} 
		}
		cout << num_affected_pc << " " << max_cand << "\n";
	}
    

    return 0;
}

