#include <bits/stdc++.h>


using namespace std;

int width, height;

int dct_y[4] = {0, 1, 0, -1};
int dct_x[4] = {1, 0, -1, 0};
bool visited[501][501];
int board[501][501];
int max_cand = 0;
int extra_shape[4][4][2] = {{{0 , 0}, {0, 1}, {-1, 0}, {0 , -1}}, {{0,0}, {0, 1}, {-1, 0}, {1, 0}},{{0,0}, {0, 1}, {0, -1}, {1, 0}}, {{0,0}, {-1, 0}, {1, 0}, {0, -1}}};

bool IsInBound(int y, int x) {
	return (y>= 0 && y < height && x >= 0 && x < width);
}

void BFS(int y, int x, int sum, int cnt) {
	if (cnt == 4) {
		max_cand = max(max_cand, sum);
	}
	else {
		for (int i = 0; i < 4; i++) {
			int next_y = y + dct_y[i];
			int next_x = x + dct_x[i];
			if (IsInBound(next_y, next_x) && !visited[next_y][next_x]) {
				visited[y][x] = true;
				BFS(next_y, next_x, sum + board[y][x], cnt + 1);
				visited[y][x] = false;
			}
		}
	}
}
void ExtraShapes(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int next_y = y + extra_shape[i][j][0];
			int next_x = x + extra_shape[i][j][1];
			if (!IsInBound(next_y, next_x)) {
				break;
			}
			sum += board[next_y][next_x];
		}
		max_cand = max(max_cand, sum);
	}
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
//     std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//     std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> height >> width) {
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				cin >> board[y][x];
			}
		}
		memset(visited, 0 , sizeof(visited));
		max_cand = 0;
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				BFS(y, x, 0, 0);
				ExtraShapes(y,x);
			}
		}
		cout << max_cand << "\n";
	}
    

    return 0;
}

