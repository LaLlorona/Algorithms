#include <bits/stdc++.h>


using namespace std;

int width, height, num_cabbage;
bool cabbage[50][50];
bool earthworm[50][50];
int dct_y[4] = {-1, 1, 0, 0};
int dct_x[4] = {0, 0, -1, 1};
bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 && x < width);
}

void Dfs(int from) {
	int current_y = from / width;
	int current_x = from % width;
	earthworm[current_y][current_x] = true;
	for (int i = 0; i < 4; i++) {
		int next_y = current_y + dct_y[i];
		int next_x = current_x + dct_x[i];
		if (IsInBound(next_y, next_x) && cabbage[next_y][next_x] && !earthworm[next_y][next_x]) {
			Dfs(next_y * width + next_x);
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
	cin >> num_testcase;
	while (num_testcase--) {
		
		cin >> width >> height >> num_cabbage;
		int num_earthworm = 0;
		memset(cabbage, 0, sizeof(cabbage));
		memset(earthworm, 0, sizeof(earthworm));
		for (int i = 0; i < num_cabbage; i++) {
			int y, x;
			cin >> x >> y;
			cabbage[y][x] = true;
		}
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				if (cabbage[y][x] && !earthworm[y][x]) {
					Dfs(y * width + x);
					num_earthworm++;
				}
			}
		}
		cout << num_earthworm << "\n";
	}
    

    return 0;
}

