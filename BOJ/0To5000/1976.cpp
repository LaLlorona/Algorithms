#include <bits/stdc++.h>


using namespace std;

int num_city, num_plan;
int plan[1001];


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

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
// 	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
// 	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_city >> num_plan) {
		DisjointSet sets(num_city);
		bool is_connected, is_plan_valid;
		is_plan_valid = true;
		for (int from = 0; from < num_city; from++) {
			for (int to = 0; to < num_city; to++) {
				cin >> is_connected;
				if (is_connected) {
					sets.merge(from, to);
				}
			}
		}
		for (int i = 0; i < num_plan; i++) {
			cin >> plan[i];
		}
		for (int i = 0; i < num_plan - 1; i++) {
			int from = plan[i] - 1;
			int to = plan[i + 1] - 1;
			if (sets.find(from) != sets.find(to)) {
				is_plan_valid = false;
				break;
			}
		}
		if (is_plan_valid) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
    

    return 0;
}

