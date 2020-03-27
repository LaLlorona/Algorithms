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

int width, height;
const int INF = 987654321;
vector<int> graph[1001 * 1001];
int distance_from[1001 * 1001];
int input[1001 * 1001];
bool visited[1001 * 1001];

bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 && x < width);
}

int ConvertToInt(int y, int x) {
	return width * y + x;
}
void PreProcess() {
	for (int i = 0; i < width * height; i++) {
		cin >> input[i];
		graph[i].clear();
		distance_from[i] = INF;		
	}
	
	for (int i = 0; i < width * height; i++) {
		if (input[i] >= 0) {
			int y = i / width;
			int x = i % width;
			if (IsInBound(y + 1, x) && input[ConvertToInt(y + 1, x)] >= 0) {
				graph[i].push_back(ConvertToInt(y + 1, x));
				graph[ConvertToInt(y + 1, x)].push_back(i);
			}
			if (IsInBound(y - 1, x) && input[ConvertToInt(y - 1, x)] >= 0) {
				graph[i].push_back(ConvertToInt(y - 1, x));
				graph[ConvertToInt(y - 1, x)].push_back(i);
			}
			if (IsInBound(y, x + 1) && input[ConvertToInt(y, x + 1)] >= 0) {
				graph[i].push_back(ConvertToInt(y, x + 1));
				graph[ConvertToInt(y, x + 1)].push_back(i);
			}
			if (IsInBound(y, x - 1) && input[ConvertToInt(y, x - 1)] >= 0) {
				graph[i].push_back(ConvertToInt(y, x - 1));
				graph[ConvertToInt(y, x - 1)].push_back(i);
			}
		}
	}
	
	
	
}

void BFS(vector<int> start) {
	memset(visited, 0 ,sizeof(visited));
	queue<int> to_visit;
	
	for (int i = 0; i < start.size(); i++) {
		int here = start[i];
		distance_from[here] = 0;
		visited[here] = true;
		to_visit.push(here);
	}
	
	
	
	while (!to_visit.empty()) {
		//cout << "iterating " << endl;
		int here = to_visit.front();
		to_visit.pop();
		
		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i];
			if (!visited[there]) {
				distance_from[there] = min(distance_from[here] + 1, distance_from[there]);
				visited[there] = true;
				to_visit.push(there);
			}
		}
	}
	
}

int Solve() {
	vector<int> ripen_tomato(0);
	for (int i = 0; i < width * height; i++) {
		if (input[i] == 1) {
			ripen_tomato.push_back(i);
		}
	}
	BFS(ripen_tomato);
	int max_distance_from = -1;
	for (int i = 0; i < width * height; i++) {
		if (input[i] != -1 && distance_from[i] == INF) {
			return -1;
		}
		else if (input[i] != -1) {
			max_distance_from = max(max_distance_from, distance_from[i]);
		}
		
		
	}
	return max_distance_from;
}



int main()
{
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> width >> height) {
		PreProcess();
		cout << Solve() << endl;
	}
    

    return 0;
}

