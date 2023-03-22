#include <bits/stdc++.h>

using namespace std;

int lenSequence;
int numSum;
const int MAX = 100002;

int inputSequence[MAX];
int partialSum[MAX];

void FillPartialSum() {
    for (int i = 0 ; i < lenSequence; i++) {
        if (i == 0) {
            partialSum[i] = inputSequence[i];
        }
        else {
            partialSum[i] = partialSum[i - 1] + inputSequence[i];
        }

    }
}

int rangeSum(int from, int to) {
    if (from == 0) {
        return partialSum[to];
    }
    else {
        return partialSum[to] - partialSum[from - 1];
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

    while (cin >> lenSequence >> numSum) {
        for (int i = 0; i < lenSequence; i++) {
            cin >> inputSequence[i];
        }
        FillPartialSum();
        int from, to;
        for (int i = 0; i < numSum; i++) {
            cin >> from >> to;
            from--;
            to--;
            cout << rangeSum(from, to) << "\n";
        }

    }

}


  