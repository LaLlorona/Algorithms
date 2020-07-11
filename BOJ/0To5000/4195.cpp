#include <bits/stdc++.h>


using namespace std;

int num_connection;


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
	
// 	std::ifstream in("in.txt");
// 	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
// 	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		cin >> num_connection;
		
		DisjointSet sets(num_connection + 1);
		map<string, int> name_to_index;
		//map<int, string> index_to_name;
		int index_count = 0;
		for (int i = 0; i < num_connection; i++) {
			string friend_one;
			string friend_two;
			cin >> friend_one >> friend_two;
			if (name_to_index.find(friend_one) == name_to_index.end()) {
				name_to_index[friend_one] = index_count;
				//index_to_name[index_count] = friend_one;
				index_count++;
			}
			if (name_to_index.find(friend_two) == name_to_index.end()) {
				name_to_index[friend_two] = index_count;
				//index_to_name[index_count] = friend_two;
				index_count++;
			}
			//cout << "friend one is " << friend_one << " index is " << name_to_index[friend_one] << "\n";
			//cout << "friend two is " << friend_two << " index is " << name_to_index[friend_two] << "\n";
			sets.merge(name_to_index[friend_one], name_to_index[friend_two]);
			cout << sets.find_num(name_to_index[friend_one]) << "\n";
			
			
			
		}
		
	}
    

    return 0;
}

