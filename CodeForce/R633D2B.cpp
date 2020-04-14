#include <bits/stdc++.h>


using namespace std;

int len_arr;
vector<int> input_arr;

void SortedAdjacentDifference() {
	if (len_arr % 2 == 1) {
		int current_ptr = len_arr / 2;
		int count = 1;
		int sign = 1;
		while (current_ptr != 0) {
			cout << input_arr[current_ptr] << " ";
			current_ptr += count * sign;
			count++;
			sign = -sign;	
		}
		cout << input_arr[current_ptr];
	}
	else {
		int current_ptr = len_arr / 2 - 1;
		int count = 1;
		int sign = 1;
		while (current_ptr != len_arr - 1) {
			cout << input_arr[current_ptr] << " ";
			current_ptr += count * sign;
			count++;
			sign = - sign;
		}
		cout << input_arr[current_ptr];
	}
	cout << "\n";
}

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
		int input_num;
		cin >> len_arr;
		input_arr.clear();
		for (int i = 0; i < len_arr; i++) {
			cin >> input_num;
			input_arr.push_back(input_num);
			
		}
		sort(input_arr.begin(), input_arr.end());
		
		
		
		SortedAdjacentDifference();
		
	} 
    

    return 0;
}

