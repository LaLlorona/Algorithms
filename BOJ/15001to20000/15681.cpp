#include <bits/stdc++.h>


using namespace std;

const int MAX = 100000;
vector<int> graph[MAX + 1];
bool visited[MAX + 1];
int components[MAX + 1];


int num_vertice, root, num_query;

int dfs(int here) {
	int& ret = components[here];
	visited[here] = true;
	if (ret != -1) {
		return ret;
	}
	ret = 1;
	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];
		if (!visited[there]) {
			ret += dfs(there);
		}
	}
	return ret;
	
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	while (cin >> num_vertice >> root >> num_query) {
		for (int i = 0; i < MAX + 1; i++) {
			graph[i].clear();
		}
		memset(visited, 0, sizeof(visited));
		memset(components, -1, sizeof(components));
		for (int i = 0; i < num_vertice - 1; i++) {
			int here, to;
			cin >> here >> to;
			graph[here].push_back(to);
			graph[to].push_back(here);
		}
		dfs(root);
		for (int i = 0; i < num_query; i++) {
			int query;
			cin >> query; 
			cout << components[query] << "\n";
		}
	}
    

    return 0;
}

