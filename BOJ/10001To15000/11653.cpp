#include <bits/stdc++.h>


using namespace std;

const int MAX = 10000000;
bool is_prime[MAX + 1];
int min_divisor[MAX + 1];

void Eratosthenes() {
	int square = (int)sqrt(MAX);
	for (int i = 2; i <= square; i++) {
		if (is_prime[i]) {
			min_divisor[i] = i;
			for (int j = i * i; j <= MAX; j += i) {
				is_prime[j] = false;
				if (min_divisor[j] == 1) {
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
	int n;

	for (int i = 0; i < MAX + 1; i++) {
		is_prime[i] = true;
		min_divisor[i] = 1;
	}
	Eratosthenes();
	for (int i = 0; i < MAX + 1; i++) {
		if (is_prime[i]) {
			min_divisor[i] = i;
		}
	}
	while (cin >> n) {
		int current_num = n;
		//cout << n << "\n";
		while (current_num != 1) {
			//cout << current_num << "\n";
			cout << min_divisor[current_num] << "\n";
			
			current_num = current_num / min_divisor[current_num];
		}
		
	}
    //cout << min_divisor[9999999] << "\n";

    return 0;
}

