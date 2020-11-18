#include <bits/stdc++.h>


using namespace std;

int rows[10]; // rows[i] = j means put a queen in ith row, j th column. base value is -1 
vector<vector<string> > result;

void FillNQueen(int current_row, int board_size) {
	if (current_row == board_size) {//when all queens are successfully used
		vector<string> one_result;
		
		for (int i = 0; i < board_size; i++) {
			string temp(board_size, '.');
			temp[rows[i]] = 'Q';
			one_result.push_back(temp);
		}
		result.push_back(one_result);
		return;
	}
	// filling queens
	for (int i = 0; i < board_size; i++) {//is it possible to use queen at ith column?
		bool possible = true;
		for (int j = 0; j < current_row; j++) {
			if (rows[j] == i || abs(rows[j] - i) == current_row - j) {
				possible = false;
				break;
			}
		}
		if (possible) {
			rows[current_row] = i;
			FillNQueen(current_row + 1, board_size);
			rows[current_row] = -1;
		}
	}
	
}

vector<vector<string>> solveNQueens(int n) {
	memset(rows, -1, sizeof(rows));
	result.clear();
	FillNQueen(0, n);
	return result;
}




int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	for (int i = 0; i <= 9; i++) {
		cout << "N queen result when there is " << i << " queens\n";
		vector<vector<string> > result = solveNQueens(i);
		for (int j = 0; j < result.size(); j++) {
			for (int k = 0; k < result[j].size(); k++) {
				cout << result[j][k] << " ";
			}
			cout << "\n";
		}
	}
	
	// vector<vector<string> > result = solveNQueens(4);
	// for (int j = 0; j < result.size(); j++) {
	// 	for (int k = 0; k < result[j].size(); k++) {
	// 		cout << result[j][k] << " ";
	// 	}
	// 	cout << "\n";
	// }
	
	
    

    return 0;
}

