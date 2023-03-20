#include <bits/stdc++.h>

using namespace std;

// struct Coordinate {
//     int z;
//     int y;
//     int x;
// };

typedef tuple<int, int, int> iii;


const int INF = 987654321;
const int MAX = 101;
int width, depth, height;
int day;

int graph[MAX][MAX][MAX];

int direction[6][3] = {{-1, 0, 0}, {1, 0, 0},{0, 1, 0},{0, -1, 0},{0, 0, 1},{0, 0, -1}};
const int numDirections = 6;

vector<iii> beginPoints;

bool IsInBoundary(int z, int y, int x) {
    return ( y >= 0 && y < depth && x >= 0 && x < width && z >= 0 && z < height);
}

int CheckDay() {
    int maxDay = -INF;
    for (int z = 0; z < height; z++) {
        for (int y = 0; y < depth; y++) {
            for (int x = 0; x < width; x++) {
                maxDay = max(maxDay, graph[z][y][x]);
                if (graph[z][y][x] == 0) {
                    return -1;
                }
            }
        }
    }
    

    return maxDay - 1;
}
int BFS() {
    if (CheckDay() == 0) {
        return 0;
    }

    queue<iii> bfsQueue;
    for (int i = 0 ; i <beginPoints.size(); i++) {
        bfsQueue.push(beginPoints[i]);

        
    }

    while (!bfsQueue.empty()) {
        iii here = bfsQueue.front();
        bfsQueue.pop();

        int currentDay = graph[get<0>(here)][get<1>(here)][get<2>(here)];
        for (int i = 0; i < numDirections; i++) {
            int nextZ = get<0>(here) + direction[i][0];
            int nextY = get<1>(here) + direction[i][1];
            int nextX = get<2>(here) + direction[i][2];
            if (IsInBoundary(nextZ, nextY, nextX) && graph[nextZ][nextY][nextX] == 0) {
                graph[nextZ][nextY][nextX] = currentDay + 1;
                iii nextPoint = iii(nextZ, nextY, nextX);
                bfsQueue.push(nextPoint);
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

    std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(in.rdbuf()); 

    while (cin>> width >> depth >> height) {
        beginPoints.clear();
        for (int z = 0; z < height; z++) {
            for (int y = 0; y < depth; y++) {
                for (int x = 0; x < width; x++) {
                    cin >> graph[z][y][x];
                    if (graph[z][y][x] == 1) {
                        
                        beginPoints.push_back(iii(z,y,x));
                    }
                }
            }
        }
        
        cout << BFS() << "\n";
    }

}