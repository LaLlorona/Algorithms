//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;
const int  n = 10;
const int INF = 987654321;
int board[10][10];
int papers[5] = {5, 5, 5, 5, 5};
int min_use = INF;

bool IsInBound(int y, int x) {
	return (y >= 0 && y < n && x >= 0 && x < n);
}

void CoverBoard(int pos) {
	//cout << pos << " ";
	if (pos == n * n) {
		//cout << "reached!!\n";
		int used = 0;
		for (int i = 0; i < 5; i++) {
			used += papers[i];
		}
		//cout << "paper used is " << used << "\n";
		min_use = min(min_use, 25 - used);
	}
	else {
		int y = pos / n;
		int x = pos % n;
		if (board[y][x] == 0) {
			CoverBoard(pos + 1);
		}
		else{
			for (int size = 1; size <= 5; size++) {
				if (papers[size - 1] == 0) {
					continue;
				}
				bool possible_cover = true;
				for (int cover_y = y; cover_y < y + size; cover_y++) {
					for (int cover_x = x; cover_x < x + size; cover_x++) {
						if (!IsInBound(cover_y, cover_x) || board[cover_y][cover_x] == 0) {
							possible_cover = false;
						}
					}
				}
				if (!possible_cover) {
					continue;			
				}
				//cout << "covered!!!\n";
				for (int cover_y = y; cover_y < y + size; cover_y++) {
					for (int cover_x = x; cover_x < x + size; cover_x++) {
						board[cover_y][cover_x] = 0;
					}
				}
				papers[size - 1] -= 1;
				CoverBoard(pos + 1);
				
				for (int cover_y = y; cover_y < y + size; cover_y++) {
					for (int cover_x = x; cover_x < x + size; cover_x++) {
						board[cover_y][cover_x] = 1;
					}
				}
				papers[size - 1] += 1;
			}
		}
	}
}


int main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	while (true) {
		min_use = INF;
		for (int i = 0; i < 5; i++) {
			papers[i] = 5;
		}
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cin >> board[y][x];
			}
		}
		CoverBoard(0);
		if (min_use == INF) {
			cout << -1 << "\n";
		}
		
		else {
			cout << min_use << "\n";
		}
	}
	
	
	return 0;
}


