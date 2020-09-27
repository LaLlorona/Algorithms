#include <bits/stdc++.h>


using namespace std;

int num_node, deleted_node, root_node;
vector<int> graph[51];

int CalcLeafNode(int current_node) {
	if (current_node == deleted_node) {
		return 0;
	}
	else {
		int num_child = graph[current_node].size();
		int result = 0;
		if (num_child == 0) {
			return 1;
		}
		if (num_child == 1 && graph[current_node][0] == deleted_node) {
			return 1;
		}
		for (int i = 0; i < graph[current_node].size(); i++) {
			int child = graph[current_node][i];
			result += CalcLeafNode(child);
		}
		return result;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	while (cin >> num_node) {
		for (int i = 0; i < 51; i++) {
			graph[i].clear();
		}
		for (int i = 0; i < num_node; i++) {
			int parent;
			cin >> parent;
			if (parent == -1) {
				root_node = i;
			}
			else {
				graph[parent].push_back(i);
			}
		}
		cin >> deleted_node;
		cout << CalcLeafNode(root_node) << "\n";
	}
    

    return 0;
}

