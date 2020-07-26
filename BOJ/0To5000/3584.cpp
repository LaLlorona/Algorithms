#include <bits/stdc++.h>


using namespace std;
const int MAX = 10002;
vector<int> tree[MAX];
bool am_i_root[MAX];
int parent_of[MAX];
int am_i_contain_ances2[MAX];
int num_node;
int root;
int find_ancestor1, find_ancestor2;


int AmIContainTwoChild(int here) { // return 1 if subtree of root here contains find_ancestor2
	int& ret = am_i_contain_ances2[here];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	if (here == find_ancestor2) {
		ret = 1;
		return ret;
	}
	else {
		for (int i = 0; i < tree[here].size(); i++) {
			int child = tree[here][i];
			if (AmIContainTwoChild(child) == 1) {
				ret = 1;
				break;
			}	
		}
		return ret;
	}
	
	
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
		cin >> num_node;
		memset(am_i_contain_ances2, -1, sizeof(am_i_contain_ances2));
		for (int i = 0 ; i < MAX; i++) {
			tree[i].clear();
		}
		for (int i = 1; i <= num_node; i++) {
			am_i_root[i] = true;
		}
		for (int i = 0; i < num_node - 1; i++) { 
			int parent, child;
			cin >> parent >> child;
			tree[parent].push_back(child);
			parent_of[child] = parent;
			am_i_root[child] = false;
		}
		
		for (int i = 1; i <= num_node; i++) {
			if (am_i_root[i]) {
				root = i;
				parent_of[i] = i;
				break;
			}
		}
		
		cin >> find_ancestor1 >> find_ancestor2;
			//cout << "common ancestor of " << find_ancestor1 << " and " << find_ancestor2 << " is ";
		int current_node = find_ancestor1;
		while (current_node != root) {
			if (AmIContainTwoChild(current_node) == 1) {
				cout << current_node << "\n";
				break;
			}
			else {
				//cout << current_node << " ";
				current_node = parent_of[current_node];
			
			}
		}
		if (current_node == root) {
			cout << root << "\n";
		}
	}
		
	
    

    return 0;
}

