#include <bits/stdc++.h>

using namespace std;


const int MAX = 100001;
const int INF = 987654321;


int inputSequence[MAX];
int partialSum[MAX];
int n;
int targetSum;

void FillPartialSum() {
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			partialSum[i] = inputSequence[i];
		}
		else {
			partialSum[i] = partialSum[i - 1] + inputSequence[i];
		}
	}
}

int SumFromTo(int from, int to) {
	if (to == 0) {
		return partialSum[to];
	}
	else {
		return partialSum[to] - partialSum[from - 1];
	}
}

int FindShortestTargetSum() {
	int from = 0;
	int to = 0;
	int shortestLength = INF;

	while (!(to == n)) {
		// cout << "current from and to is " << from << " " << to << "\n";
		int currentSum = SumFromTo(from, to);
		if (currentSum >= targetSum) {
			shortestLength = min(shortestLength, to - from + 1);
			from++;
			if (shortestLength == 1) {
				return 1;
			}
		}

		else if (currentSum < targetSum) {
			to++;
		}
	}
	if (shortestLength == INF) {
		shortestLength =0;
	}
	return shortestLength;
}


int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    // std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); 
	// std::cin.rdbuf(in.rdbuf()); 

	while (cin >> n >> targetSum) {
		for (int i = 0; i < n; i++) {
			cin >> inputSequence[i];
		}
		// sort(inputSequence, inputSequence + n);
		FillPartialSum();
		// for (int i = 0; i < n; i++) {
		// 		cout << inputSequence[i] << " ";
		// 	}
		// 	cout << "\n";
		cout << FindShortestTargetSum() << "\n";
	}

}


  