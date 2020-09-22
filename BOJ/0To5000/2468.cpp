#include <bits/stdc++.h>


using namespace std;

int map_size;

int dct_y[4] = {-1, 0, 1, 0};
int dct_x[4] = {0, 1, 0, -1};

bool visited[100][100];
int building_height[100][100];

bool IsInBound(int y, int x) {
	return (y >= 0 && y < map_size && x >= 0 && x < map_size);
}
void FillSafeZone(int current_y, int current_x, int threshhold) {
	visited[current_y][current_x] = true;
	for (int i = 0; i < 4; i++) {
		int next_y = current_y + dct_y[i];
		int next_x = current_x + dct_x[i];
		if (IsInBound(next_y, next_x) && building_height[next_y][next_x] > threshhold && !visited[next_y][next_x]) {//there is connectable safezone from here
			FillSafeZone(next_y, next_x, threshhold);
		}
	}
}



int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> map_size) {
		for (int y = 0; y < map_size; y++) {
			for (int x = 0; x < map_size; x++) {
				cin >> building_height[y][x];
			}
		}
		int max_cand = -1;
		for (int i = 0; i <= 100; i++) {
			int num_safezone = 0;
			memset(visited, 0, sizeof(visited));
			for (int y = 0; y < map_size; y++) {
				for (int x = 0; x < map_size; x++) {
					if (building_height[y][x] > i && !visited[y][x]) {
						num_safezone++;
						FillSafeZone(y, x, i);
					}
				}
			}
			//cout << num_safezone << "\n";
			max_cand = max(max_cand, num_safezone);
		}
		cout << max_cand << "\n";
	}
    

    return 0;
}

