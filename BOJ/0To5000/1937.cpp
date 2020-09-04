#include <bits/stdc++.h>


using namespace std;

int maze_size;
int max_survival_day[500][500];
int bamboo[500][500];
int dct_x[4] = {0, 1, 0, -1};
int dct_y[4] = {1, 0, -1, 0};

bool IsInBound(int y, int x) {
	return (y >= 0 && y < maze_size && x >= 0 && x < maze_size);
}
int MaxSurvivalDayUntil(int y, int x) {
	int& ret = max_survival_day[y][x];
	if (ret != -1) {
		return ret;
	}
	else {
		ret = 1;
		for (int i = 0; i < 4; i++) {
			int next_y = y + dct_y[i];
			int next_x = x + dct_x[i];
			if (IsInBound(next_y, next_x) && bamboo[next_y][next_x] > bamboo[y][x]) {
				ret = max(ret, 1 + MaxSurvivalDayUntil(next_y, next_x));
			}
		}
		return ret;
	}
}
 

int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
//     std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//     std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	while (cin >> maze_size) {
		memset(max_survival_day, -1, sizeof(max_survival_day));
		for (int y = 0; y < maze_size; y++) {
			for (int x = 0; x < maze_size; x++) {
				cin >> bamboo[y][x];
			}
		}
		int ret = 0;
		for (int y = 0; y < maze_size; y++) {
			for (int x = 0; x < maze_size; x++) {
				ret = max(ret, MaxSurvivalDayUntil(y, x));
			}
		}
		cout << ret << "\n";
		
	}
    

    return 0;
}

