#include <bits/stdc++.h>

using namespace std;

const int MAX = 501;
const int INF = 987654321;
int n;

int inputSequence[MAX][MAX];
int cumulativeSum[MAX][MAX];

void FillCumulativeSum() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x <= y; x++) {
                if (y == 0) {
                    cumulativeSum[y][x] = inputSequence[y][x];
                }
                else {
                    if (x == 0) {
                    cumulativeSum[y][x] = cumulativeSum[y - 1][x];
                    }
                    else if ( x == y) {
                        cumulativeSum[y][x] = cumulativeSum[y-1][x-1];
                        }
                    else {
                        cumulativeSum[y][x] = max(cumulativeSum[y - 1][x], cumulativeSum[y - 1][x - 1]);
                        }
                    cumulativeSum[y][x] += inputSequence[y][x];
            }
        }      
    }
    int maxCand = -INF;
    for (int x = 0; x < n; x++) {
        maxCand = max(maxCand, cumulativeSum[n - 1][x]);
    }
    cout << maxCand << "\n";
}

int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    // std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); 
	// std::cin.rdbuf(in.rdbuf());

    while (cin >> n) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x <= y; x++) {
                cin >> inputSequence[y][x];
            }
        }
        FillCumulativeSum();
        // for (int y = 0; y < n; y++) {
        //     for (int x = 0; x <= y; x++) {
        //         cout << cumulativeSum[y][x] << " ";
        //     }
        //     cout << "\n";
        // }
    }



}

