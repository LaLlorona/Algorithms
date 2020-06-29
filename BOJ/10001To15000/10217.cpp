#include <bits/stdc++.h>


using namespace std;

const int INF = 987654321;
int max_cost;
int num_vertice;
int num_edge;

int time_to_reach[101][10001];
vector<pair<int, pair<int, int> > > graph[101]; // {cost, {time, place}}
void Dijkstra(int src) {
	
	time_to_reach[src][0] = 0;
	
	priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
	pq.push({0, {0, src}});
	
	while(!pq.empty()) {
		int current_cost = pq.top().first;
		int current_time = pq.top().second.first;
		int here = pq.top().second.second;
		pq.pop();
		
		if (current_time > time_to_reach[here][current_cost]) {
			continue;
		}
		
		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i].second.second;
			int next_cost = graph[here][i].first + current_cost;
			int next_time = graph[here][i].second.first + current_time;
			if (next_cost > max_cost) {
				continue;
			}
			if (time_to_reach[next][next_cost] > next_time) {
				for (int i = next_cost; i <= max_cost; i++) {
					if (time_to_reach[next][i] > next_time) {
						time_to_reach[next][i] = next_time;
					}
				}
				pq.push({next_cost, {next_time, next}});
			}
		}
	}
	int fastest = INF;
	for (int i = 0; i <= max_cost; i++) {
		if (time_to_reach[num_vertice - 1][i] != INF) {
			fastest = min(fastest, time_to_reach[num_vertice - 1][i]);
		}
	}
	// for (int i = 0; i < num_vertice; i++) {
	// 	for (int j = 0; j <= max_cost; j++) {
	// 		cout << time_to_reach[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	if (fastest == INF) {
		cout << "Poor KCM\n";
	}
	else {
		cout << fastest << "\n";
	}
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
		cin >> num_vertice >> max_cost >> num_edge;
		for (int i = 0; i < num_vertice; i++) {
			for (int j = 0; j <= max_cost; j++) {
				time_to_reach[i][j] = INF;
			}
		}
		for (int i = 0; i < num_vertice; i++) {
			graph[i].clear();
		}
		for (int i = 0; i < num_edge; i++) {
			int from;
			int to;
			int cost_between;
			int time_between;
			cin >> from >> to >> cost_between >> time_between;
			from--;
			to--;
			graph[from].push_back({cost_between, {time_between, to}});
		}
		Dijkstra(0);
	}
    

    return 0;
}

