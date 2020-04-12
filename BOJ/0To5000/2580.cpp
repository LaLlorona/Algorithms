#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <map>


using namespace std;

int sudoku_board[9][9]; // input sudoku board
bool row[9][10], col[9][10], square[9][10]; // row[a][b] : true if b is exists on ath row 

void MakeSudokuBoard() {
	int input_num;
	int current_row, current_col, current_square;
	for (int i = 0; i < 81; i++) {
		cin >> input_num;
		current_row = i / 9;
		current_col = i % 9;
		current_square = (current_row / 3) * 3 + (current_col / 3);
		
		row[current_row][input_num] = true;
		col[current_col][input_num] = true;
		square[current_square][input_num] = true;
		
		sudoku_board[current_row][current_col] = input_num;
		
	}
}

void FillSudokuBoard(int current_pixel) {
	if (current_pixel == 81) { // when filling all pixels of sudoku
		for (int y = 0; y < 9; y++) {
			for (int x = 0; x < 9; x++) {
				cout << sudoku_board[y][x] << " ";
			}
			cout << "\n";
		}
		exit(0);
		
	}
	else {
		int current_y = current_pixel / 9;
		int current_x = current_pixel % 9;
		int current_square = (current_y / 3) * 3 + (current_x / 3);
		if (sudoku_board[current_y][current_x] != 0) {
			FillSudokuBoard(current_pixel + 1);
		}
		else {
			for (int i = 1; i <= 9; i++) {
				if (!row[current_y][i] && !col[current_x][i] && !square[current_square][i]) { // when poissble to fill current pixel with i
					row[current_y][i] = true;
					col[current_x][i] = true;
					square[current_square][i] = true;
					sudoku_board[current_y][current_x] = i;
					FillSudokuBoard(current_pixel + 1);
					row[current_y][i] = false;
					col[current_x][i] = false;
					square[current_square][i] = false;
					sudoku_board[current_y][current_x] = 0;
					
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
	
	
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(square, 0, sizeof(square));
	MakeSudokuBoard();
	
	FillSudokuBoard(0);
	
	
    

    return 0;
}

