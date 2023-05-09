#include <bits/stdc++.h>

using namespace std;
typedef tuple<int, int, int> tiii;

const int ROOMSIZE = 5;
const int CHECKDISTANCE = 2;

bool visited[ROOMSIZE][ROOMSIZE];
vector<string> currentPlace;

int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool IsInBoundary(int y, int x) {
	return (y >= 0 && y < ROOMSIZE && x >= 0 && x < ROOMSIZE);
}

bool CheckSocialDistancing(int y, int x) {
	memset(visited, 0, sizeof(visited));
	queue<tiii> distancingCheckQueue;

	distancingCheckQueue.push({y, x, 0});

	visited[y][x] = true;

	while (!distancingCheckQueue.empty()) {
		tiii here = distancingCheckQueue.front();
		distancingCheckQueue.pop();

		int hereY = get<0>(here);
		int hereX = get<1>(here);
		int hereDistance = get<2>(here);

		for (int i = 0; i < 4; i++) {
			int nextY = hereY + directions[i][0];
			int nextX = hereX + directions[i][1];
			

			if (IsInBoundary(nextY, nextX) && hereDistance <= 1 && currentPlace[nextY][nextX] != 'X') {
				if (currentPlace[nextY][nextX] == 'P' && !visited[nextY][nextX]) {
					return false;
				}
				visited[nextY][nextX] = true;
				distancingCheckQueue.push(tiii(nextY,nextX, hereDistance + 1));
			}
		}

	}
	return true;
}



vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

	for (int i = 0; i < places.size(); i++) {
		int socialDistancingChecked = 1;
		currentPlace = places[i];
		for (int y = 0; y < ROOMSIZE; y++) {
			for (int x = 0; x < ROOMSIZE; x++) {
				if (places[i][y][x] == 'P') {
					if (!CheckSocialDistancing(y, x)) {
						socialDistancingChecked = 0;
					}
				}
			}
		}
		answer.push_back(socialDistancingChecked);
	}
    return answer;
}

void PrintVector(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
}

int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    string test = "asdfasdf";

    std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(in.rdbuf()); 

	vector<vector<string>> test1 = {{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, 
	{"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};

	PrintVector(solution(test1));



}


  