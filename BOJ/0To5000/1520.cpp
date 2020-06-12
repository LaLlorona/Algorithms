#include <bits/stdc++.h>


using namespace std;

int height, width;
int stair[500][500];
int num_path[500][500];
int dct_y[4] = {0, 0, -1, 1};
int dct_x[4] = {-1, 1, 0, 0};

bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 && x < width);
}
int CalcNumPath(int y, int x) {
	if (!IsInBound(y, x)) {
		return 0;
	}
	int& ret = num_path[y][x];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int next_y = y + dct_y[i];
		int next_x = x + dct_x[i]; 
		if (IsInBound(next_y, next_x) && stair[next_y][next_x] > stair[y][x]) {
			ret += CalcNumPath(next_y, next_x);
		}
	}
	return ret;
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
			for (int x = 0; x < width; x++) {
				cin >> stair[y][x];
			}
		}
		memset(num_path, -1, sizeof(num_path));
		num_path[0][0] = 1;
		cout << CalcNumPath(height - 1, width - 1) << "\n";
		
		// for (int y = 0; y < height; y++) {
		// 	for (int x = 0; x < width; x++) {
		// 		cout << num_path[y][x] << " ";
		// 	}
		// 	cout << "\n";
		// }
		
		
	}
    

    return 0;
}

