#include <bits/stdc++.h>


using namespace std;

string input;
int len_input;
map<char, int> frequency;


string nthBigNum(int n) {
	if (n == 1) {
		return "4";
	}
	else if (n == 2) {
		return "7";
	}
	int k_set = 0;
	int numbering = n + 1;

	for (int i = 1; i < 21; i++) {
		if (numbering < (int)(pow(2, i) + 0.5)) {
			k_set = i - 1;
			break;
		}
	}
	if (numbering < (int)(pow(2, k_set) + pow(2, k_set - 1) + 0.5)) {
		return "4" + nthBigNum(n - (int)(pow(2, k_set - 1) + 0.5));
	}
	else {
		return "7" + nthBigNum(n - (int)(pow(2, k_set) + 0.5));
	}




}
int main()
{
	
	int k;
	cin >> k;
	cout << nthBigNum(k);
	
	

	
	

	
	 
	 


	return 0;
}

