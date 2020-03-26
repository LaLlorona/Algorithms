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

int input[26][26];
vector<int> graph[26 * 26];
bool visited[26 * 26];
int n;
int connected_vertex = 0;

bool IsInBound(int y, int x) {
	if ((y >= 0 && y < n) && (x >= 0 && x < n)) {
		return true;
	}
	return false;
}
int ConvertToInt(int y, int x) {
	return n * y + x;
}
void FillGraph() {
	for (int i = 0; i < 26 * 26; i++) {
		graph[i].clear();
	}
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			int current_point = ConvertToInt(y , x);
			if (input[y][x] == 1) {
				if (IsInBound(y + 1, x) && input[y + 1][x] == 1) {
					graph[current_point].push_back(ConvertToInt(y + 1, x));
				}
				if (IsInBound(y - 1, x) && input[y - 1][x] == 1) {
					graph[current_point].push_back(ConvertToInt(y - 1, x));
				}
				if (IsInBound(y, x + 1) && input[y][x + 1] == 1) {
					graph[current_point].push_back(ConvertToInt(y, x + 1));
				}
				if (IsInBound(y, x - 1) && input[y][x - 1] == 1) {
					graph[current_point].push_back(ConvertToInt(y, x - 1));
				}
			}
			
			
		}
	}
}

void DFS(int here) {
	visited[here] = true;
	connected_vertex++;
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
	
	for (int i = 0; i < n * n; i++) {
		if (input[i / n][i % n] == 1 && !visited[i]) {
			// cout << "visited vertex is " << i << " ";
			DFS(i);
			connected_houses.push_back(connected_vertex);
			connected_vertex = 0;
		}
	}
	// cout << endl;
	cout << connected_houses.size() << endl;
	sort(connected_houses.begin(), connected_houses.end());
	for (int i = 0; i < connected_houses.size(); i++) {
		cout << connected_houses[i] << endl;
	}
}

int main()
{
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	while (cin >> n) {
		string s;
		for (int y = 0; y < n; y++) {
			cin >> s; 
			for (int x = 0; x < n; x++) {
				input[y][x] = s[x] - 48;
			}
		}
	
		FillGraph();
		solve();
	}
	
	// cin >> n;
	
	
	
    return 0;
}

