#include <bits/stdc++.h>


using namespace std;

int num_vertice;
int num_edge;
const int INF = 666666666;
vector<pair<int, int> > graph[801];

vector<int> Dijkstra(int src) {
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
		for (int i = 0; i < 801; i++) {
			graph[i].clear();
		}
		
		int from;
		int to;
		int weight;
		
		for (int i = 0; i < num_edge; i++) {
			cin >> from >> to >> weight;
			--from;
			--to;
			graph[from].push_back({weight, to});
			graph[to].push_back({weight, from});
		}
		int must_pass1;
		int must_pass2;
		cin >> must_pass1 >> must_pass2;
		--must_pass1;
		--must_pass2;
		vector<int> from_begin = Dijkstra(0);
		vector<int> from_must_pass1 = Dijkstra(must_pass1);
		vector<int> from_must_pass2 = Dijkstra(must_pass2);
		int min_cand = INF;
		min_cand = min(from_begin[must_pass1] + from_must_pass1[must_pass2] + from_must_pass2[num_vertice - 1],
					  from_begin[must_pass2] + from_must_pass2[must_pass1] + from_must_pass1[num_vertice - 1]);
		if (min_cand >= INF) {
			cout << -1 << "\n";
		}
		else {
			cout << min_cand << "\n";
		}
		
		
		
		
	}
    

    return 0;
}

