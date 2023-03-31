#include <bits/stdc++.h>

using namespace std;

int n;
const int INF = 2087654321;
const int MAX = 100001;
int inputSequence[MAX];


void NumTargetSum() {
	sort(inputSequence, inputSequence + n);

	// for (int i =0 ; i < n; i++) {
	// 	cout << inputSequence[i] << " ";
	// }
	// cout << "\n";
	int lowCandidate = 0;
	int highCandidate = n - 1;

	int firstPointer = 0;
	int lastPointer = n - 1;
	int absMinSum = abs(inputSequence[firstPointer] + inputSequence[lastPointer]);

	while (firstPointer != lastPointer) {
		int currentSum = inputSequence[firstPointer] + inputSequence[lastPointer];
		if (abs(currentSum) < absMinSum) {
			absMinSum = abs(currentSum);
			lowCandidate = firstPointer;
			highCandidate = lastPointer;
		}

		if (currentSum == 0) {
			cout << inputSequence[firstPointer] << " " << inputSequence[lastPointer] << "\n"; 
			return;
		}
		else if (currentSum > 0) {
			lastPointer--;
		}
		else {
			firstPointer++;
		}

		
	}
	cout << inputSequence[lowCandidate] << " " << inputSequence[highCandidate] << "\n";
	
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
		for (int i = 0; i < n; i++) {
			cin >> inputSequence[i];
		}
	

		NumTargetSum();
	}

    


}


  