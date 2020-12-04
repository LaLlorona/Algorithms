#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

ll total_sum;


ll FindMaxNum(ll sum) {
	ll lo = 0;
	ll hi = 200000;
	ll max_cand = 0;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (mid * (mid + 1) / 2 > sum) { // sum from 1 to mid is bigger than sum. we need to reduce the number
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
			max_cand = mid;
		}
	}
	return max_cand;
}


int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> total_sum) {
		cout << FindMaxNum(total_sum) << "\n";
	}
	
    

    return 0;
}

