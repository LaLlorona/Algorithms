#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> pii;

const int INF = 987654321;

const int MAX = 10001;
int num_protein;
int num_bad_combinations;
map<pii, bool> bad_combinations;

bool canIDrinkWith(int a, int b) {
	if (bad_combinations.find(pii(a, b)) == bad_combinations.end()) {
		return true;
	}
	return false;
}
int numPossibleCombinations() {
	int possible_combinations = 0;
	for (int i = 1; i <= num_protein; i++) {
		for (int j = i + 1; j <= num_protein; j++) {
			if (canIDrinkWith(i, j)) {
				for (int k = j + 1; k <= num_protein; k++) {
					if (canIDrinkWith(i, k) && canIDrinkWith(j, k)) {
						possible_combinations++;
					}
				}
			}
		}
	}
	return possible_combinations;
}


int main()
{
	cin >> num_protein >> num_bad_combinations;

	for (int i = 0; i < num_bad_combinations; i++) {
		int a, b;
		cin >> a >> b;
		bad_combinations[pii(a, b)] = true;
		bad_combinations[pii(b, a)] = true;
	}

	cout << numPossibleCombinations();


	
	
	
	
	

	
	

	
	 
	 


	return 0;
}

