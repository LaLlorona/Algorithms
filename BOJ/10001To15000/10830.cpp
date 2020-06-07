#include <bits/stdc++.h>


using namespace std;

int n;
long long power;
vector<vector<int> > initial_matrix(5, vector<int> (5, 0)); 
vector<vector<int> > identity_matrix(5, vector<int> (5, 0)); 



vector<vector<int> > MaxtrixMultiply(vector<vector<int> > mat_a, vector<vector<int > > mat_b) {
	vector<vector<int> > result = vector<vector<int> >(5, vector<int> (5, 0)); 
	for (int row = 0; row < 5; row++) {
		for (int column = 0; column< 5; column++) {
			for (int item = 0; item < 5; item++) {
				result[row][column] += mat_a[row][item] * mat_b[item][column]; 
				result[row][column] %= 1000;
			}
		}
	}
	return result;
}

vector<vector<int> > MatrixPower(long long power) {
	if (power == 1) {
		return MaxtrixMultiply(initial_matrix, identity_matrix);
	}
	else {
		if (power % 2 == 0) {
			vector<vector<int> > mid_result = MatrixPower(power / 2);
			return MaxtrixMultiply(mid_result, mid_result);
		}
		else {
			return MaxtrixMultiply(initial_matrix, MatrixPower(power - 1));
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
	for (int i = 0; i < 5; i++) {
		identity_matrix[i][i] = 1;
	}


	while (cin >> n >> power) {
		initial_matrix = vector<vector<int> >(5, vector<int>(5, 0));
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cin >> initial_matrix[y][x];
			}
		}
		vector<vector<int> > result = MatrixPower(power);
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cout << result[y][x] << " ";
			}
			cout << "\n";
		}
		
		
	}
    

    return 0;
}

