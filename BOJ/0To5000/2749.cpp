#include <bits/stdc++.h>


using namespace std;


long long power;
vector<vector<long long > > initial_matrix(2, vector<long long> (2, 0)); 
vector<vector<long long> > identity_matrix(2, vector<long long> (2, 0)); 



vector<vector<long long> > MaxtrixMultiply(vector<vector<long long> > mat_a, vector<vector<long long > > mat_b) {
	vector<vector<long long> > result = vector<vector<long long> >(2, vector<long long> (2, 0)); 
	for (long long row = 0; row < 2; row++) {
		for (long long column = 0; column< 2; column++) {
			for (long long item = 0; item < 2; item++) {
				result[row][column] += mat_a[row][item] * mat_b[item][column]; 
				result[row][column] %= 1000000;
			}
		}
	}
	return result;
}

vector<vector<long long> > MatrixPower(long long power) {
	if (power == 1) {
		return MaxtrixMultiply(initial_matrix, identity_matrix);
	}
	else {
		if (power % 2 == 0) {
			vector<vector<long long> > mid_result = MatrixPower(power / 2);
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
	for (int i = 0; i < 2; i++) {
		identity_matrix[i][i] = 1;
	}


	while (cin >> power) {
		initial_matrix = vector<vector<long long> >(2, vector<long long>(2, 0));
		initial_matrix[0][0] = 1;
		initial_matrix[0][1] = 1;
		initial_matrix[1][0] = 1;
		
		vector<vector<long long> > result = MatrixPower(power);
		cout << result[1][0] << "\n";
		
		
	}
    

    return 0;
}

