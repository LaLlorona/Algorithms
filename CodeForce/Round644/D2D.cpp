#include <bits/stdc++.h>


using namespace std;

int n, k;



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		cin >> n >> k;
		
	
		
		int max_iter = min(int(sqrt(n)), k);
	
		int ans = n;
		for (int i = max_iter; i >= 1; i--) {
			if (n % i == 0){
				if (i <= k) {
					ans = min(ans, n / i);
				}
				if (n / i <= k) {
					ans = min(ans, i);
				}
			}
		}	
		cout << ans << "\n";
		
	}
    

    return 0;
}

