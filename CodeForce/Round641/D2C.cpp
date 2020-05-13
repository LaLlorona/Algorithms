#include <bits/stdc++.h>


using namespace std;

const int MAX = 200001;
const int INF = 987654321;
bool is_prime[MAX];
int input_integers[100001];
int num_integers;

vector<int> primes(0);

void Eratosthenes() {
	int square = (int)sqrt(MAX);
	for (int i = 2; i <= square; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= MAX; j += i) {
				is_prime[j] = false;
			}
		}
	}
	for (int i = 2; i < MAX; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
		}
	}
}

long long GcdOfPairLcm() {
	long long ans = 1;
	int div_fail_count;
	int power_count;
	for (int i = 0; i < primes.size(); i++) {
		div_fail_count = 0;
		power_count = 0;
		vector<int> power_prime (0);
		for (int j = 0; j < num_integers; j++) {
			power_count = 0;
			if (div_fail_count == 2) {
				
				break;
			}
			int divided = input_integers[j];
			if (divided % primes[i] != 0) {
				div_fail_count++;
				power_prime.push_back(0);
				continue;
			}
			
			
			while (divided % primes[i] == 0) {
				power_count++;
				divided /= primes[i];
			}
			power_prime.push_back(power_count);
			
		}
		if (div_fail_count == 2) {
			continue;
		}
		// if (primes[i] == 5) {
		// 	cout << "56 is iasdf";
		// 	for (int j = 0; j < power_prime.size(); j++) {
		// 		cout << power_prime[j] << " ";
		// 	}
		// }
		sort(power_prime.begin(), power_prime.end());
		ans *= (long long) pow(primes[i], power_prime[1]);
	}
	return ans;
}

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	memset(is_prime, 1, sizeof(is_prime));
	Eratosthenes();
	// for (int i = 0; i < 10; i++) {
	// 	cout << primes[i] << " ";
	// }
	
	while (cin >> num_integers) {
		// cout << "the answer is\n";
		for (int i = 0; i < num_integers; i++) {
			cin >> input_integers[i];
		}
		cout << GcdOfPairLcm() << "\n";
		
	}
    

    return 0;
}

