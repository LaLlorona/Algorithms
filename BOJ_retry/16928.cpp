#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;
typedef tuple<int, int> ii;
int numLadder, numSnake;



map<int, int> teleports;

int mapInfo[MAX];

bool IsInBound(int x) {
    return (x >= 1 && x <= 100);
}


int BFS(){
    queue<int> bfsQueue;
    int beginPoint = 1;
    mapInfo[beginPoint] = 0;
    bfsQueue.push(beginPoint);

    while (!bfsQueue.empty()) {
        int here = bfsQueue.front();
        int currentDistance = mapInfo[here];
        bfsQueue.pop();
        for (int i = 1; i <= 6; i++) {
            int next = here + i;
            if (teleports.find(next) != teleports.end()) {
                next = teleports[next];
            }
            if (next == 100) {
                return currentDistance + 1;
            }
            if (mapInfo[next] == -1) {
                mapInfo[next] = currentDistance + 1;
            bfsQueue.push(next);
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

    while (cin >> numLadder >> numSnake) {
        teleports.clear();
        memset(mapInfo, -1, sizeof(mapInfo));
        int from, to;
        for (int i = 0; i < numLadder + numSnake; i++) {
            cin >> from >> to;
            teleports[from] = to;
        }
        cout << BFS() << "\n";
    }

}


  