#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

ll total_game, won_game;

ll FindMinGame() {
	ll lo = 0;
	ll hi = 2000000000;
	ll ans = hi + 1;
	if ((won_game * 100) / total_game >= 99) {
		return -1;
	}
	else {
		while (lo <= hi) {
			ll mid = (lo + hi) / 2;
			if ((won_game * 100)/ total_game < ((won_game + mid)* 100) / (total_game + mid)) {// if win rate increase if play 'mid' number of games
				hi = mid - 1;
				ans = min(ans, mid);
			}
			else {
				lo = mid + 1;
			}
		}
	}
	return ans;
}


int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> total_game >> won_game) {
		cout << FindMinGame() << "\n";
	}
    

    return 0;
}

