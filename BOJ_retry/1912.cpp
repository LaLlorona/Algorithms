#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;
const int INF = 1987654321;

int maxCandidate = -INF;
int N;
int inputSequence[MAX];
int maxSumCandiate[MAX];
int cache[MAX];

int CalcMaxSequence(int index) { // when beginning from index 'index', what is the maximum value of consecutive sequence?  
    if (index == N - 1) {
        return inputSequence[index];
    }

    int& ret = cache[index];

    if (ret != -1) {
        return ret;
    }

    int temp = CalcMaxSequence(index + 1);

    if (temp > 0) {
        ret = temp + inputSequence[index];
    }
    else {
        ret = inputSequence[index];
    }
    return ret;
}


void FillMaxSumCandate() {
    for (int i = N - 1; i >= 0; i--) {
        if (i == N - 1) {
            maxSumCandiate[i] = inputSequence[i];
        }
        else {
            if (maxSumCandiate[i + 1] > 0) {
                maxSumCandiate[i] = maxSumCandiate[i + 1] + inputSequence[i];
            }
            else {
                maxSumCandiate[i] = inputSequence[i];
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
        memset(cache, -1, sizeof(cache));
        maxCandidate = -INF;
        for (int i = 0 ; i < N; i++) {
            cin >> inputSequence[i];
        }

        FillMaxSumCandate();

        for (int i = 0 ; i < N; i++) {
            maxCandidate = max(maxCandidate, maxSumCandiate[i]);
        }
        cout << maxCandidate << "\n";

        
    }

}


  