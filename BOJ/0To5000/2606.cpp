#include <bits/stdc++.h>


using namespace std;

int num_vertex, num_edge;
vector<int> graph[101];
bool visited[101];

void Dfs(int from) {
	visited[from] = true;
	for (int i = 0; i < graph[from].size(); i++) {
		int to = graph[from][i];
		if (!visited[to]) {
			Dfs(to);
		}
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

	while (cin >> num_vertex >> num_edge) {
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < 101; i++) {
			graph[i].clear();
		}
		for (int i = 0 ; i < num_edge; i++) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		
		Dfs(0);
		int infected = 0;
		for (int i = 0; i < 101; i++) {
			if (visited[i]) {
				infected++;
			}
		}
		cout << infected - 1 << "\n";
		
	}
    

    return 0;
}

