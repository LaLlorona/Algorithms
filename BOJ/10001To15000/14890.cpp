#include <bits/stdc++.h>


using namespace std;

int n;
int input_map[110][110];
int len_ramp;
int road[110];
int built[110];

bool CheckOneLine() {
	bool possible = true;
	int i = 0;
	// for (int j = 0; j < n; j++) {
	// 	cout << road[j] << " ";
	// }
	// cout << "\n";
	for (int j = 0; j < n - 1; j++) {
		if (abs(road[j] - road[j + 1]) > 1) {
			return false;
		}
	}
	// cout << "left to right scan\n";
	while (i < n - 1 && possible) {
		if (road[i] - road[i + 1] == 1) { // building a ramp on the right side
			for (int j = i + 1; j <= i + len_ramp; j++) {
				if (j >= n) { // out of range
					possible = false;
					break;
					
				}
				else if (built[j] || road[j] != road[i + 1]) { // height is different or already ramp is built
					possible = false;
					break;
					
				}
				else { // possible to build
					built[j] = true;
				}
			}
			i += len_ramp;
		}
		else{
			i++;
		}
	}
	i = n - 1;
	// cout << "right to left scan\n";
	while (i > 0 && possible) {
		if (road[i] - road[i - 1] == 1) { // building a ramp on the left
			for (int j = i - 1; j >= i - len_ramp; j--) {
				if (j < 0) { // out of range
					possible = false;
					break;
					
				}
				else if (built[j] || road[j] != road[i - 1]) { // height is different or already ramp is built
					possible = false;
					break;
					
				}
				else { // possible to build
					built[j] = true;
				}
			}
			i -= len_ramp;
		}
		else{
			i--;
		}
	}
	return possible;
}

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	
// 	std::ifstream in("in.txt");
// 	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
// 	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	
	while (cin >> n >> len_ramp) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cin >> input_map[y][x];
			}
		}
		
		int passing_road = 0;
		for (int y = 0; y < n; y++) {
			memset(road, 0, sizeof(road));
			memset(built, 0 ,sizeof(built));
			for (int x = 0; x < n; x++) {
				road[x] = input_map[y][x];
			}
			
			if (CheckOneLine()) {
				// for (int x = 0; x < n; x++) {
				// 	cout << road[x] << " ";
				// }
				// cout << "\n";
				passing_road++;
			}
		}
		
		for (int x = 0; x < n; x++) {
			memset(road, 0, sizeof(road));
			memset(built, 0 ,sizeof(built));
			for (int y = 0; y < n; y++) {
				road[y] = input_map[y][x];
			}
			if (CheckOneLine()) {
				// for (int x = 0; x < n; x++) {
				// 	cout << road[x] << " ";
				// }
				// cout << "\n";
				passing_road++;
			}
		}
		cout << passing_road << "\n";
		
	}
    

    return 0;
}

