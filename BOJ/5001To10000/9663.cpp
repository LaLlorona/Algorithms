#include <bits/stdc++.h>


using namespace std;

int n;
int col[15];
int num_possible_place = 0;

bool ValidPosition(int i) {
	for (int j = 0; j < i; j++) {
		if (col[i] == col[j] || abs(col[i] - col[j]) == i - j) {
			return false;
		}
	}
	return true;
}

void NQueen(int placed) {
	if (placed == n) {
		num_possible_place++;
	}
	else {
		for (int j = 0; j < n; j++) {
			col[placed] = j;
			if (ValidPosition(placed)) {
				NQueen(placed + 1);
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
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> n) {
		
		memset(col, 0, sizeof(col));
		num_possible_place = 0;
		NQueen(0);
		cout << num_possible_place << "\n";
		
	}
    

    return 0;
}

