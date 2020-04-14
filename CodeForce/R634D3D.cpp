#include <bits/stdc++.h>


using namespace std;

int sudoku[9][9];

void FillSudoku() {
	string one_line;
	for (int i = 0; i < 9; i++) {
		cin >> one_line;
		for (int j = 0; j < 9; j++) {
			sudoku[i][j] = one_line[j] - '0';
		}
	}
	
}

void AntiSudoku() {
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			if (sudoku[y][x] == 1) {
				sudoku[y][x] = 2;
			}
		}
	}
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cout << sudoku[y][x];
		}
		cout << "\n";
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	cin >> num_testcase;
	
	
	while (num_testcase--) {
		FillSudoku();
		AntiSudoku();
	}
    

    return 0;
}

