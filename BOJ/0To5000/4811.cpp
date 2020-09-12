#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
//const int MOD = 1000000007;


ll num_combinations[31][31];

ll CalcNumComb(int one, int half) {
    if (one == 0) {
        return 1;
    }
    else {
        ll& ret = num_combinations[one][half];
        if (ret != -1) {
            return ret;
        }
        ret = 0;
        ret += CalcNumComb(one - 1, half + 1);
        if (half > 0) {
            ret += CalcNumComb(one, half - 1);
        }
        return ret;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
    std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
//
//    std::ifstream in("in.txt");
//    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    int num;
    memset(num_combinations, -1, sizeof(num_combinations));
    while (cin >> num) {
        if (num == 0) {
            break;
        }
        else {
            cout << CalcNumComb(num, 0) << "\n";
        }
    }
    return 0;
}


