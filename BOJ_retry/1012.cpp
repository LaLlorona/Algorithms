#include <bits/stdc++.h>

using namespace std;

const int MAX = 51;
int numTestcase;
int width, height;
int numVegetables;

bool graph[MAX][MAX];
bool visited[MAX][MAX];

int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool IsInBoundary(int y, int x) {
    return ( y>= 0 && y < height && x >= 0 && x < width);
}

void DFS(int y, int x) {
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int nextY = y + direction[i][0];
        int nextX = x + direction[i][1];

        if (IsInBoundary(nextY, nextX) && graph[nextY][nextX] && !visited[nextY][nextX]) {
            visited[nextY][nextX] = true;
            DFS(nextY, nextX);
        }
    }
}

int FindRequiredEarthwarm() {
    int cnt = 0;
    for (int y =0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (graph[y][x] && !visited[y][x]) {
                cnt++;
                DFS(y, x);
            }
        }
    }
    return cnt;
}

int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    // std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); 
	// std::cin.rdbuf(in.rdbuf()); 

    cin >> numTestcase;

    while (numTestcase--) {
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
        cin >> width >> height >> numVegetables;
        for (int i = 0; i < numVegetables; i++) {
            int x, y;
            cin >> x >> y;
            graph[y][x] = true;

        }
        cout << FindRequiredEarthwarm() << "\n";

        
    }

}


  