#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
const int MAX = 100001;
ll max_time;
ll num_friends, num_checkpoint;
ll time_check[MAX];

bool PossibleToPassWithin(ll second) {
	ll people_checked = 0;
	for (int i = 0; i < num_checkpoint; i++) {
		people_checked += second / time_check[i];
	}
	return (people_checked >= num_friends);
}
ll BinarySearch() {
	ll lo = 0;
	ll hi = max_time * num_friends;	
	ll ans = 0;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (PossibleToPassWithin(mid)) {
			ans = mid;
			hi = mid - 1;
		} 
		else {
			lo = mid + 1;
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
	
	while (cin >> num_checkpoint >> num_friends) {
		max_time = 0;
		for (int i = 0; i < num_checkpoint; i++) {
			cin >> time_check[i];
			max_time = max(max_time, time_check[i]);
		}
		cout << BinarySearch() << "\n";
	}
    

    return 0;
}

