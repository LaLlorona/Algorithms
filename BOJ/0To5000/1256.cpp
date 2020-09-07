#include <bits/stdc++.h>


using namespace std;

int num_a, num_z;
int skip;
const int MAX = 1000000000 + 100;
int binomial_coefficient[201][201];

void CalcBino() {
	memset(binomial_coefficient, 0, sizeof(binomial_coefficient));
	binomial_coefficient[0][0] = 1;
	binomial_coefficient[1][1] = 1;
	binomial_coefficient[1][0] = 1;
	for (int i = 2; i <= 200; i++) {
		binomial_coefficient[i][0] = 1;
		binomial_coefficient[i][i] = 1;
		for (int j = 1; j < i; j++) {
			binomial_coefficient[i][j] = min(binomial_coefficient[i - 1][j - 1] + binomial_coefficient[i - 1][j], MAX);
		}
	}
}
void GenerateString(int n, int m, string result) {
	if (skip < 0) {
		return;
	}
	if (n == 0 && m == 0) {
		if (skip == 0) {
			cout << result << "\n";
		}
		skip--;
		return;
	}
	
	if (binomial_coefficient[n + m][m] <= skip) {
		skip -= binomial_coefficient[n + m][m];
		return;
	}
	if (n > 0) {
		GenerateString(n - 1, m , result + "a");
	}
	if (m > 0)
	{
		GenerateString(n, m - 1, result + "z");
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
	CalcBino();
	// for (int i = 0; i < 10; i++) {
	// 	for (int j = 0; j <= i; j++) {
	// 		cout << i << " " << j << " " << binomial_coefficient[i][j] << "\n";
	// 	}
	// }
	while (cin >> num_a >> num_z >> skip) {
		if (binomial_coefficient[num_a + num_z][num_a] < skip) {
			cout << "-1\n";
		}
		else {
			skip--;
			GenerateString(num_a, num_z, "");
		}
		
	}
    

    return 0;
}

