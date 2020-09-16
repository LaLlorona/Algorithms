#include <bits/stdc++.h>
//#include <iostream>

using namespace std;
int num_sinker;
int num_target;
int weights[31];
int possible_to_measure[120000][31];

int PossibleToMeasure(int current_weight, int current_sinker) {
	if (current_sinker == num_sinker) {
		if (current_weight != 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
	if (current_weight == 0) {
		return 1;
	}
	int& ret = possible_to_measure[current_weight + 60000][current_sinker];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	ret |= PossibleToMeasure(current_weight - weights[current_sinker], current_sinker + 1);
	ret |= PossibleToMeasure(current_weight + weights[current_sinker], current_sinker + 1);
	ret |= PossibleToMeasure(current_weight, current_sinker + 1);
	return ret;
}
int main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	while (cin >> num_sinker) {
		memset(possible_to_measure, -1, sizeof(possible_to_measure));
		for (int i = 0; i < num_sinker; i++) {
			cin >> weights[i];
		}
		cin >> num_target;
		for (int i = 0; i < num_target; i++) {
			int target_weight;
			cin >> target_weight;
			if (PossibleToMeasure(target_weight, 0) == 0) {
				cout << "N" << " ";
			}
			else {
				cout << "Y" << " ";
			}
			
		}
	}
	
	
	
	return 0;
}



