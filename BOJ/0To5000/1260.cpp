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
int start;

vector<int> graph[1001];
bool visited[1001];

void DFS(int here) {
	cout << here << " ";
	visited[here] = true;
	for (int i = 0; i < graph[here].size(); i++) {
		int there =  graph[here][i];
		if (!visited[there]) {
			DFS(there);
		}
	}
}

void BFS (int start) {
	queue<int> to_visit;
	visited[start] = true;
	
	to_visit.push(start);
	while (!to_visit.empty()) {
		int from = to_visit.front();
		to_visit.pop();
		cout << from << " ";
		//visited[from] = true;
		for (int i = 0; i < graph[from].size(); i++) {
			int there = graph[from][i];
			if (!visited[there]) {
				to_visit.push(there);
				visited[there] = true;
			}
		}
	}
		
	
}
int main()
{
	int a, b;
	while(cin >> num_vertex >> num_edge >> start){
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < 1001; i++) {
		graph[i].clear();
		}
		for (int i = 0; i < num_edge; i++) {
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
	
		for (int i = 0; i < num_vertex; i++) {
			sort(graph[i].begin(), graph[i].end());
		}
		DFS(start);
		cout << endl;
		memset(visited, 0, sizeof(visited));
		BFS(start);
	}
    return 0;
}

