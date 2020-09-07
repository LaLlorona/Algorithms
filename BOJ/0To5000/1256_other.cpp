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

string KthString(int n, int m, int skip) {
	if (n == 0) {
		return string(m, 'z');
	}
	else if (m == 0) {
		return string(n, 'a');
	}
	if (skip >= binomial_coefficient[n + m - 1][m]) {
		return "z" + KthString(n, m - 1, skip - binomial_coefficient[n + m - 1][m]);
	}
	else {
		return "a" + KthString(n - 1, m, skip);
	}
}



int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
// 	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
// 	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	CalcBino();
	
	while (cin >> num_a >> num_z >> skip) {
		if (binomial_coefficient[num_a + num_z][num_a] < skip) {
			cout << "-1\n";
		}
		else {
			skip--;
			cout << KthString(num_a, num_z, skip) << "\n";
		}
		
	}
    

    return 0;
}

