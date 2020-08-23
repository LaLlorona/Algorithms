#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
using namespace std;

vector<vector<vector<int> > > CCTVs = { {{0}, {1}, {2}, {3}}, {{0, 2}, {1, 3}}, {{0, 1}, {1, 2}, {2, 3}, {3, 0}},
{{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}}, {{0, 1, 2, 3}} };
int dct_x[4] = {0, 1, 0, -1};
int dct_y[4] = {1, 0, -1, 0};

const int MAX = 8;
const int INF = 987654321;
int width, height;
int office[MAX][MAX];
int min_cand = INF;

int CountEmpty() {
	int cnt = 0;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (office[y][x] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}

bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 && x < width);
}
void PrintOffice() {
	for (int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			cout << office[y][x] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void UpdateMin(int here) {
	if (here == width * height) {
		min_cand = min(min_cand, CountEmpty());
		//PrintOffice();
	}
	else {
		int current_y = here / width;
		int current_x = here % width;
		if (office[current_y][current_x] >= 10000 && office[current_y][current_x] <= 60000) {//when here is cctv
			int cctv_type = office[current_y][current_x] / 10000 - 1;
			
			for (int i = 0; i < CCTVs[cctv_type].size(); i++) { //total number of direction contingent to type of cctv. its value if from 1 to 4
				for (int j = 0; j < CCTVs[cctv_type][i].size(); j++) {
					int direction = CCTVs[cctv_type][i][j];
					for (int k = 1; k <= MAX; k++) {
						int next_y = current_y + k * dct_y[direction];
						int next_x = current_x + k * dct_x[direction];
						if (IsInBound(next_y, next_x)) {
							if (office[next_y][next_x] == INF) {
								break; // when meet the wall
							}
							else {
								office[next_y][next_x]++;
							}
						}
					}
				}
				UpdateMin(here + 1);
				for (int j = 0; j < CCTVs[cctv_type][i].size(); j++) {
					int direction = CCTVs[cctv_type][i][j];
					for (int k = 1; k <= MAX; k++) {
						int next_y = current_y + k * dct_y[direction];
						int next_x = current_x + k * dct_x[direction];
						if (IsInBound(next_y, next_x)) {
							if (office[next_y][next_x] == INF) {
								break; // when meet the wall
							}
							else {
								office[next_y][next_x] = office[next_y][next_x] - 1;
							}
						}
					}
				}
			}
		}
		else { // when here is not the wall
			UpdateMin(here + 1);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	while (cin >> height >> width) {
		memset(office, 0, sizeof(office));
		min_cand = INF;
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				int num;
				cin >> num;
				if (num >= 1 && num <= 5) {
					office[y][x] = num * 10000;
				}
				else if (num == 6) {
					office[y][x] = INF;
				}
			}
		}
		UpdateMin(0);
		cout << min_cand << "\n";
	}
	
	
	
	
	
	return 0;
}



