#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;

int food[MAX][MAX];
int mapY;
int mapX;
int visited[MAX][MAX];


int numDirections = 4;
int currentFood = 0;

int directions[4][2] = {{-1, 0}, {1,0}, {0,-1}, {0, 1}};


bool isInBound(int y, int x) {
    return (y >= 0 && y < mapY && x >= 0 && x < mapX);
}

void dfs(int y, int x) {
    visited[y][x] = 1; //이게 없으면 왜 안되는가?

    for (int i = 0; i < numDirections; i++) {
        
        int nextY = y + directions[i][0];
        int nextX = x + directions[i][1];
        if (isInBound(nextY, nextX) && (visited[nextY][nextX] == 0)) {
            // cout << "next visit is  " << nextX << " " << nextY << "\n"; 
            visited[y][x] = 1;
            currentFood += food[nextY][nextX];
            dfs(nextY, nextX);
        }
    }

}

vector<int> solution(vector<string> maps) {
    mapY = maps.size();
    mapX = maps[0].size();
    vector<int> answer;
    for (int y = 0; y < mapY; y++) {
        for (int x = 0; x < mapX; x++) {
            if (maps[y][x] == 'X') {
                food[y][x] = -1;
                visited[y][x] = -1;
            }
            else {
                food[y][x] = maps[y][x] - '0';
                visited[y][x] = 0;
            }
        }
        
    }

   

    for (int y = 0; y < mapY; y++) {
        for (int x = 0; x < mapX; x++) {
            if (visited[y][x] == 0) {

                currentFood = food[y][x];
                visited[y][x] = 1;
                
                dfs(y, x);

                answer.push_back(currentFood);

            }
        }
    }
    if (answer.size() == 0) {
        answer.push_back(-1);
    }
    sort(answer.begin(), answer.end());
  
    return answer;
}


int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(in.rdbuf());
    vector<int> result1 = solution({"X591X","X1X5X","X231X", "1XXX1"});
    vector<int> result2 = solution({"XXX","XXX","XXX"});

    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i] << " ";
    }
    cout << "\n";

    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i] << " ";
    }
    cout << "\n";

}


  