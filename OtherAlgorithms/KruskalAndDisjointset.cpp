#include <bits/stdc++.h>


using namespace std;
typedef pair<double, int> pdi; 
typedef pair<int, int> pii;
int num_stars, num_connected;
vector<pdi> graph[1001];
vector<pii> connected;
bool visited[1001];
double coordinate[1001][2];
struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n), rank(n ,1) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int find (int u) {
		if (parent[u] == u) {
			return u;
		}
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v) {
		int root_u = find(u);
		int root_v = find(v);
		if (root_v == root_u) {
			return;
		}
		if (rank[root_u] > rank[root_v]) {
			swap(root_u, root_v);
		}
		parent[root_u] = root_v;
		if (rank[root_u] == rank[root_v]) {
			rank[root_v]++;
		}
 	}
};

double Kruskal(vector<pii> &selected, DisjointSet &sets) {
	double total_cost = 0;
	selected.clear();
	vector<pair<double, pii> > edge;
	for (int i = 0; i < num_stars; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int from = i;
			int to = graph[i][j].second;
			double weight = graph[i][j].first;
			edge.push_back({weight, {from, to}});
		}
	}
	sort(edge.begin(), edge.end());
	
	for (int i = 0; i < edge.size(); i++) {
		int from = edge[i].second.first;
		int to = edge[i].second.second;
		double weight = edge[i].first;
		int set_from = sets.find(from);
		int set_to = sets.find(to);
		if (set_from == set_to) {
			continue;
		}
		else {
			selected.push_back({from, to});
			total_cost += weight;
			sets.merge(from, to);
		}
	}
	return total_cost;
}




int main()
{
	cout << fixed;
    cout.precision(2);
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_stars >> num_connected) {
		memset(visited, 0, sizeof(visited));
		connected.clear();
		DisjointSet sets(num_stars);
		vector<pii> min_spanning_tree;
		for (int i = 0; i < 1001; i++) {
			graph[i].clear();
		}
		for (int i = 0; i < num_stars; i++) {
			cin >> coordinate[i][0] >> coordinate[i][1];
		}
		for (int i = 0; i < num_stars; i++) {
			for (int j = 0; j < num_stars; j++) {
				if (i != j) {
					double dist = sqrt(pow(coordinate[i][0] - coordinate[j][0], 2.0) + pow(coordinate[i][1] - coordinate[j][1], 2.0));
					graph[i].push_back({dist, j});
					graph[j].push_back({dist, i});
				}
			}
		}
		for (int i = 0; i < num_connected; i++) {
			int from;
			int to;
			cin >> from >> to;
			from--;
			to--;
			sets.merge(from, to);
		}
		cout << Kruskal(min_spanning_tree, sets) << "\n";
	

	}
    

    return 0;
}

