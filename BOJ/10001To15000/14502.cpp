#include <bits/stdc++.h>


using namespace std;

int height, width;
int lab_initial[8][8];
int lab_after_spreading[8][8];

int direction_y[4] = {-1, 0, 0, 1};
int direction_x[4] = {0, -1, 1, 0};

bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 && x < width);
}

void PreProcess() {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cin >> lab_initial[y][x];
			lab_after_spreading[y][x] = lab_initial[y][x];
			
		}
	}
}
void BFS(int wall1, int wall2, int wall3) {
	queue<pair<int, int> > to_visit;
	
	lab_after_spreading[wall1 / width][wall1 % width] = 1;
	lab_after_spreading[wall2 / width][wall2 % width] = 1;
	lab_after_spreading[wall3 / width][wall3 % width] = 1;
	
	
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (lab_after_spreading[y][x] == 2) {
				to_visit.push(make_pair(y, x));
			}
		}
	}
	while (!to_visit.empty()) {
		int current_y = to_visit.front().first;
		int current_x = to_visit.front().second;
		to_visit.pop();
		for (int i = 0 ; i < 4; i++) {
			int next_y = current_y + direction_y[i];
			int next_x = current_x + direction_x[i];
			if (IsInBound(next_y, next_x) && lab_after_spreading[next_y][next_x] == 0) {
				lab_after_spreading[next_y][next_x] = 2;
				to_visit.push(make_pair(next_y, next_x));
			}
		}
	}
}
int Solve() {
	int max_safe_zone_cand = 0;
	
	for (int i = 0; i < width * height; i++) {
		for (int j = i + 1; j < width * height; j++) {
			for (int k = j + 1; k < width * height; k++) {
				if (lab_initial[i / width][i % width] == 0 && lab_initial[j/ width][j % width] == 0 && lab_initial[k / width][k % width] == 0) { // possible to build walls on i, j, k
					int safe_zone_count = 0;
					for (int y = 0; y < height; y++) { // initializing 
						for (int x = 0; x < width; x++) {
							lab_after_spreading[y][x] = lab_initial[y][x];
							
						}
					}
					BFS(i, j, k);
					for (int y = 0; y < height; y++) {
						for (int x = 0; x < width; x++) {
							if (lab_after_spreading[y][x] == 0) {
								safe_zone_count++;
							}
						}
					}
					max_safe_zone_cand = max(max_safe_zone_cand, safe_zone_count);
					
				}
			}
		}
	}
	return max_safe_zone_cand;
}


int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	while (cin >> height >> width) {
		PreProcess();
		cout << Solve() << "\n";
	
	}
    

    return 0;
}

