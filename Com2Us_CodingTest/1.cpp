#include <bits/stdc++.h>


using namespace std;

string input;
int len_input;
map<char, int> frequency;


char FindMaxFrequency() {
	char max_cand = ' ';
	int max_frequency = -1;
	int counter = 0;

	for (map<char, int>::iterator it = frequency.begin(); it != frequency.end(); it++) {
		if (it->second > max_frequency) {
			max_cand = it->first;
			max_frequency = it->second;
		}
	}
	for (map<char, int>::iterator it = frequency.begin(); it != frequency.end(); it++) {
		if (it->second == max_frequency) {
			counter++;
		}
		
	}
	if (counter >= 2) {
		return '?';
	}

	else {
		return toupper(max_cand);
	}

}

int main()
{
	cin >> input;
	len_input = input.length();
	for (int i = 0; i < len_input; i++) {
		char current = tolower(input[i]);
		if (frequency.find(current) == frequency.end()) {
			frequency[current] = 1;
		}
		else {
			frequency[current]++;
		}
	}

	cout << FindMaxFrequency();
	
	
	

	
	 
	 


	return 0;
}

