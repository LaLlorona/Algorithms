#include <bits/stdc++.h>


using namespace std;

int n;
int occupied[15][15];

int dct_y[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dct_x[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int num_possible_place = 0;

bool IsInBound(int y, int x) {  
	return (y >= 0 && y < n && x >= 0 && x < n);
}

void PlaceQueen(int current_pos, int num_placed) {
	if (current_pos == n * n) {
		// for (int y = 0; y < n; y++) {
		// 	for (int x = 0; x < n; x++) {
		// 		cout << occupied[y][x] << " ";
		// 	}
		// 	cout << "\n";
		// }
		// cout << num_placed << "\n";
		if (num_placed == n) {
			num_possible_place++;
		}
		
	}
	else {
		int current_y = current_pos / n;
		int current_x = current_pos % n;
		
		if (occupied[current_y][current_x] != 0) {
			PlaceQueen(current_pos + 1, num_placed);
		}
		else {
			for (int direction = 0; direction < 8; direction++) {
				for (int dist = 0; dist <= n; dist++) {
					int next_y = current_y + dct_y[direction] * dist;
					int next_x = current_x + dct_x[direction] * dist;
					if (IsInBound(next_y, next_x)) {
						occupied[next_y][next_x]++;
					}
					
				}
			}
			
			PlaceQueen(current_pos + 1, num_placed + 1);
			
			for (int direction = 0; direction < 8; direction++) {
				for (int dist = 0; dist <= n; dist++) {
					int next_y = current_y + dct_y[direction] * dist;
					int next_x = current_x + dct_x[direction] * dist;
					if (IsInBound(next_y, next_x)) {
						occupied[next_y][next_x]--;
					}
					
				}
			}
			
			PlaceQueen(current_pos + 1, num_placed);
			
			
		}
	}
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> n) {
		
		memset(occupied, 0, sizeof(occupied));
		num_possible_place = 0;
		
		PlaceQueen(0, 0);
		cout << num_possible_place << "\n";
	}
    

    return 0;
}

