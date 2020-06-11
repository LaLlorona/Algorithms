#include <bits/stdc++.h>


using namespace std;

int adj[400][400];
const int INF = 987654321;

int num_vertex, num_edge;




int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
// 	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
// 	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	while (cin >> num_vertex >> num_edge) {
		for (int i = 0; i < num_vertex; i++) {
			for (int j = 0; j < num_vertex; j++) {
				if (i == j) {
					adj[i][j] = 0;
				}
				else {
					adj[i][j] = INF;	
				}
			}
		}
		for (int i = 0; i < num_edge; i++) {
			int from, to, weight;
			cin >> from >> to >> weight;
			from--;
			to--;
			adj[from][to] = min(adj[from][to], weight);
		}
		for (int k = 0; k < num_vertex; k++) {
			for (int i = 0; i < num_vertex; i++) {
				for (int j = 0; j < num_vertex; j++) {
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}
		int min_cycle = INF;
		for (int i = 0; i < num_vertex; i++) {
			for (int j = 0; j < num_vertex; j++) {
				if (i != j) {
					min_cycle = min(min_cycle, adj[i][j] + adj[j][i]);
				}
			}
		}
		if (min_cycle == INF) {
			cout << -1 << "\n";
		}
		else {
			cout << min_cycle << "\n";
		}
	}
    

    return 0;
}

