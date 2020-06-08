#include <bits/stdc++.h>


using namespace std;

long long n, k;


long long CalculateNumbersSmallerThan(long long pivot) { //pivot 보다 작거나 같은 수들의 개수를 return 함 
	long long ret = 0;
	for (long long i = 1; i <= n; i++) {
		ret += min(n, pivot / i);
	}
	return ret;
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
		long long  lo = 1;
		long long hi = n * n;
		long long mid;
		long long ret;
		while (lo <= hi) {
			mid = (hi + lo) / 2;
			//cout << mid << "\n";
			if (CalculateNumbersSmallerThan(mid) >= k) {
				ret = mid;
				hi = mid - 1;
			}	
			else {
				lo = mid + 1;
			}
		}
		cout << ret << "\n";
	}
    

    return 0;
}

