#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> pii;

int num_vertice, num_edge;
vector<pii> graph[1001]; //graph [i].first : weight between adjacent vertex, graph[i].second: numbering of adjacent vertex
bool visited[1001];

int Prim() {
	memset(visited, 0, sizeof(visited));
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	int total_weight = 0;
	int visited_num = 0;
	pq.push({0, 1});
	while (!pq.empty() && visited_num != num_vertice) {
		int here = pq.top().second;
		int current_weight = pq.top().first;
		pq.pop();
		if (visited[here]) {
			continue;
		}
		//cout << here << " ";
		visited[here] = true;
		total_weight += current_weight;
		visited_num++;
		for (int i = 0 ; i < graph[here].size(); i++) {
			int there = graph[here][i].second;
			int weight_to = graph[here][i].first;
			if (!visited[there]) {
				pq.push({weight_to, there});
			}
		}
	}
	return total_weight;
	
}



int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
//     std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//     std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_vertice >> num_edge) {
		for (int i = 0; i < num_edge; i++) {
			int from, to, weight;
			cin >> from >> to >> weight;
			graph[from].push_back({weight, to});
			graph[to].push_back({weight, from});
		}
		cout << Prim() << "\n";
	}
    

    return 0;
}

