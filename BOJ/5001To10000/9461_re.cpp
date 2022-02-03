
#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
const int MAX = 101;


ll cache[MAX];

ll padovan(int x) {
    if (x == 1 || x == 2 || x == 3) {
        return 1;
    }

    else if (x == 4 || x == 5) {
        return 2;
    }
    

    ll& ret = cache[x];

    if (ret != -1) {
        return ret;
    }

    ret = padovan(x - 1) + padovan(x-5);
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

    int num_testcase;
    cin >> num_testcase;
    int N;
    memset(cache, -1, sizeof(cache));
    while (num_testcase--) {
        cin >> N;
        cout << padovan(N) <<"\n";
    }
    return 0;
}


