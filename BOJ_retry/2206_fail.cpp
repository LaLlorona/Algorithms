#include <bits/stdc++.h>

using namespace std;

typedef tuple<bool, int, int> bii; //canBreak, y, x
int height, width;
const int MAX = 1001;
int graph[MAX][MAX]; // 0: no wall, 1: wall
int distanceFrom[MAX][MAX];

const int numDirections = 4;
int directions[numDirections][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool IsInBound(int y, int x) {
    return (y >= 0 && y < height && x >= 0 && x < width);
}

// 벽을 한 개 까지 부술 수 있다. 
// 1. 그래프에서 모든 1에 대해 하나만 0으로 바꾸고 순회를 돈다 => 시간 복잡도에서 탈락할 것 같다. o(n^4) = (10^4)^4 / 10^8 초 이상 걸린다. 
// 2. queue 에 currentBreak 라는 parameter 를 하나 추가로 넣는다. currentBreak 가 true 일 경우 한 번까지 break 를 할 수 있다. 


int BFS() {
    bii beginPoint = bii(true, 0, 0);
    distanceFrom[0][0] = 1;

    queue<bii> bfsQueue;

    bfsQueue.push(beginPoint);

    while(!bfsQueue.empty()) {
        bii here = bfsQueue.front();
        bfsQueue.pop();
        bool canBreak = get<0>(here);
        int currentY = get<1>(here);
        int currentX = get<2>(here);
        for (int i = 0 ; i < numDirections; i++) {
            int nextY = currentY + directions[i][0];
            int nextX = currentX + directions[i][1];

            if (IsInBound(nextY, nextX)) {
                if (canBreak && graph[nextY][nextX] == 1 && distanceFrom[nextY][nextX] == -1) { //break the wall
                    bfsQueue.push(bii(false, nextY, nextX));
                    distanceFrom[nextY][nextX] = distanceFrom[currentY][currentX] + 1;
                    if (nextY == height - 1 && nextX == width - 1) {
                        return distanceFrom[nextY][nextX];
                    }
                }

                if (graph[nextY][nextX] == 0 && distanceFrom[nextY][nextX] == -1) {
                    bfsQueue.push(bii(canBreak, nextY, nextX));
                    distanceFrom[nextY][nextX] = distanceFrom[currentY][currentX] + 1;
                    if (nextY == height - 1 && nextX == width - 1) {
                        return distanceFrom[nextY][nextX];
                    }
                }
            }
        }
    }
    return -1;
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
        memset(distanceFrom, -1, sizeof(distanceFrom));
        for (int y = 0; y < height; y++) {
            string oneLine;
            cin >> oneLine;
            for (int x = 0; x < width; x++) {
                graph[y][x] = oneLine[x] - '0';
            }
        }
        cout << BFS() << "\n";
        // for (int y = 0; y < height; y++) {
        //     for (int x = 0; x < width; x++) {
        //         cout << distanceFrom[y][x] << " ";
        //     }
        //     cout << "\n";
        // }
    }

}


  