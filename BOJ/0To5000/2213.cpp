#include <bits/stdc++.h>


using namespace std;
vector<int> tree[10001];
int am_i_root[10001];
int parent_of[10001];
int num_node;
int root;
int find_ancestor1, find_ancestor2;

bool AmIContainTwoChild(int here) {
	if (here == find_ancestor2) {
		return true;
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		cin >> num_node;
		for (int i = 1; i <= num_node; i++) {
			am_i_root[i] = true;
		}
		for (int i = 0; i < num_node - 1; i++) {
			int parent, int child;
			cin >> parent >> child;
			tree[parent].push_back(child);
			parent_of[child] = parent 
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
		
		
	}
    

    return 0;
}

