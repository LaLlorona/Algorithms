#include <bits/stdc++.h>


using namespace std;

int len_arr;
long long input_arr[200002];
const long long INF = 1987654321;

long long FindMaxAlternative() {
	int ptr = 0;
	int sign = 1;
	if (input_arr[ptr] < 0) {
		sign = -1;
	}
	long long local_max = -INF;
	long long current_sum = 0;
	while (ptr < len_arr) {
		if (ptr < len_arr - 1) {
			if (sign * input_arr[ptr] > 0) { // 현재 보고 있는 숫자와 영역의 부호가 같을때
				local_max = max(local_max, input_arr[ptr]);
				
				ptr++;
			}
			else { // 부호가 다를때
				// cout << local_max << " ";
				current_sum += local_max;
				local_max = -INF;
				sign *= -1;
			}
		}
		else {
			if (sign * input_arr[ptr] > 0) { // 계속 부호가 같을때
				local_max = max(local_max, input_arr[ptr]);
				// cout << local_max << " ";
				current_sum += local_max;
				
				ptr++;
			}
			else{ // 부호가 다를 때 
				current_sum += local_max;
				// cout << input_arr[ptr] << " ";
				current_sum += input_arr[ptr];
				ptr++;
			}
		}
	}
	// cout << "\n";
	return current_sum;
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
		cin >> len_arr;
		for (int i = 0; i < len_arr; i++) {
			cin >> input_arr[i];
		}
		cout << FindMaxAlternative() << "\n";
	}
    

    return 0;
}

