#include <bits/stdc++.h>


using namespace std;

int n ,k;

int Solve() {
	vector<int> input_arr(n);
	vector<int> sum_no_change(2 * k + 1);
	vector<int> sum_one_change(2 * k + 2);
	for (int i = 0; i < n; ++i) {
		cin >> input_arr[i];
	}
	for (int i = 0 ; i < n / 2; ++i) {
		++sum_no_change[input_arr[i] + input_arr[n - 1 - i]];
	}
	for (int i = 0; i < n / 2; ++i) {
		int left_border = 1 + min(input_arr[i], input_arr[n - 1 - i]);
		int right_border = k + max(input_arr[i], input_arr[n - 1 - i]);
		++sum_one_change[left_border];
		--sum_one_change[right_border + 1];
	}
	
	for (int i = 1; i <= 2 * k + 1; i++) {
		sum_one_change[i] += sum_one_change[i - 1];
	}
	
	int min_cand = 987654321;
	for (int i = 2; i <= 2 * k; ++i) {
		min_cand = min(min_cand, sum_one_change[i] - sum_no_change[i] + 2 * (n / 2 - sum_one_change[i]));
	}
	return min_cand;
	 
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
//     std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//     std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		cin >> n >> k;
		cout << Solve() << "\n";
		
	}
    

    return 0;
}

