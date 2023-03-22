#include <bits/stdc++.h>

using namespace std;

int numStairs;
const int MAX = 301;
int score[MAX];
int cache[MAX];

int maxScore(int n) {
	if (n == 0) {
		return score[0];
	}
	else if (n == 1) {
		return score[1] + score[0];
	}
	else if (n == 2) {
		return max(score[1], score[0]) + score[2];
	}

	int& ret = cache[n];
	if (ret != -1) {
		return ret;
	}

	return ret = max(maxScore(n - 2), maxScore(n - 3) + score[n-1]) + score[n];
}

int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    // std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); 
	// std::cin.rdbuf(in.rdbuf()); 

	while (cin >> numStairs) {
		memset(cache, -1, sizeof(cache));
		for (int i = 0 ; i < numStairs; i++) {
			cin >> score[i];
		}

		cout << maxScore(numStairs - 1) << "\n";


	}

}


  