#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

int width, height, must_pass;
ll binomial_coefficient[31][31];

ll CalcBinomialCoefficient(int n, int k) {
	if (n == k || k == 0) {
		return 1;
	}
	else {
		ll& ret = binomial_coefficient[n][k];
		if (ret != -1) {
			return ret;
		}
		else {
			ret = 0;
			ret += CalcBinomialCoefficient(n - 1, k) + CalcBinomialCoefficient(n - 1, k - 1);
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
	
	while (cin >> height >> width >> must_pass) {
		memset(binomial_coefficient, -1, sizeof(binomial_coefficient));
		if (must_pass == 0) {
			cout << CalcBinomialCoefficient(height + width - 2, height - 1);
		}
		else {
			must_pass--;
			int must_pass_y = must_pass / width;
			int must_pass_x = must_pass % width;
			cout << CalcBinomialCoefficient(must_pass_y + must_pass_x, must_pass_x) * CalcBinomialCoefficient(height - 1 + width - 1 - must_pass_y - must_pass_x, height - 1 - must_pass_y) << "\n";
		}
	}
    

    return 0;
}

