#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> pii; 
int num_country, num_ticket;
vector<pii> graph[1001];
bool visited[1001];

int Prim() {
	int min_cost = 0;
	int begin_point = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	
	// for (int i = 0; i < graph[begin_point].size(); i++) {
	// 	pq.push(graph[begin_point][i]);
	// }
	pq.push({0, begin_point});
	while (!pq.empty()) {
		int here = pq.top().second;
		int here_cost = pq.top().first;
		
		pq.pop();
		if (visited[here]) {
			continue;
		}
		min_cost += here_cost;
		// cout << here << " ";
		visited[here] = true;
		for (int i = 0 ; i < graph[here].size(); i++) {
			int there = graph[here][i].second;
			int there_cost = graph[here][i].first;
			
			pq.push({there_cost, there});
		}
	}
	return min_cost;
	
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
		cin >> num_country >> num_ticket;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < 1001; i++) {
			graph[i].clear();
		}
		for (int i = 0; i < num_ticket; i++) {
			int from;
			int to;
			cin >> from >> to;
			from--;
			to--;
			graph[from].push_back({1, to});
			graph[to].push_back({1, from});
		}
		cout << Prim() << "\n";
	}
    

    return 0;
}

