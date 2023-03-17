#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAX = 101;
int height, width;

bool mapInfo[MAX][MAX];
int distanceInfo[MAX][MAX];

queue<pii> bfsQueue;

int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1},{0, -1}};

bool IsInBoundary(int y, int x) {
    return (y >= 0 && y < height && x >= 0 && x < width);
}

void BFS(int beginY, int beginX) {
    distanceInfo[beginY][beginX] = 1;
    bfsQueue.push(pii(beginY, beginX));

    while (!bfsQueue.empty()) {
        pii here = bfsQueue.front();
        bfsQueue.pop();

        for (int i = 0; i < 4; i++) {
            int nextY = here.first + direction[i][0];
            int nextX = here.second + direction[i][1];
            int currentDistance = distanceInfo[here.first][here.second];

            if (IsInBoundary(nextY, nextX) && mapInfo[nextY][nextX] && distanceInfo[nextY][nextX] == -1) {
                distanceInfo[nextY][nextX] = currentDistance + 1;
                bfsQueue.push(pii(nextY, nextX));
            }
        }
    }
}

int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);    

    // std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); 
	// std::cin.rdbuf(in.rdbuf());

    while (cin >> height >> width) {
        memset(mapInfo, 0, sizeof(mapInfo));
        memset(distanceInfo, -1, sizeof(distanceInfo));

        for (int y = 0; y < height; y++) {
            string oneLine;
            cin >> oneLine;
            for (int x = 0; x < width; x++) {
                mapInfo[y][x] = oneLine[x] - '0';
            }
        }
        BFS(0 ,0);
        cout << distanceInfo[height - 1][width - 1] << "\n";

    }

}


  