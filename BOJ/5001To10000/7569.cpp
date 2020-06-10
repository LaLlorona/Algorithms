#include <bits/stdc++.h>


using namespace std;
const int INF = 987654321;
int width, height, layer;
int tomato[100][100][100];
int day[100][100][100];

int dct_z[6] = {-1, 1, 0, 0, 0, 0};
int dct_y[6] = {0, 0, -1, 1, 0, 0};
int dct_x[6] = {0, 0, 0, 0, -1, 1};

int IsInBound(int z, int y, int x) {
	return (z >= 0 && z < layer && y >= 0 && y < height && x >= 0 && x < width);
}

void BFS() {
	queue<int> bfs_queue;
	for (int i = 0; i < layer; i++) {
		for (int j = 0; j < height; j++) {
			for (int k = 0; k < width; k++) {
				if (tomato[i][j][k] == 1) {
					day[i][j][k] = 0;
					bfs_queue.push(i * height * width + j * width + k);
				}
			}
		}
	}
	while (!bfs_queue.empty()) {
		int here = bfs_queue.front();
		bfs_queue.pop();
		int current_z = here / (height * width);
		int current_y = (here % (height * width)) / width;
		int current_x = (here % (height * width)) % width;
		for (int i = 0; i < 6; i++) {
			int next_z = current_z + dct_z[i];
			int next_y = current_y + dct_y[i];
			int next_x = current_x + dct_x[i];
			
			if (IsInBound(next_z, next_y, next_x) && tomato[next_z][next_y][next_x] == 0) {
				tomato[next_z][next_y][next_x] = 1;
				day[next_z][next_y][next_x] = day[current_z][current_y][current_x] + 1;
				bfs_queue.push(next_z * height * width + next_y * width + next_x);
			}
		}
	}
}

int FindMaxDay() {
	int max_cand = -1;
	for (int i = 0; i < layer; i++) {
		for (int j = 0; j < height; j++) {
			for (int k = 0; k < width; k++) {
				if (tomato[i][j][k] != -1) {
					if (day[i][j][k] == INF) {
						return -1;
					}
					else {
						max_cand = max(max_cand, day[i][j][k]);
					}
				}
			}
		}
	}
	return max_cand;
}

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	while (cin >> width >> height >> layer) {
		for (int i = 0; i < layer; i++) {
			for (int j = 0; j < height; j++) {
				for (int k = 0; k < width; k++) {
					cin >> tomato[i][j][k];
					day[i][j][k] = INF;
				}
			}
		}
		BFS();
		cout << FindMaxDay() << "\n";
		
	}
    

    return 0;
}

