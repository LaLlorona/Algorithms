#include <bits/stdc++.h>


using namespace std;

int num_players, num_match;
const int MAX = 50001;
set<int> graph[MAX];
set<int> roots;
int num_pointed[MAX];

struct DisjointSet {
	vector<int> parent, rank, elements;
	DisjointSet(int n) : parent(n), rank(n ,1), elements(n, 1) {
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
	int find_num(int u) {
		if (parent[u] == u) {
			return elements[u];
		}
		
		return elements[u] = find_num(parent[u]);
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
		int elements_in_first_tree = elements[root_u];
		int elements_in_second_tree = elements[root_v];
		elements[root_u] = elements_in_first_tree + elements_in_second_tree;
		elements[root_v] = elements[root_u];
		parent[root_u] = root_v;
		if (rank[root_u] == rank[root_v]) {
			rank[root_v]++;
		}
 	}
};




int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_players >> num_match) {
		DisjointSet sets(num_players);
		vector<pair <int, int> > win_lose_player;
		roots.clear();
		for (int i = 0; i < MAX; i++) {
			graph[i].clear();
		}
		memset(num_pointed, 0, sizeof(num_pointed));
		
		for (int i = 0; i < num_match; i++) {
			int p1, p2;
			char result;
			cin >> p1 >> result >> p2;
			if (result == '=') {
				sets.merge(p1, p2);
			}
			else {
				win_lose_player.push_back({p1, p2});
			}
		}
		for (int i = 0; i < win_lose_player.size(); i++) {
			int win_player = win_lose_player[i].first;
			int lose_player = win_lose_player[i].second;
			win_player = sets.find(win_player);
			lose_player = sets.find(lose_player);
			roots.insert(win_player);
			roots.insert(lose_player);
			if (graph[win_player].count(lose_player) == 0) {
				graph[win_player].insert(lose_player);
				num_pointed[lose_player]++;
			}
		}
		queue<int> q;
		for (int it : roots) {
			if (num_pointed[it] == 0) {
				q.push(it);
			}
		}
		int cnt = 0;
		while (!q.empty()) {
			int here = q.front();
			q.pop();
			cnt++;
			for (auto it : graph[here]) {
				num_pointed[it]--;
				if (num_pointed[it] == 0) {
					q.push(it);
				}
			}
		}
		if (cnt == roots.size()) {
			cout << "consistent\n";
		}
		else {
			cout << "inconsistent\n";
		}
	}
    

    return 0;
}

