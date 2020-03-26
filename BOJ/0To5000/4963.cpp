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

int input[60 * 60];
vector<int> graph[60 * 60];
bool visited[60 * 60];
int width, height;
int direct_x[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int direct_y[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

bool IsInBound(int y, int x) {
	if ((y >= 0 && y < height) && (x >= 0 && x < width)) {
		return true;
	}
	return false;
}

int ConvertToInt(int y, int x) {
	return y * width + x;
}

void FillGraph() {
	for (int i = 0; i < 60 * 60; i++) {
		graph[i].clear();
	}
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int current_point = ConvertToInt(y , x);
			if (input[current_point] == 1) {
				for (int i = 0; i < 8; i++) {
					int there = ConvertToInt(y + direct_y[i], x + direct_x[i]);
					if (IsInBound(y + direct_y[i], x + direct_x[i]) && input[there] == 1) {
						graph[current_point].push_back(there);
						graph[there].push_back(current_point);
					}
				}
			}
		}
	}
}

void DFS(int here) {
	visited[here] = true;
	for (int i = 0; i < graph[here].size(); i++) {
		int there =  graph[here][i];
		if (!visited[there]) {
			DFS(there);
		}
	}
}

void solve() {
	vector<int> connected_houses(0);
	memset(visited, 0 ,sizeof(visited));
	int count = 0;
	
	for (int i = 0; i < width * height; i++) {
		if (input[i] == 1 && !visited[i]) {
			DFS(i);
			count++;
		}
	}
	cout << count << "\n";
}

int main()
{
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	while (cin >> width >> height) {
		if (width == 0 && height == 0) {
			break;
		}
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				cin >> input[ConvertToInt(y, x)];
			}
		}
	
		FillGraph();
		solve();
	}
	
    return 0;
}

