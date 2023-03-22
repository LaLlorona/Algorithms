#include <bits/stdc++.h>

using namespace std;

int numDays;
int consecutiveDays;

const int MAX = 100001;
const int INF = 987654321;

int temperatureRecord[MAX];
int partialSumArray[MAX];


void FillPartialSum() {
	partial_sum(temperatureRecord, temperatureRecord + numDays, partialSumArray);
	// for (int i = 0 ; i < numDays; i++) {
	// 	cout << partialSumArray[i] << " ";
	// }
	// cout << "\n";
}

int returnSum(int from, int to) {
	if (from == 0) {
		return partialSumArray[to];
	}
	else {
		return partialSumArray[to] - partialSumArray[from - 1];
	}
}

void PrintMaxSum() {
	int maxCand = -INF;
	for (int i = 0 ; i + consecutiveDays - 1 < numDays; i++) {
		// cout << maxCand << " ";
		maxCand = max(maxCand, returnSum(i, i + consecutiveDays - 1));
		// cout << "\n";
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

	while (cin >> numDays >> consecutiveDays) {
		for (int i = 0; i < numDays; i++) {
			cin >> temperatureRecord[i];
		}
		FillPartialSum();
		PrintMaxSum();
	}

}


  