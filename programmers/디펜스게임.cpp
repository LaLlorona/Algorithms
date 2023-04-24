#include <bits/stdc++.h>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int, vector<int>, greater<int> > enemyStopBySkill;
    int numEnemyStopBySkill = 0;
    int cumulativeEnemyAtThisWave = 0;

    for (int wave = 0; wave < enemy.size(); wave++) {
        cumulativeEnemyAtThisWave += enemy[wave];
        if (k > enemyStopBySkill.size()) { //when you can use the skill
            enemyStopBySkill.push(enemy[wave]);
            numEnemyStopBySkill += enemy[wave];
            continue;
        }
        if (enemyStopBySkill.top() < enemy[wave]) { //when using skill at this wave is more efficient, use it
            int difference = enemy[wave] - enemyStopBySkill.top();
            enemyStopBySkill.pop();
            enemyStopBySkill.push(enemy[wave]);
            numEnemyStopBySkill += difference;
        }
        // cout <<"current wave is " << wave << " and cumulative enemy is " << cumulativeEnemyAtThisWave << " and numEnemystopbyskill is " << numEnemyStopBySkill << "\n";

        if (cumulativeEnemyAtThisWave - numEnemyStopBySkill > n) {
            return wave;
        }
    }
    return enemy.size();

    
}


int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(in.rdbuf());

    vector<int> test1 = {4, 2, 4, 5, 3, 3, 1};
    cout << solution(7, 3, test1) << "\n";

    vector<int> test2 = {3, 3, 3, 3};
    cout << solution(2, 4, test2) << "\n";

}