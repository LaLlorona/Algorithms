#include <bits/stdc++.h>


using namespace std;
const int MAX = 1000001;
int n, k;

int min_divisor[MAX];

void Eratosthenes() {
	int square = (int)sqrt(MAX);
	for (int i = 2; i <= square; i++) {
		if (min_divisor[i] == i) {
			for (int j = i * i; j <= MAX; j += i) {
				if (min_divisor[j] >= i) {
					min_divisor[j] = i;
				}
			}
		}
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
	for (int i = 0; i < 100001; i++) {
		min_divisor[i] = i;
	}
	Eratosthenes();
	
	// for (int i = 90000; i < 90300; i++) {
	// 	cout << min_divisor[i] << " ";
	// }
	// cout << "\n";
	// cout << "90000 min divisor is " << min_divisor[90000] << "\n";
	
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		
		cin >> n >> k;
		if (n % 2 == 0) {
			cout << n + 2 * k << "\n";
		}
		else {
			cout << n + min_divisor[n] + 2 * (k - 1) << "\n";
		}
		
	
	}
    

    return 0;
}

