#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
//#include <queue>
using namespace std;
const int MAX = 1001;
int num_singer;
int num_PD;
vector<int> graph[MAX];
//bool connected[MAX][MAX];
int num_pointed[MAX];
bool visited[MAX];

void TopologicalSort() {
	queue<int> q;
	for (int i = 1; i <= num_singer; i++) {
		if (num_pointed[i] == 0) {
			q.push(i);
		}
	}
	vector<int> result;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		//visited[here] = true;
		result.push_back(here);
		
		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i];
			num_pointed[there] = num_pointed[there] - 1;
			if (num_pointed[there] == 0) {
				q.push(there);
			}
		}
	}
	if (result.size() == num_singer) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << "\n";
		}
	}
	else {
		cout << "0\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	while (cin >> num_singer >> num_PD) {
		memset(num_pointed, 0, sizeof(num_pointed));
		memset(visited, 0 ,sizeof(visited));
		for (int i = 0; i < MAX; i++) {
			graph[i].clear();
		}
		for (int i = 0; i < num_PD; i++) {
			int num_idea;
			cin >> num_idea;
			vector<int> temp;
			int singer;
			for (int j = 0; j < num_idea; j++) {
				cin >> singer;
				temp.push_back(singer);
			}
			for (int j = 0; j < num_idea - 1; j++) {
				graph[temp[j]].push_back(temp[j + 1]);
				num_pointed[temp[j + 1]]++;
			}
		}
		TopologicalSort();
	}
	
	
	
	return 0;
}


