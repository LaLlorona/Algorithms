#include <bits/stdc++.h>


using namespace std;

int n;
int left_operators[4];
vector<int> input_nums;
stack<int> mid_result;
const int INF = 1987654321;
int min_cand;
int max_cand;

void UpdateMinMax(int num_used_operators) {
	if (num_used_operators == n - 1) {
		int ret = mid_result.top();
		min_cand = min(min_cand, ret);
		max_cand = max(max_cand, ret);
	}
	else {
		for (int i = 0; i < 4; i++) {
			int first_num;
			int second_num;
			if (left_operators[i] > 0) {
				first_num = mid_result.top();
				mid_result.pop();
				second_num = mid_result.top();
				mid_result.pop();
				if (i == 0) {
					mid_result.push(first_num + second_num);
				}
				if (i == 1) {
					mid_result.push(first_num - second_num);
				}
				if (i == 2) {
					mid_result.push(first_num * second_num);
				}
				if (i == 3) {
					mid_result.push(first_num / second_num);
				}
				left_operators[i]--;
				UpdateMinMax(num_used_operators + 1);
					
				mid_result.pop();
				mid_result.push(second_num);
				mid_result.push(first_num);
				left_operators[i]++;
			}
		}
	}
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	
	while (cin >> n) {
		int input_num;
		memset(left_operators, 0, sizeof(left_operators));
		input_nums.clear();
		
		for (int i = 0; i < n; i++) {
			cin >> input_num;
			input_nums.push_back(input_num);
		}
		
		while(!mid_result.empty() ) mid_result.pop();
		
		for (int i = input_nums.size() - 1; i >= 0; i--) {
			mid_result.push(input_nums[i]);
		}
		min_cand = INF;
		max_cand = -INF;
		
		for (int i = 0; i < 4; i++) {
			cin >> left_operators[i];
		}
		UpdateMinMax(0);
		cout << max_cand << "\n" << min_cand << "\n";
	
	}
    

    return 0;
}

