#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> pii;


const int MAX = 100001;
int num_house, num_road;
vector<pii> graph[MAX];
bool visited[MAX];

int Prim() {
	priority_queue<pii, vector<pii>, greater<pii> > adjacent_node;
	int max_weight = -1;
	int total_weight = 0;
	adjacent_node.push({0, 1});
	
	while (!adjacent_node.empty()) {
		int here = adjacent_node.top().second;
		int weight = adjacent_node.top().first;
		adjacent_node.pop();
		if (!visited[here]) {
			visited[here] = true;
			total_weight += weight;
			max_weight = max(max_weight, weight);
			for (int i = 0; i < graph[here].size(); i++) {
				int there = graph[here][i].second;
				int there_weight = graph[here][i].first;
				adjacent_node.push({there_weight, there});
			}
		}
	}
	return total_weight - max_weight;
	
}





int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_house >> num_road) {
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < MAX; i++) {
			graph[i].clear();
		}
		for (int i = 0; i < num_road; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			graph[a].push_back({c, b});
			graph[b].push_back({c, a});
		}
		cout << Prim() << "\n";
	}
    

    return 0;
}

