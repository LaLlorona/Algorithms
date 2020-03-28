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
const int INF = 987654321;
vector<pair<int, int> >graph[100002]; // weight and connected vertex number 
int distance_from[100002];
bool visited[100002];

int max_distance = 0;
int furthest_vertex = -1;

void BFS(int start) {
	memset(visited, 0 ,sizeof(visited));
	for (int i = 0; i < 100002; i++) {
		distance_from[i] = INF;
	}
	queue<int> to_visit;
	
	max_distance = 0;
	furthest_vertex = - 1;
	distance_from[start] = 0;
	visited[start] = true;
	to_visit.push(start);
	
	
	while (!to_visit.empty()) {
		//cout << "iterating " << endl;
		int here = to_visit.front();
		to_visit.pop();
		for (int i = 0; i < graph[here].size(); i++) {
			int weight = graph[here][i].first;
			int there = graph[here][i].second;
			if (!visited[there]) {
				distance_from[there] = distance_from[here] + weight;
				if (distance_from[there] > max_distance) {
					max_distance = distance_from[there];
					furthest_vertex = there;
				}
				visited[there] = true;
				to_visit.push(there);
			}
		}
	}
	
}

void FillGraph() {
	int here;
	int there;
	int weight;
	for (int i = 1; i <= num_vertex; i++) {
		cin >> here;
		while ((cin >> there) && there != -1) {
			cin >> weight;
			graph[here].push_back(make_pair(weight, there));
		}
	}
	
}



int main()
{
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_vertex) {
		FillGraph();
		BFS(1);
		BFS(furthest_vertex);
		cout << max_distance;
	}
    

    return 0;
}

