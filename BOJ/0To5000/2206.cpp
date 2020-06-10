#include <bits/stdc++.h>


using namespace std;

const int INF = 987654321;
int width, height;

int board[1000][1000];
int min_distance[1000][1000];

int direct_y[4] = {-1, 0, 0, 1};
int direct_x[4] = {0, -1, 1, 0};

bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 && x < width);
}


void BFS() {
	min_distance[0][0] = 1;
	priority_queue< pair<int, int >, vector< pair<int, int> >, greater< pair<int, int > > > pq;
	pq.push({0, 0}); //num_break, position 
	
	while (!pq.empty()) {
		int current_break = pq.top().first;
		int current_y = pq.top().second / width;
		int current_x = pq.top().second % width;
		pq.pop();
		
		if (current_break <= 1) {
			for (int i = 0; i < 4; i++) {
				int next_y = current_y + direct_y[i];
				int next_x = current_x + direct_x[i];
				if (IsInBound(next_y, next_x)) {
					if (min_distance[next_y][next_x] > min_distance[current_y][current_x] + 1) {
						if (board[next_y][next_x] == 1 && current_break == 0) {
							min_distance[next_y][next_x] = min_distance[current_y][current_x] + 1;
							pq.push({current_break + 1, next_y * width + next_x});
						}
						else if (board[next_y][next_x] == 0) {
							min_distance[next_y][next_x] = min_distance[current_y][current_x] + 1;
							pq.push({current_break, next_y * width + next_x});
						}
					}
				}
			}
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

	while (cin >> height >> width) {
		for (int y = 0; y < height; y++) {
			string one_line;
			cin >> one_line;
			for (int x = 0; x < width; x++) {
				min_distance[y][x] = INF;
				board[y][x] = one_line[x] - '0';
			}
		}
		BFS();
		// for (int y = 0; y < height; y++) {
		
		// 	for (int x = 0; x < width; x++) {
		// 		cout << min_distance[y][x] << " ";
		// 	}
		// 	cout << "\n";
		// }
		if (min_distance[height - 1][width - 1] == INF) {
			cout << "-1\n";
		}
		else {
			cout << min_distance[height - 1][width - 1] << "\n";
		}
	
	}
    

    return 0;
}

