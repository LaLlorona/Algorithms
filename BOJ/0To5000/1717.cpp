#include <bits/stdc++.h>


using namespace std;

int num_range, num_operations;


struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int n): parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int find(int u) {
		if (parent[u] == u) {
			return u;
		}
		else {
			return parent[u] = find(parent[u]);
		}
	}
	void merge(int u, int v) {
		int root_u = find(u);
		int root_v = find(v);
		if (root_u > root_v) {
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
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_range >> num_operations) {
		DisjointSet sets(num_range + 1);
		int operation, a, b;
		for (int i = 0; i < num_operations; i++) {
			cin >> operation >> a >> b;
			if (operation == 0) {
				sets.merge(a, b);
			}
			else {
				if (sets.find(a) == sets.find(b)) {
					cout << "YES\n";
				}
				else {
					cout << "NO\n";
				}
			}
		}
	}
    

    return 0;
}

