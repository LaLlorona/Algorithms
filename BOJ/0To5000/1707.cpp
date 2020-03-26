#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>



using namespace std;

int num_vertex;
int num_edge;

vector<int> graph[20001];
int color[20001];

void DFS (int here, int paint) {
	color[here] = paint;
	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];
		if (color[there] == 0) {
			DFS(there, 3 - paint);
		}
	}
}

string CheckColor() {
	for (int i = 1; i <= num_vertex; i++) {
		if (color[i] == 0) {
			DFS(i, 1);
		}
	}
	for (int i = 1; i <= num_vertex; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			if (color[i] == color[graph[i][j]]) {
				return "NO";
			}
		}
	}
	return "YES";
}

// void BFS (int start) {
// 	queue<int> to_visit;
// 	visited[start] = true;
	
// 	to_visit.push(start);
// 	while (!to_visit.empty()) {
// 		int from = to_visit.front();
// 		to_visit.pop();
// 		//cout << from << " ";
// 		//visited[from] = true;
// 		for (int i = 0; i < graph[from].size(); i++) {
// 			int there = graph[from][i];
// 			if (!visited[there]) {
// 				to_visit.push(there);
// 				visited[there] = true;
// 			}
// 		}
// 	}
		
	
// }
int main()
{
	std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int a, b;
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		cin >> num_vertex;
		cin >> num_edge;
		memset(color, 0, sizeof(color));
		for (int l = 0; l < 20001; l++) {
			graph[l].clear();
		}
		for (int j = 1; j <= num_edge; j++) {
			cin >> a;
			cin >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		cout << CheckColor() << "\n";
		// for (int i = 1; i <= num_vertex; i++) {
		// 	cout << color[i] << " ";
		// }
		// cout << endl;
		 
		
	}
    return 0;
}

