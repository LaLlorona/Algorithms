#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
ll n, k;
ll MOD = 1000000007L;
ll power(ll a, ll k) {//return a^k 
	if (k == 1) {
		return a;
	}
	else if (k % 2 == 0) {
		ll mid = power(a, k / 2);
		return (mid * mid) % MOD; 
	}
	else {
		return (power(a, k - 1) * a) % MOD;
	}
}




int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	while (cin >> n >> k) {
		ll A = 1L;
		ll B = 1L;
		for (ll i = 1L; i <= n; i++) {
			A *= i;
			A = A % MOD;
		}
		for (int i = 1L; i <= k; i++) {
			B *= i;
			B = B % MOD;
		}
		for (int i = 1L; i <= (n - k); i++) {
			B *= i;
			B = B % MOD;
		}
		ll mid = A * power(B, MOD - 2);
		cout << mid % MOD << "\n";
	}
    

    return 0;
}

