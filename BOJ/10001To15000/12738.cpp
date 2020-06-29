#include <bits/stdc++.h>

using namespace std;

int len_arr;
int main() {
	
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> len_arr) {
		vector<int> LIS;
		int num;
		for (int i = 0; i < len_arr; i++) {
			cin >> num;
			if (i == 0 || LIS.back() < num) {
				LIS.push_back(num);
			}
			else {
				vector<int>:: iterator iter = lower_bound(LIS.begin(), LIS.end(), num);
				*iter = num;
			}
		}
		cout << LIS.size() << "\n";
		// for (int i = 0; i < LIS.size(); i++) {
		// 	cout << LIS[i] << " ";
		// }
	}
	
	
	
	
	return 0;
}



