#include <bits/stdc++.h>

using namespace std;

const int MOD = 15746;

const int MAX = 1000003;
int cache[MAX];

int N;

int CalcTile(int n) {
    if (n == 1) {
        return 1;
    }

    else if (n == 2) {
        return 2;
    }

    int& ret = cache[n];

    if (ret != -1) {
        return ret;
    }

    ret = (CalcTile(n - 1) + CalcTile(n - 2)) % MOD;

    return ret;
}

int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    // std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); 
	// std::cin.rdbuf(in.rdbuf()); 

    memset(cache, -1, sizeof(cache));

    while (cin >> N) {
        cout << CalcTile(N) << "\n";
    }

}
