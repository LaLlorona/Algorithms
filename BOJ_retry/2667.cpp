#include <bits/stdc++.h>

using namespace std;

const int MAX = 25;
bool mapInfo[MAX][MAX];
bool visited[MAX][MAX];
int N;
int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1},{0, -1}};
int numVillage;
int housePerVillage;
vector<int> housePerVillageRecord;

bool IsInBoundary(int y, int x) {
    return (y >= 0 && y < N && x >= 0 && x < N);
}

void DFS(int y, int x) {
    visited[y][x] = true;
    housePerVillage++;
    for (int i = 0; i < 4; i++) {
        int nextY = y + direction[i][0];
        int nextX = x + direction[i][1];
        if (IsInBoundary(nextY, nextX) &&  !visited[nextY][nextX] && mapInfo[nextY][nextX]){
            visited[nextY][nextX];
            DFS(nextY, nextX);
        }
    }
}

void UpdateHousePerVillageRecord() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (mapInfo[y][x] && !visited[y][x]) {
                numVillage++;
                DFS(y, x);
                housePerVillageRecord.push_back(housePerVillage);
                housePerVillage = 0;
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

    while (cin >> N) {
        memset(visited, 0 , sizeof(visited));
        for (int y = 0; y < N; y++) {
            string oneLine;
            cin >> oneLine;
            for (int x = 0; x < N; x++) {
                mapInfo[y][x] = oneLine[x] - '0';
            }
        }
        UpdateHousePerVillageRecord();
        cout << numVillage << "\n";

        sort(housePerVillageRecord.begin(), housePerVillageRecord.end());

        for (int i =0 ; i < housePerVillageRecord.size(); i++) {
            cout << housePerVillageRecord[i] << "\n";
        }
    }

}


  