#include <bits/stdc++.h>


using namespace std;

int n;
int board[21][21];

int local_max = 0;

void UpdateBoard(int moves) {
	if (moves == 5) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				
				local_max = max(local_max, board[y][x]);
			}
		}
		// if (local_max == 32) {
		// 	for (int y = 0; y < n; y++) {
		// 		for (int x = 0; x < n; x++) {

		// 			cout << board[y][x] << " ";
		// 		}
		// 		cout << "\n";
		// 	}
		// 	cout << "\n";
		// }
		
	}
	else {
		
		
		for (int i = 0; i < 4; i++) {
			int board_before_update[21][21];
			for (int y = 0; y < n; y++) {
				for (int x = 0; x < n; x++) {
					board_before_update[y][x] = board[y][x];
				}
			}
			if (i == 0 || i == 2) {
				for (int x = 0; x < n; x++) {
					vector<int> one_line(0);
					vector<int> merged_line(n);
					for (int y = 0; y < n; y++) {
						if (board[y][x] != 0) {
							one_line.push_back(board[y][x]);
						}
					}
					if (i == 2) {
						reverse(one_line.begin(), one_line.end());
					}
					for (int j = 1; j < one_line.size() ; j++) {
						if (one_line[j - 1] == one_line[j]) {
							one_line[j - 1] *= 2;
							one_line[j] = 0;
						}
					}
					int pushed = 0;
					for (int j = 0; j < one_line.size(); j++) {
						if (one_line[j] != 0) {
							merged_line[pushed] = one_line[j];
							pushed++;
						}
					}
					if (i == 2) {
						reverse(merged_line.begin(), merged_line.end());
					}
					for (int j = 0; j < merged_line.size(); j++) {
						board[j][x] = merged_line[j];
					}
				}
				// cout <<i << " th attempt\n";
				// for (int y = 0; y < n; y++) {
				// 	for (int x = 0; x < n; x++) {
				// 		cout << board[y][x] << " ";
				// 	}
				// 	cout << "\n";
				// }
				UpdateBoard(moves + 1);
				for (int y = 0; y < n; y++) {
					for (int x = 0; x < n; x++) {
						board[y][x] = board_before_update[y][x];
					}
				}
			}
			
			if (i == 1 || i == 3) {
				for (int y = 0; y < n; y++) {
					vector<int> one_line(0);
					vector<int> merged_line(n);
					for (int x = 0; x < n; x++) {
						if (board[y][x] != 0) {
							one_line.push_back(board[y][x]);
						}
					}
					if (i == 3) {
						reverse(one_line.begin(), one_line.end());
					}
					for (int j = 1; j < one_line.size() ; j++) {
						if (one_line[j - 1] == one_line[j]) {
							one_line[j - 1] *= 2;
							one_line[j] = 0;
						}
					}
					int pushed = 0;
					for (int j = 0; j < one_line.size(); j++) {
						if (one_line[j] != 0) {
							merged_line[pushed] = one_line[j];
							pushed++;
						}
					}
					if (i == 3) {
						reverse(merged_line.begin(), merged_line.end());
					}
					for (int j = 0; j < merged_line.size(); j++) {
						board[y][j] = merged_line[j];
					}
				}
				// cout <<i << " th attempt\n";
				// for (int y = 0; y < n; y++) {
				// 	for (int x = 0; x < n; x++) {
				// 		cout << board[y][x] << " ";
				// 	}
				// 	cout << "\n";
				// }
				UpdateBoard(moves + 1);
				for (int y = 0; y < n; y++) {
					for (int x = 0; x < n; x++) {
						board[y][x] = board_before_update[y][x];
					}
				}
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
	int num_testcase;
	
	while (cin >> n) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cin >> board[y][x];
			
			}
		}
		local_max = 0;
		UpdateBoard(0);
		cout << local_max << "\n";
	}
    

    return 0;
}

