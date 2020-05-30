#include <bits/stdc++.h>


using namespace std;

int n;

vector<int> input_nums;

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		cin >> n;
		input_nums.clear();
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			input_nums.push_back(num);
		}
		int num_odds = 0;
		int num_evens = 0;
		for (int i = 0; i < n; i++) {
			if (input_nums[i] % 2 == 0) {
				num_evens++;
			}
			else {
				num_odds++;
			}
		}
		if (num_odds % 2 != num_evens % 2) {
			cout << "NO\n";
		}
		else {
			if (num_odds % 2 == 0 && num_evens % 2 == 0) {
				cout << "YES\n";
			}
			else {
				bool found = false;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (i != j && abs(input_nums[i] - input_nums[j]) == 1) {
							found = true;
						}
					}
				}
				if (found) {
					cout << "YES\n";
				}
				else {
					cout << "NO\n";
				}
			}
		}
		
	}
    

    return 0;
}

