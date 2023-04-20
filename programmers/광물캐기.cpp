#include <bits/stdc++.h>

using namespace std;

int cost[3][3] = {{1, 1, 1} , {5, 1, 1}, {25, 5, 1}};
vector<int> globalPicks;
vector<int> globalMinerals;

const int INF = 987654321;
int minCand = INF;

bool UsedAllPicks() {
    return (globalPicks[0] == 0 && globalPicks[1] == 0 && globalPicks[2] == 0);
}

void UpdateMincand(int mineralIndex, int currentFatigue) {
    if (mineralIndex >= globalMinerals.size() || UsedAllPicks()) {
        minCand = min(minCand, currentFatigue);
        return;
    }

    for (int pick = 0; pick < 3; pick++) {
        if (globalPicks[pick] != 0) { //when we can use pick
            globalPicks[pick]--;
            int fatigueAfterPick = currentFatigue;
            for (int j = mineralIndex; j < min((int)globalMinerals.size(), mineralIndex + 5); j++) {
                fatigueAfterPick += cost[pick][globalMinerals[j]];
            }
            UpdateMincand(mineralIndex + 5, fatigueAfterPick);
            globalPicks[pick]++;
        }
    }
}



int solution(vector<int> picks, vector<string> minerals) {
    globalPicks = picks;
    globalMinerals.clear();
    minCand = INF;

    for (int i = 0; i < minerals.size(); i++) {
        if (minerals[i] == "diamond") {
            globalMinerals.push_back(0);
        }
        else if (minerals[i] == "iron") {
            globalMinerals.push_back(1);
        }
        else {
            globalMinerals.push_back(2);
        }
    }
    UpdateMincand(0, 0);





    int answer = minCand;
    return answer;
}

int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    // vector<int> inputPicks = {1, 3, 2};
    // vector<string> inputMinerals = {"diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone"};

    vector<int> inputPicks = {0, 1, 1};
    vector<string> inputMinerals = {"diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond"};
    cout << solution(inputPicks, inputMinerals) << "\n";

    

    

}


  