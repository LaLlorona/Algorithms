#include <bits/stdc++.h>


using namespace std;

int width, height;

int dct_y[4] = {0, -1, 0, 1};
int dct_x[4] = {-1, 0, 1, 0};

int iceberg_current[300][300];
int iceberg_future[300][300];
bool visited[300][300];

bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 && x < width);
}
void Dfs(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int next_y = y + dct_y[i];
		int next_x = x + dct_x[i];
		if (IsInBound(next_y, next_x) && !visited[next_y][next_x] && iceberg_current[next_y][next_x] > 0){
			Dfs(next_y, next_x);
		}
	}
}

void UpdateFutureIceberg() {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int adjacent_water = 0;
			for (int i = 0; i < 4; i++) {
				int next_y = y + dct_y[i];
				int next_x = x + dct_x[i];
				if (IsInBound(next_y, next_x) && iceberg_current[next_y][next_x] == 0) {
					adjacent_water++;
				}
			}
			iceberg_future[y][x] = max(0, iceberg_current[y][x] - adjacent_water);	
		}
	}
}



int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	// memset(iceberg_future, 0, sizeof(iceberg_future));
	// memset(iceberg_current, 0, sizeof(iceberg_current));

	while (cin >> height >> width) {
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				cin >> iceberg_current[y][x];
				iceberg_future[y][x] = iceberg_current[y][x];
			}
		}
		int current_year = 0;
		
		while (true) {
			memset(visited, 0, sizeof(visited));
			
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					iceberg_current[y][x] = iceberg_future[y][x];
				}
			}
			UpdateFutureIceberg();
			
			int current_chunk = 0;
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					if (iceberg_current[y][x] != 0 && !visited[y][x]) { // if this chunk is not visited
						current_chunk++;
						Dfs(y, x);
					}
				}
			}
			if (current_chunk == 0) {
				cout << 0 << "\n";
				break;
			}
			else if (current_chunk >= 2) {
				cout << current_year << "\n";
				break;
			}
			current_year++;
			// for (int y = 0; y < height; y++) {
			// 	for (int x = 0; x < width; x++) {
			// 		cout << iceberg_future[y][x] << " ";
			// 	}
			// 	cout << "\n";
			// }
			// cout << "\n";
			
			
			
			
		}
	}
	
    

    return 0;
}

