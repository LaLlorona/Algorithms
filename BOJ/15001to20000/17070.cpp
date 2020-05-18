#include <bits/stdc++.h>
//#include <iostream>

using namespace std;
int cache[16][16][16][16];
int board[16][16];
int n;

bool IsInBound(int y, int x) {
	return (y >= 0 && y < n && x >= 0 && x < n);
}
int CurrentState(int first_y, int first_x, int second_y, int second_x) {
	if (first_y + 1 == second_y && first_x + 1 == second_x) {
		return 1; // diagonally positioned	
	}
	else if (first_y + 1 == second_y) {
		return 2;
	}
	else {
		return 0;
	}
}

int NumMoves(int first_y, int first_x, int second_y, int second_x) {
	//cout << first_y << " " << first_x << " " << second_y << " " << second_x << "\n";
	if (second_y == n - 1 && second_x == n - 1) {
		return 1;	
	}
	int& ret = cache[first_y][first_x][second_y][second_x];
	
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	int current_state = CurrentState(first_y, first_x, second_y, second_x);
	//cout << "current state is " << current_state << "\n";
	if (current_state == 0) {
		if (IsInBound(second_y, second_x + 1) && board[second_y][second_x + 1] == 0) {
			ret += NumMoves(first_y, first_x + 1, second_y, second_x + 1);
			if (IsInBound(second_y + 1, second_x) && IsInBound(second_y + 1, second_x + 1) 
			&& board[second_y + 1][second_x] == 0 && board[second_y + 1][second_x + 1] == 0) {
				ret += NumMoves(first_y, first_x + 1, second_y + 1, second_x + 1);
			}
		}
	}
	
	else if (current_state == 2) {
		if (IsInBound(second_y + 1, second_x) && board[second_y + 1][second_x] == 0) {
			ret += NumMoves(first_y + 1, first_x, second_y + 1, second_x);
			if (IsInBound(second_y, second_x + 1) && IsInBound(second_y + 1, second_x + 1) 
			&& board[second_y][second_x + 1] == 0 && board[second_y + 1][second_x + 1] == 0) {
				ret += NumMoves(first_y + 1, first_x, second_y + 1, second_x + 1);
			}
		}
	}
	else {
		bool right_check = false;
		bool down_check = false;
		if (IsInBound(second_y , second_x + 1) && board[second_y][second_x + 1] == 0) {
			right_check = true;
			ret += NumMoves(first_y + 1, first_x + 1, second_y, second_x + 1);
		}
		if (IsInBound(second_y + 1, second_x) && board[second_y + 1][second_x] == 0) {
			down_check = true;
			ret += NumMoves(first_y + 1, first_x + 1, second_y + 1, second_x);
		}
		if (right_check && down_check && IsInBound(second_y + 1, second_x + 1) &&
		board[second_y + 1][second_x + 1] == 0) {
			ret += NumMoves(first_y + 1, first_x + 1, second_y + 1, second_x + 1);
		}
	}
	return ret;
}
int main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	while (cin >> n) {
		memset(cache, -1,  sizeof(cache));
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cin >> board[y][x];
			}
		}
		cout << NumMoves(0, 0, 0, 1) << "\n";
	}
	
	return 0;
}