#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;


const int MAX = 1000001;
int numSteps[MAX];


vector<int> possibleNextStep(int step, int n) {
    vector<int> nextStep(3);
    nextStep[0] = step * 2;
    nextStep[1] = step * 3;
    nextStep[2] = step + n;
    return nextStep;
}

bool IsInBound(int n) {
    return (n >= 1 && n < MAX);
}

int BFS(int x, int y, int n) {
    if (x == y) {
        return 0;
    }
    numSteps[x] = 0;
    queue<pii> bfsQueue;
    bfsQueue.push(pii(0, x)); //numStep, currentNumber;

    while (!bfsQueue.empty()) {
        
        pii here = bfsQueue.front();
        bfsQueue.pop();

        int hereStep = here.first;
        int hereNumber = here.second;

       
        vector<int> nextNum = possibleNextStep(hereNumber, n);

        for (int i = 0; i < nextNum.size(); i++) {
            if (nextNum[i] == y) {
                return hereStep + 1;
            }

            if (IsInBound(nextNum[i]) && numSteps[nextNum[i]] == -1) {
                numSteps[nextNum[i]] = hereStep + 1;
                bfsQueue.push(pii(hereStep + 1, nextNum[i]));
            }
        }
    }

    return -1;
}


int solution(int x, int y, int n) {
    
    memset(numSteps, -1, sizeof(numSteps));
    return BFS(x, y, n);
}

int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(in.rdbuf());

    cout << solution(2 ,5 , 4);

    

}


  