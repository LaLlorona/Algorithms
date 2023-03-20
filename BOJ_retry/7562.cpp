#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAX = 301;

int numTestcase;
int boardSize;
int beginY, beginX;
int targetY, targetX;

int chessDistance[MAX][MAX];

int directions[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
const int numDirections = 8;

bool IsInBound(int y, int x) {
    return ( y >= 0 && y < boardSize && x >= 0 && x < boardSize);
}

int numMovement() {
    if (targetY == beginY && targetX == beginX) {
        return 0;
    }
    queue<pii> bfsQueue;
    bfsQueue.push(pii(beginY, beginX));
    chessDistance[beginY][beginX] = 0;

    while (!bfsQueue.empty()) {
        pii here = bfsQueue.front();
        bfsQueue.pop();
        int currentDistance = chessDistance[here.first][here.second];

        for (int i = 0; i < numDirections; i++) {
            int nextY = here.first + directions[i][0];
            int nextX = here.second + directions[i][1];

            if (nextY == targetY && nextX == targetX) {
                return currentDistance + 1;
            }

            if (IsInBound(nextY, nextX) && chessDistance[nextY][nextX] == -1) {
                chessDistance[nextY][nextX] = currentDistance + 1;
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

    cin >> numTestcase;

    while (numTestcase--) {
        cin >> boardSize;
        cin >> beginY >> beginX;
        cin >> targetY >> targetX;

        memset(chessDistance, -1, sizeof(chessDistance));
        cout << numMovement() << "\n";

    }

}