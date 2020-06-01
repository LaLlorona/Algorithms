#include <bits/stdc++.h>


using namespace std;

const int MAX = 1000000;
const int MOD = 15746;
int n;
int num_combinations[MAX + 1];




int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	memset(num_combinations, 0, sizeof(num_combinations));
	
	
	num_combinations[1] = 1;
	num_combinations[2] = 2;
	for (int i = 3; i < MAX + 1; i++) {
		num_combinations[i] = (num_combinations[i - 2] + num_combinations[i - 1]) % MOD;
	}
	while (cin >> n) {
		cout << num_combinations[n] << "\n";
	}
    

    return 0;
}

