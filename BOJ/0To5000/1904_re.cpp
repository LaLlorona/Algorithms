
#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
const int MAX = 1000001;
const ll MOD = 15746;

ll cache[MAX];

ll fiboMod(int x) {
    if (x == 1) {
        return 1;
    }
    else if (x == 2) {
        return 2;
    }

    if (cache[x] != -1) {
        return cache[x];
    }

    ll& ret = cache[x];

    ret = (fiboMod(x - 1) + fiboMod(x - 2)) % MOD;
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

    int N;
    memset(cache, -1, sizeof(cache));
    while (cin >> N) {
        cout << fiboMod(N) <<"\n";
    }
    return 0;
}


