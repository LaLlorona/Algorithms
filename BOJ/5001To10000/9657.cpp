#include <bits/stdc++.h>


using namespace std;


#define my 0
#define your 1
#define win true
#define lose false

int winner_at[1001][2];

// 0: SK, 1; CY
int CalcWinnerAt(int left_stone, int turn) {
	if (left_stone == 0) {
        if (turn == my) {
            return winner_at[left_stone][turn] = lose;
        }
        if (turn == your) {
            return winner_at[left_stone][turn] = win; 
        }
    }
    if (left_stone < 0) {
        if (turn == your) {
            return 0;
        }
        else if (turn == my) {
            return 1;
        }
    }
    int& ret = winner_at[left_stone][turn];
    if (ret != -1) {
        return ret;
    } 
    if (turn == my) {
        return ret = CalcWinnerAt(left_stone - 1, turn ^ 1) | CalcWinnerAt(left_stone - 3, turn ^ 1) | CalcWinnerAt(left_stone - 4, turn ^ 1);
    }
    else if (turn == your) {
        return ret = CalcWinnerAt(left_stone - 1, turn ^ 1) & CalcWinnerAt(left_stone - 3, turn ^ 1) & CalcWinnerAt(left_stone - 4, turn ^ 1);

    }
    return ret;


}


int main()
{
    std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
    std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
    std::cout.tie(NULL);

    // std::ifstream in("in.txt");
    // std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    // std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    int n;

    
    memset(winner_at, -1, sizeof(winner_at));
    while (cin >> n) {
        if (CalcWinnerAt(n, my) == win) {
            cout << "SK" << "\n";
        }
        else {
            cout << "CY" << "\n";
        }
		
    }
	// cout << CalcWinnerAt(2, my) << "\n";
	// cout << CalcWinnerAt(1, your);
    return 0;
}