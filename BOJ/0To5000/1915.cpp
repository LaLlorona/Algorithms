#include <bits/stdc++.h>


using namespace std;

int height, width;
int board[1001][1001];
int max_square_size[1001][1001];



int dct_y[2] = {0, -1};
int dct_x[2] = {-1, 0};


bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 && x < width);
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
		int ret = 0;
		for (int y = 0; y < height; y++) {
			string one_line;
			cin >> one_line;
			for (int x = 0; x < width; x++) {
				board[y][x] = one_line[x] - '0';
				if (board[y][x] == 1) {
					max_square_size[y][x] = 1;
					ret = 1;
				}
				else {
					max_square_size[y][x] = 0;
				}
			}
			
		}
	
		
		for (int y = 1; y < height; y++) {
			for (int x = 1; x < width; x++) {
				if (board[y][x] == 1) {
					max_square_size[y][x] = 1 + min(max_square_size[y - 1][x - 1], min(max_square_size[y - 1][x], max_square_size[y][x - 1]));
					ret = max(ret, max_square_size[y][x]);
				}
			}
		}
		cout << ret * ret << "\n";
	}
    

    return 0;
}

