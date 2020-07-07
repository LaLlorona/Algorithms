#include <bits/stdc++.h>


using namespace std;

const int INF = 987654321;
int num_matrix;
int matrix_dimension[501][2];
int min_multiplication[501][501];

int MultiFromTo(int from, int to) {
	if (from == to) {
		return 0;
	}
	else if (to == from + 1) {
		return matrix_dimension[from][0] * matrix_dimension[from][1] * matrix_dimension[to][1];
	}
	else {
		int& ret = min_multiplication[from][to];
		if (ret != -1) {
			return ret;
		}
		ret = INF;
		for (int mid = from; mid < to; mid++) {
			int first_matrix_row = matrix_dimension[from][0];
			int second_matrix_column = matrix_dimension[to][1];
			ret = min(ret, MultiFromTo(from, mid) + MultiFromTo(mid + 1, to) +  first_matrix_row * matrix_dimension[mid][1] * second_matrix_column);
		}
		return ret;
		
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
	
	while (cin >> num_matrix) {
		int row, column;
		memset(min_multiplication, -1, sizeof(min_multiplication));
		for (int i = 0; i < num_matrix; i++) {
			cin >> row >> column;
			matrix_dimension[i][0] = row;
			matrix_dimension[i][1] = column;
		}
		cout << MultiFromTo(0, num_matrix - 1) << "\n";
		
		
	}
    

    return 0;
}

