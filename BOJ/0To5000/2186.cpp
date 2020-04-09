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


using namespace std;

int height, width, k;
string target;

int possible_path[101][101][81]; // possible_path[y][x][i] : number of possible path when i th character of given string is board[y][x];
char board[101][101];

int direct_x[4] = {0, -1, 1, 0};
int direct_y[4] = {-1, 0, 0, 1};

bool IsInBound(int y, int x) {
	return (y < height && y >= 0 && x < width && x >= 0);
}

vector<pair<int, int> > FindCharOnBoard(char c) {
	vector<pair<int, int> > occurance;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (board[y][x] == c) {
				occurance.push_back(make_pair(y ,x));
			}
		}
	}	
	return occurance;
}

void FillPossiblePath() {
	int last_index = target.size() - 1;
	int current_y, current_x;
	memset(possible_path, 0, sizeof(possible_path));
	vector<pair<int, int> > last_char_occurance_first = FindCharOnBoard(target[last_index]);
	
	for (int i = 0; i < last_char_occurance_first.size(); i++) {
		possible_path[last_char_occurance_first[i].first][last_char_occurance_first[i].second][last_index] = 1;
	}
	
	for (int current_index = last_index; current_index >= 1; current_index--) {
		vector<pair<int, int> > last_char_occurance = FindCharOnBoard(target[current_index]);
		for (int i = 0; i < last_char_occurance.size(); i++) {
			current_y = last_char_occurance[i].first;
			current_x = last_char_occurance[i].second;
			for (int multi = 1; multi <= k; multi++) {
				for (int j = 0; j < 4; j++) {
					int next_y = current_y + multi * direct_y[j];
					int next_x = current_x + multi * direct_x[j];
					int next_index = current_index - 1;
					if (IsInBound(next_y, next_x) && (board[next_y][next_x] == target[next_index])) {
						possible_path[next_y][next_x][next_index] += possible_path[current_y][current_x][current_index];
					}
				}
			}
		}
		
	}
		
		
}
int Solve() {
	vector<pair<int, int> > first_char_occurance = FindCharOnBoard(target[0]);
	int ret = 0;
	for (int i = 0; i < first_char_occurance.size(); i++) {
		ret += possible_path[first_char_occurance[i].first][first_char_occurance[i].second][0];
	}
	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	string one_line;
	
	while (cin >> height >> width >> k) {
		for (int y = 0; y < height; y++) {
			cin >> one_line;
			for (int x = 0; x < width; x++) {
				board[y][x] = one_line[x];
			}
		}
		cin >> target;
		FillPossiblePath();
		cout << Solve() << "\n";
	
	}
    

    return 0;
}

