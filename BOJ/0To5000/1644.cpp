#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <map>


using namespace std;

int target_sum;
const int MAX_num = 4000010;

bool IsPrime[MAX_num + 1];
vector<int> primes;

void FillIsPrime() {
	memset(IsPrime, 1, sizeof(IsPrime));
	primes.clear();
	IsPrime[0] = false;
	IsPrime[1] = false;
	
	for (int i = 2; i <= int(sqrt(MAX_num)); i++) {
		if (IsPrime[i]) {
			for (int j = i * i; j <= MAX_num; j += i) {
				IsPrime[j] = false;
			}
		}
	}
	for (int i = 0; i < MAX_num + 1; i++) { 
		if (IsPrime[i]) {
			primes.push_back(i);
		}
	}
}
int PossibleToMakeTargetSum() {
	int lo = 0;
	int hi = 0;
	int current_sum = primes[0];
	int match = 0;
	while (lo <= hi && hi < primes.size()) {
		if (current_sum < target_sum) {
			hi++;
			current_sum += primes[hi];
		}
		else if (current_sum == target_sum) {
			match++;
			
			hi++;
			current_sum += primes[hi];
		}
		else {
			current_sum -= primes[lo];
			lo++;
		}
	}
	return match;
}


int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	
	
	FillIsPrime();
	
	while(cin >> target_sum) {
		cout << PossibleToMakeTargetSum() << "\n";
	}
	
	
    

    return 0;
}

