#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
using namespace std;

vector<int> graph[11];
int num_city;
int people[11];
int city_type[11];
int visited[11];
const int INF = 987654321;


bool CheckBit(int num, int kth) {
	return (num & (1 << kth)) > 0;
}

bool Reachable(int here, int here_type) {
	visited[here] = here_type;
	
	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];
		if (visited[there] == 0 && city_type[there] == here_type) {
			Reachable(there, here_type);
		}
	}
}

int Solve() {
	int total_possibility = (2 << num_city) - 1;
	int min_cand = INF;
	for (int i = 1; i < total_possibility; i++) {
		int city1, city2;
		for (int j = 0; j < num_city; j++) {
			if (CheckBit(i, j)) {
				city_type[j] = 1;
				city1 = j;
			}
			else {
				city_type[j] = 2;
				city2 = j;
			}
		}
		memset(visited, 0, sizeof(visited));
		Reachable(city1, 1);
		Reachable(city2, 2);
		bool seperatable = true;
		for (int j = 0; j < num_city; j++) {
			if (visited[j] == 0) {
				seperatable = false;
				break;
			}
			else if (visited[j] == 1 && city_type[j] != 1) {
				seperatable = false;
				break;
			}
			else if (visited[j] == 2 && city_type[j] != 2) {
				seperatable = false;
				break;
			}
		}
		if (!seperatable) {
			continue;
		}
		int people_city1, people_city2;
		for (int j = 0; j < num_city; j++) {
			if (city_type[j] == 1) {
				people_city1 += people[j];
			}
			else {
				people_city2 += people[j];
			}
		}
		min_cand = min(min_cand, abs(people_city1 - people_city2));
	}
	if (min_cand == INF) {
		return -1;
	}
	else {
		return min_cand;
	}
}






int main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	while (cin >> num_city) {
		for (int i = 0; i < num_city; i++) {
			cin >> people[i];
		}
		for (int i = 0; i < num_city; i++) {
			int num_adjacent;
			cin >> num_adjacent;
			for (int j = 0; j < num_adjacent; j++) {
				int adjacent;
				cin >> adjacent;
				adjacent = adjacent - 1;
				graph[j].push_back(adjacent);
				graph[adjacent].push_back(j);
			}
		}
		cout << Solve() << "\n";
	}
	
	
	
	return 0;
}


