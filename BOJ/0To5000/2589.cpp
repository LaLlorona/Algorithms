#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> pii;

int width, height;
int travel_time[50][50];
bool is_land[50][50];

int dct_y[4] = {-1, 0, 1, 0};
int dct_x[4] = {0, 1, 0, -1};


bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 && x < width);
}
int MaxTravelTime(int start_y, int start_x) {
	memset(travel_time, -1, sizeof(travel_time));
	int max_cand_hour = 0;
	queue<pii> bfs_queue;
	bfs_queue.push({start_y, start_x});
	travel_time[start_y][start_x] = 0;
	while (!bfs_queue.empty()) {
		int here_y = bfs_queue.front().first;
		int here_x = bfs_queue.front().second;
		int here_time = travel_time[here_y][here_x];
		max_cand_hour = max(max_cand_hour, here_time);
		bfs_queue.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = here_y + dct_y[i];
			int next_x = here_x + dct_x[i];
			if (IsInBound(next_y, next_x) && is_land[next_y][next_x] && travel_time[next_y][next_x] == -1) {
				travel_time[next_y][next_x] = here_time + 1;
				bfs_queue.push({next_y, next_x});
			}
		}
	}
	return max_cand_hour;
	
}


int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> height >> width) {
		for (int y = 0; y < height; y++) {
			string one_line;
			cin >> one_line;
			for (int x = 0; x < width; x++) {
				if (one_line[x] == 'W') {
					is_land[y][x] = false;
				}
				else {
					is_land[y][x] = true;
				}
			}
		}
		int max_cand = -1;
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				if (is_land[y][x]) {
					max_cand = max(max_cand, MaxTravelTime(y, x));
				}
			}
		}
		cout << max_cand << "\n";
	}
    

    return 0;
}

