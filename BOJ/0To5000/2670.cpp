#include <bits/stdc++.h>
//#include <iostream>

using namespace std;
const int MAX = 10001;
double input[MAX];
double max_until[MAX];
int num_input;

void FillMaxUntil() {
	max_until[0] = 1.0;
	for (int i = 1; i <= num_input; i++) {
		max_until[i] = max(input[i], max_until[i - 1] * input[i]);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	cout << fixed;
	cout.precision(3);
	
	while (cin >> num_input) {
		input[0] = 1.0;
		for (int i = 1; i <= num_input; i++) {
			cin >> input[i];
		}
		FillMaxUntil();
		double max_cand = 0.0;
		for (int i = 1; i <= num_input; i++) {
			max_cand = max(max_cand, max_until[i]);
		}
		cout << max_cand << "\n";
	}
	
	
	
	return 0;
}



