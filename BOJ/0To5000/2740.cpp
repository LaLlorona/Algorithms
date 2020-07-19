#include <bits/stdc++.h>


using namespace std;

int col_a, row_a, col_b, row_b;
int mat_a[100][100];
int mat_b[100][100];
int mat_mult[100][100];



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	while (cin >> col_a >> row_a) {
		memset(mat_mult, 0, sizeof(mat_mult));
		for (int y = 0; y < col_a; y++) {
			for (int x = 0; x < row_a; x++) {
				cin >> mat_a[y][x];
			}
		}
		cin >> col_b >> row_b;
		for (int y = 0; y < col_b; y++) {
			for (int x = 0; x < row_b; x++) {
				cin >> mat_b[y][x];
			}
		}
		for (int i = 0; i < col_a; i++) {
			for (int j = 0; j < row_b; j++) {
				for (int k = 0; k < row_a; k++) {
					mat_mult[i][j] += mat_a[i][k] * mat_b[k][j];
				}
			}
		}
		for (int i = 0; i < col_a; i++) {
			for (int j = 0 ; j < row_b; j++) {
				cout << mat_mult[i][j] << " ";
			}
			cout << "\n";
		}
	}
    

    return 0;
}

