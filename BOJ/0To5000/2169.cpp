#include <bits/stdc++.h>


using namespace std;

const int INF = 987654321;
int width, height;
int expedition_value[1001][1001];
int max_expedition_value[1001][1001]; // default : - INF

int dct_y[3] = {-1, 0, 0};
int dct_x[3] = {0, -1, 1};



bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 && x < width);
}

void FillMaxExpeditionValue() {
	
	max_expedition_value[0][0] = expedition_value[0][0];
	for (int x = 1; x < width; x++) {
		max_expedition_value[0][x] = max_expedition_value[0][x - 1] + expedition_value[0][x];
	}
	for (int y = 1; y < height; y++) {
		int max_cand_cache[width][2]; //0 : from left , 1 : from right
		
		for (int x = 0 ; x < width; x++) {
			max_expedition_value[y][x] = expedition_value[y][x] + max_expedition_value[y - 1][x];	
			max_cand_cache[x][0] = max_expedition_value[y][x];
			max_cand_cache[x][1] = max_expedition_value[y][x];
		}
		
		for (int x = 1 ; x < width; x++) { // from left to right
			max_cand_cache[x][0] = max(max_cand_cache[x][0], max_cand_cache[x - 1][0] + expedition_value[y][x]); 
		}
		for (int x = width - 2; x >= 0; x--) {//from right to left
			max_cand_cache[x][1] = max(max_cand_cache[x][1], max_cand_cache[x + 1][1] + expedition_value[y][x]);
		}
		for (int x = 0; x < width; x++) {
			max_expedition_value[y][x] = max(max_expedition_value[y][x], max(max_cand_cache[x][0], max_cand_cache[x][1]));
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
	
	while (cin >> height >> width) {
		
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				cin >> expedition_value[y][x];
				max_expedition_value[y][x] = -INF;
			}
		}
		FillMaxExpeditionValue();
		
		// for (int y = 0; y < height; y++) {
		// 	for (int x = 0; x < width; x++) {
		// 		cout << max_expedition_value[y][x] << " ";
				
		// 	}
		// 	cout << "\n";
		// }
		cout << max_expedition_value[height - 1][width - 1] << "\n";
	}
    

    return 0;
}

