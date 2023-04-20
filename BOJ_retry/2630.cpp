#include <bits/stdc++.h>

using namespace std;

int n;
const int MAX = 128;
int inputSequence[MAX][MAX];

int CheckColor(int beginY, int beginX, int len, int check) {
	int cnt = 0;
	for (int y = beginY; y < beginY + len; y++) {
		for (int x = beginX; x < beginX + len; x++) {
			if (check == inputSequence[y][x]) {
				cnt++;
			}
			
		}
	}

	if (cnt == 0) {
		return 0; //not found
	}
	else if (cnt == len * len) {
		return 1; //found
	}
	else{
		return -1;
	}


	
}

int NumPaper(int beginY, int beginX, int len, int check) {
	int CheckColorResult = CheckColor(beginY, beginX, len, check);
	if (CheckColorResult == 1) {
		return 1;
	}
	else if (CheckColorResult == 0) {
		return 0;
	}
	else {
		return NumPaper(beginY, beginX, len / 2, check) + NumPaper(beginY, beginX + len / 2, len / 2, check) + 
		NumPaper(beginY + len / 2, beginX, len / 2, check) +NumPaper(beginY + len / 2, beginX + len / 2, len / 2, check);
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

	while (cin >> n) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cin >> inputSequence[y][x];
			}
		}
		cout << NumPaper(0, 0, n, 0) << "\n" << NumPaper(0, 0, n ,1) << "\n";
	}

}


  