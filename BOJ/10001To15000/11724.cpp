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
	//cout << here << " ";
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
		//cout << from << " ";
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
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int a, b, count;
	while(cin >> num_vertex >> num_edge){
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
		count = 0;
		for (int i = 1; i <= num_vertex; i++) {
			if (!visited[i]) {
				DFS(i);
				count++;
			}
		}
		cout << count;
		
	}
    return 0;
}

