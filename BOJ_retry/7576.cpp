#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int INF = 987654321;
const int MAX = 1001;
int width, height;
int day;

int graph[MAX][MAX];

int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int numDirections = 4;

vector<pii> beginPoints;

bool IsInBoundary(int y, int x) {
    return ( y >= 0 && y < height && x >= 0 && x < width);
}

int CheckDay() {
    int maxDay = -INF;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            maxDay = max(maxDay, graph[y][x]);
            if (graph[y][x] == 0) {
                return -1;
            }
        }
    }

    return maxDay - 1;
}
int BFS() {
    if (CheckDay() == 0) {
        return 0;
    }

    queue<pii> bfsQueue;
    for (int i = 0 ; i <beginPoints.size(); i++) {
        bfsQueue.push(beginPoints[i]);

        
    }

    while (!bfsQueue.empty()) {
        pii here = bfsQueue.front();
        bfsQueue.pop();

        int currentDay = graph[here.first][here.second];
        for (int i = 0; i < numDirections; i++) {
            int nextY = here.first + direction[i][0];
            int nextX = here.second + direction[i][1];
            if (IsInBoundary(nextY, nextX) && graph[nextY][nextX] == 0) {
                graph[nextY][nextX] = currentDay + 1;
                bfsQueue.push(pair(nextY, nextX));
            }
        }
    }

    return CheckDay();
}
int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    // std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); 
	// std::cin.rdbuf(in.rdbuf()); 

    while (cin>> width >> height) {
        beginPoints.clear();
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                cin >> graph[y][x];
                if (graph[y][x] == 1) {
                    beginPoints.push_back(pii(y, x));
                }
            }
        }
        cout << BFS() << "\n";
    }

}