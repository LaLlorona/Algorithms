#include <bits/stdc++.h>


using namespace std;
const int MAX = 10002;

int num_testcase;
vector<int> graph[MAX];
int depth[MAX];
int parent[MAX];
int num_node;
int target1, target2, root;

void FillDepth(int here, int current_depth) {
	depth[here] = current_depth;
	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];
		FillDepth(there, current_depth + 1);
	}
}

int FindLCA() {
	int depth_first = depth[target1];
	int depth_second = depth[target2];
	int here_first = target1;
	int here_second = target2;
	int depth_difference = abs(depth_first - depth_second);
	if (depth_first > depth_second) {
		for (int i = 0; i < depth_difference; i++) {
			here_first = parent[here_first];
		}
	}
	else {
		for (int i = 0; i < depth_difference; i++) {
			here_second = parent[here_second];
		}
	}
	for (int i = 0; i < min(depth_first, depth_second); i++) {
		if (here_first == here_second) {
			break;
		}
		here_first = parent[here_first];
		here_second = parent[here_second];
	}
	return here_first;
}
int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	cin >> num_testcase;
	while (num_testcase--) {
		cin >> num_node;
		memset(parent, 0 ,sizeof(parent));
		for (int i = 0; i < MAX; i++) {
			graph[i].clear();
		}
		for (int i = 0; i < num_node - 1; i++) {
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
			parent[to] = from;
		}
		
		cin >> target1 >> target2;
		
		for (int i = 1; i <= num_node; i++) { // find root
			if (parent[i] == 0) {
				root = i;
				break;
			}
		}
		FillDepth(root, 0);
		cout << FindLCA() << "\n";
		
	}
	
	
    

    return 0;
}

