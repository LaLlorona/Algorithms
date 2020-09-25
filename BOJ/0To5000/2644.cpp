#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> pii;
const int INF = 987654321;
vector<pii> graph[101];
int num_people;
int num_relation;

void Dijistra(int start, vector<int>& final_dist) {
	for (int i = 0; i < final_dist.size(); i++) {
		final_dist[i] = INF;
	}
	
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	final_dist[start] = 0;
	pq.push({0, start});
	while (!pq.empty()) {
		int here = pq.top().second;
		int dist_here = pq.top().first;
		pq.pop();
		//cout << here << " ";
		if (final_dist[here] < dist_here) {
			continue;
		}
		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i].second;
			int dist_there = graph[here][i].first + dist_here;
			if (dist_there < final_dist[there]) {
				final_dist[there] = dist_there;
				pq.push({dist_there, there});
			}
		}
	}
}



int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	while (cin >> num_people) {
		int start, end;
		cin >> start >> end;
		cin >> num_relation;
		for (int i = 0; i < num_relation; i++) {
			int parent, child;
			cin >> parent >> child;
			graph[parent].push_back({1, child});
			graph[child].push_back({1, parent});
		}
		vector<int> final_dist(num_people + 1);
		Dijistra(start, final_dist);
		if (final_dist[end] == INF) {
			cout << "-1\n";
		}
		else {
			cout << final_dist[end] << "\n";
		}
		
	}
    

    return 0;
}

