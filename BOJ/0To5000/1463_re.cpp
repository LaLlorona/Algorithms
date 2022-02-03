
#include <bits/stdc++.h>


using namespace std;
const int MAX = 1000000 + 1;
const int INF = 987654321;
int cache[MAX];
int minOperation(int n) {
    if (n == 1) {
        return 0;
    }
    int& ret = cache[n];
    if (ret != -1) {
        return ret;
    }
    int min_cand = minOperation(n - 1) + 1;
    if (n % 2 == 0) {
        min_cand = min(min_cand, minOperation(n / 2) + 1);
    }
    if (n % 3 == 0 ) {
        min_cand = min(min_cand, minOperation(n / 3) + 1);
    }
    ret = min_cand;
    return ret;
}


int main()
{
    std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
    std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
    // std::ifstream in("in.txt");
    // std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    // std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    int input_n;
    memset(cache, -1, sizeof(cache));
    while (cin >> input_n) {
        cout << minOperation(input_n) << "\n";
    }
    return 0;
}


