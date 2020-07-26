#include <bits/stdc++.h>


using namespace std;

int num_gate, num_flight;
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
		if (root_u > root_v) { // always merge to smaller root
			parent[u] = root_v;
		}
		else {
			parent[v] = root_u;
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
	
	cin >> num_gate >> num_flight;
	DisjointSet sets(num_gate + 1);
	int total_available_docking = 0;
		
	for (int i = 0; i < num_flight; i++) {
		int current_flight;
		cin >> current_flight; 
		if (sets.find(current_flight) == 0) {
			break;
		}
		total_available_docking++;
		int availabe_docking_gate = sets.find(current_flight);
		sets.merge(availabe_docking_gate, availabe_docking_gate - 1);
	}
	cout << total_available_docking << "\n";
	
	return 0;
}
	
	
	
    



