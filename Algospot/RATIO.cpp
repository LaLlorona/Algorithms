#include <iostream>

using namespace std;
long long total_games;
long long  win_games;
const long long MAXIMUM_LEFT_GAMES = 2000000000;

bool PossibleToBeBetterIn(long long more_games) {
    int current_winrate =  (int)((double)win_games * 100 / total_games );
    int next_winrate =  (int)((double)(win_games + more_games) * 100 / (total_games + more_games) );
    
    if (next_winrate - current_winrate >= 1) {
        return true;
    }
    else {
        return false;
    }
}

long long FindMinimumMoreGames() { 
    long long lo = 0;
    long long hi = MAXIMUM_LEFT_GAMES;
    long long mid = 0;
    
    if (!PossibleToBeBetterIn(MAXIMUM_LEFT_GAMES)) {
        return -1;
    }
    if (PossibleToBeBetterIn(0)) {
        return 0;
    }
    
    for (int i = 0; i < 100; i++) {
        mid = (lo + hi) / 2;
        if (PossibleToBeBetterIn(mid)) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    }
    return hi;
    
    
    
}
int main()
{
    int num_testcase;
    cin >> num_testcase;
    
    for (int i = 0; i < num_testcase; i++) {
        cin >> total_games;
        cin >> win_games;
        cout << FindMinimumMoreGames() << endl;
        
    }
    

    return 0;
}
