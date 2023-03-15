#include <bits/stdc++.h>

using namespace std;

const int INF = 1987654321;

const int MAX = 101;
const int NUM_OPERATIONS = 4;
int N;
int inputNumbers[MAX];
int operations[NUM_OPERATIONS]; // + - * /

int maxCandidate = -INF;
int minCandidate = INF;

void UpdateCandidate(int index, int currentResult) {
    if (index == N) {
        maxCandidate = max(maxCandidate, currentResult);
        minCandidate = min(minCandidate, currentResult);
        return;
    }

    if (index == 0) {
        UpdateCandidate(1, inputNumbers[0]);
    }
    else {
        for (int i = 0 ; i < NUM_OPERATIONS; i++) {
            if (operations[i] > 0) {
                operations[i]--;
                if (i == 0) {
                    UpdateCandidate(index + 1, currentResult + inputNumbers[index]);
                }
                else if (i == 1) {
                    UpdateCandidate(index + 1, currentResult - inputNumbers[index]);
                }
                else if (i == 2) {
                    UpdateCandidate(index + 1, currentResult * inputNumbers[index]);
                }
                else {
                    UpdateCandidate(index + 1, currentResult / inputNumbers[index]);
                }
                operations[i]++;

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
        maxCandidate = -INF;
        minCandidate = INF;

        for (int i = 0; i < N; i++) {
            cin >> inputNumbers[i];
        }

        for (int i = 0 ; i < NUM_OPERATIONS; i++) {
            cin >> operations[i];
        }

        UpdateCandidate(0, 0);
        cout << maxCandidate << "\n" << minCandidate << "\n";
    }


}


  