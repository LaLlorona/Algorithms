#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <map>


using namespace std;

int width, height;
bool visited[26];
char graph[21][21];
int steps[21][21];
const int INF = 987654321;

int direct_x[4] = {0, -1, 1, 0};
int direct_y[4] = {-1, 0, 0, 1};

bool IsInBound(int y, int x) {
	return (y < height && y >= 0 && x < width && x >= 0);
}

void FillSteps(int y, int x, int cnt) {
	

	steps[y][x] = max(steps[y][x], cnt);
	//cout << y << " " << x << " " << steps[y][x] << "\n";
	for (int i = 0; i < 4; i++) {
		int next_y = y + direct_y[i];
		int next_x = x + direct_x[i];
		if (IsInBound(next_y, next_x) && !visited[graph[next_y][next_x] - 'A']) {
			visited[graph[next_y][next_x] - 'A'] = true;
		    
			FillSteps(next_y, next_x, cnt + 1);
			visited[graph[next_y][next_x] - 'A'] = false;
		}
	}
	
	
}
int Solve() {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			steps[y][x] = 0;
		}
	}
	memset(visited, 0 , sizeof(visited));
	visited[graph[0][0] - 'A'] = true;
	FillSteps(0, 0, 1);
	
	int ret = 0;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			//cout << y << " " << x << " " <<  steps[y][x] << "\n";
			if (steps[y][x] != 0) {
				ret = max(ret, steps[y][x]);
			}
			
		}
	}
	return ret;
	
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	
	string one_line;
	while (cin >> height>> width) {
		for (int y = 0 ; y < height; y++) {
			cin >> one_line;
			for (int x = 0; x < width; x++) {
				graph[y][x] = one_line[x];
			}
		}
		cout << Solve() << "\n";
		
	
	}
    

    return 0;
}

