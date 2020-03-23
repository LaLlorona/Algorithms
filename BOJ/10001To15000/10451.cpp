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
	int num_testcase;
	int next;
	int count;
	cin >> num_testcase;
	while (num_testcase--) {
		cin >> num_vertex;
		num_edge = num_vertex;
		memset(visited, 0, sizeof(visited));
		for (int l = 0; l < 1001; l++) {
			graph[l].clear();
		}
		for (int j = 1; j <= num_vertex; j++) {
			cin >> next;
			graph[j].push_back(next);
		}
		count = 0;
		for (int k = 1; k <= num_vertex; k++) {
			if (!visited[k]) {
				DFS(k);
				count++;
			}
		}
		cout << count << " ";
		cout << endl;
		
	}
    return 0;
}

