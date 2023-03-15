#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
const int MAX = 16;
int N;

int col[MAX]; // col[y] = x means a Queen is placed in (y, x) coordinate

int totalPossibleChoice = 0;

bool CanIPlaceQueen(int targetY, int targetX) {
    for (int y = 0; y < targetY; y++) {
        if (col[y] == targetX || col[y] - y == targetX - targetY || col[y] + y == targetX + targetY) {
            return false;
        }
    }
    return true;
}

void PlaceQueen(int placedQueen) {
    if (placedQueen == N) {
        totalPossibleChoice++;
        return;
    }

    for (int x = 0 ; x < N; x++) { //trying to place a queen in (placedQueen, x)
        if (CanIPlaceQueen(placedQueen, x)) {
            col[placedQueen] = x;
            PlaceQueen(placedQueen + 1);
            col[placedQueen] = -1;
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
        for (int i = 0 ; i < MAX; i++) {
            col[i] = INF;
        }
        totalPossibleChoice = 0;
        PlaceQueen(0);
        cout << totalPossibleChoice << "\n";
    }

    

    

}


  