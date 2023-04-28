#include <bits/stdc++.h>

using namespace std;

const int MAX = 9;
bool visited[MAX];
vector<int> middleResult;
vector<vector<int>> permutationResult;


void MakePermutation(int n, int currentCount) {

	if (currentCount == n) {
		permutationResult.push_back(middleResult);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			middleResult.push_back(i);
			visited[i] = true;
			MakePermutation(n, currentCount + 1);
			visited[i] = false;
			middleResult.pop_back();
		}
		
	}
}

int solution(int k, vector<vector<int>> dungeons) {
	memset(visited, 0,sizeof(visited));

	int numDungeons = dungeons.size();

	MakePermutation(numDungeons, 0);

	int maxDungeonRun = 0;

	for (int i = 0 ; i < permutationResult.size(); i++) {
		int currentHp = k;
		int numDungeonRun = 0;
		for (int j = 0; j < permutationResult[i].size(); j++) {
			int currentDungeon = permutationResult[i][j];
			if (currentHp >= dungeons[currentDungeon][0]) {
				currentHp -= dungeons[currentDungeon][1];
				numDungeonRun += 1;
			}
			else {
				break;
			}
		}
		maxDungeonRun = max(maxDungeonRun, numDungeonRun);
	}

    return maxDungeonRun;
}

// int solution() {
// 	memset(visited, 0,sizeof(visited));

// 	MakePermutation(3, 0);

// 	for (int i = 0; i < permutationResult.size(); i++) {
// 		for (int j = 0; j < permutationResult[i].size(); j++) {
// 			cout << permutationResult[i][j] << " ";
// 		}
// 		cout << "\n";
// 	}
//     int answer = -1;
//     return answer;
// }
//HOW TO MAKE permutaions?


int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(in.rdbuf());

	cout << solution(80, {{80,20},{50,40},{30,10}});

	



}


  