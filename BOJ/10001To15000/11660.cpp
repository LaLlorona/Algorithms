#include <bits/stdc++.h>


using namespace std;

int board_size;
int num_query;
int input_arr[1025][1025];
int square_sum[1025][1025];



int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> board_size >> num_query) {
	
		memset(square_sum, 0, sizeof(square_sum));
		
		for (int y = 0; y < board_size; y++) {
			for (int x = 0; x < board_size; x++) {
				cin >> input_arr[y][x];
			}
		}
		
		square_sum[0][0] = input_arr[0][0];
		
		for (int i = 1; i < board_size; i++) {
			square_sum[0][i] = square_sum[0][i - 1] + input_arr[0][i]; 
			square_sum[i][0] = square_sum[i - 1][0] + input_arr[i][0];
		}
		
		for (int y = 1; y < board_size; y++) {
			for (int x = 1; x < board_size; x++) {
				square_sum[y][x] = square_sum[y - 1][x] + square_sum[y][x - 1] - square_sum[y - 1][x - 1] + input_arr[y][x];
			}
		}
		
		// for (int y = 0; y < board_size; y++) {
		// 	for (int x = 0; x < board_size; x++) {
		// 		cout << square_sum[y][x] << " ";
		// 	}
		// 	cout << "\n";
		// }
		
		for (int i = 0; i < num_query; i++) {
			int y1, x1, y2, x2;
			cin >> y1 >> x1 >> y2 >> x2;
			y1--;
			x1--;
			y2--;
			x2--;
			if (y1 == 0 && x1 == 0) {
				//cout << "case 1\n";
				cout << square_sum[y2][x2] << "\n";
			}
			else if (y1 == 0) {
				//cout << "case 2\n";
				cout << square_sum[y2][x2] - square_sum[y2][x1 - 1] << "\n";
			}
			else if (x1 == 0) {
				//cout << "case 3\n";
				cout << square_sum[y2][x2] - square_sum[y1 - 1][x2] << "\n";
			}
			else {
				//cout << "case 4\n";
				cout << square_sum[y2][x2] - square_sum[y2][x1 - 1] - square_sum[y1 - 1][x2] + square_sum[y1 - 1][x1 - 1] << "\n";
				//cout << square_sum[y2][x2] << " " << square_sum[y2][x1 - 1] << " " << square_sum[y1 - 1][x2] << " " << square_sum[y1 - 1][x1 - 1] << "\n";
			}
		}
	}
	
	
    

    return 0;
}

