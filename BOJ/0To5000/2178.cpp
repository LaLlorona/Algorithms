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
vector<int> graph[101 * 101];
int distance_from[101 * 101];
int input[101 * 101];
bool visited[101 * 101];

bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 && x < width);
}

int ConvertToInt(int y, int x) {
	return width * y + x;
}
void PreProcess() {
	string s;
	for (int i = 0; i < width * height; i++) {
		graph[i].clear();
		distance_from[i] = INF;		
	}
	for (int y = 0; y < height; y++) {
		cin >> s;
		for (int x = 0; x < width; x++) {
			input[ConvertToInt(y, x)] = s[x] - 48;
		}
	}
	
	for (int i = 0; i < width * height; i++) {
		if (input[i] == 1) {
			int y = i / width;
			int x = i % width;
			if (IsInBound(y + 1, x) && input[ConvertToInt(y + 1, x)] == 1) {
				graph[i].push_back(ConvertToInt(y + 1, x));
				
			}
			if (IsInBound(y - 1, x) && input[ConvertToInt(y - 1, x)] == 1) {
				graph[i].push_back(ConvertToInt(y - 1, x));
				
			}
			if (IsInBound(y, x + 1) && input[ConvertToInt(y, x + 1)] == 1) {
				graph[i].push_back(ConvertToInt(y, x + 1));
				
			}
			if (IsInBound(y, x - 1) && input[ConvertToInt(y, x - 1)] == 1) {
				graph[i].push_back(ConvertToInt(y, x - 1));
				
			}
		}
	}
	
	
	
}

void BFS(int start) {
	memset(visited, 0 ,sizeof(visited));
	queue<int> to_visit;
	
	
	
	distance_from[start] = 1;
	visited[start] = true;
	to_visit.push(start);
	
	
	
	
	while (!to_visit.empty()) {
		//cout << "iterating " << endl;
		int here = to_visit.front();
		to_visit.pop();
		
		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i];
			if (!visited[there]) {
				distance_from[there] = distance_from[here] + 1;
				visited[there] = true;
				to_visit.push(there);
			}
		}
	}
	
}

int Solve() {
	BFS(0);
	return distance_from[width * height - 1];
}



int main()
{
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> height >> width) {
		PreProcess();
		cout << Solve() << endl;
		// for (int i = 0; i < width * height; i++) {
		// 	if (input[i] == 1) {
		// 		cout << "current point is " << i << " and adjacent to ";
		// 		for (int j = 0; j < graph[i].size(); j++) {
		// 			cout << graph[i][j] << " ";
		// 		}
		// 		cout << endl;
		// 	}
		// 	cout << "dkstnace of " << i << " is " << distance_from[i] << endl;
			
		// }
		
	}
    

    return 0;
}

