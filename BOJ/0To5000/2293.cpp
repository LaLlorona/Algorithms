#include <bits/stdc++.h>
//#include <iostream>

using namespace std;

int num_combinations[10001];
int n, target_value;
int coins[101];


int main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	while (cin >> n >> target_value) {
		memset(num_combinations, 0, sizeof(num_combinations));
		for (int i = 0; i < n; i++) {
			cin >> coins[i];
		}
		num_combinations[0] = 1;
		for (int i = 1; i * coins[0] < 10001; i++) {
			num_combinations[i * coins[0]] = 1;
		}
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < 10001; j++) {
				if (j - coins[i] >= 0) {
					num_combinations[j] += num_combinations[j - coins[i]];
				}
			} 
		}
		
		cout << num_combinations[target_value] << "\n";
		
	}
	
	
	
	
	
	return 0;
}


