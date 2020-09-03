#include <bits/stdc++.h>


using namespace std;

const int MAX = 31;
int left_border, right_border;
int num_combinations[31][31]; // when ith site on the left_border and jth site on the right_border is chosen, the total possible combination is [i][j] 

int BinomialCoefficient(int N, int K) {
	if (K == 1) {
		return N;
	}
	else if (N == K) {
		return 1;
	}
	else {
		int& ret = num_combinations[N][K];
		if (ret != -1) {
			return ret;
		}
		else {
			ret = BinomialCoefficient(N - 1, K) + BinomialCoefficient(N - 1, K - 1);
			return ret;
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
	
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		cin >> left_border >> right_border;
		memset(num_combinations, -1, sizeof(num_combinations));
		
		cout << BinomialCoefficient(right_border, left_border) << "\n";
	}
    

    return 0;
}

