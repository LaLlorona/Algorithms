#include <bits/stdc++.h>


using namespace std;

int n;
int len_arr;
int input_arr[2002];
int count_until[27][2002];

void FillCountUntil() {
	count_until[input_arr[0]][0] = 1;
	for (int i = 1; i < len_arr; i++) {
		for (int j = 1; j <= 26; j++) {
			if (input_arr[i] == j) {
				count_until[j][i] = count_until[j][i - 1] + 1;
			}
			else {
				count_until[j][i] = count_until[j][i - 1];
			}
		}
	}
}
int OccuranceOnSegment(int from, int to, int c) {
	if (from == 0) {
		return count_until[c][to];
	}
	else {
		return count_until[c][to] - count_until[c][from - 1];
	}
}

int MaximumPalindrome() {
	int max_cand = 0;
	for (int i = 1; i <= 26; i++) {
		max_cand = max(max_cand, count_until[i][len_arr - 1]);
	}
	int max_in = 0;
	int max_out = 0;
	
	for (int i = 1; i < len_arr - 1; i++) {
		for (int j = i; j < len_arr - 1; j++) {
			max_in = 0;
			max_out = 0;
			for (int c = 1; c <= 26; c++) {
				max_in = max(OccuranceOnSegment(i, j ,c) ,max_in);
				max_out = max(min(OccuranceOnSegment(0, i - 1, c), OccuranceOnSegment(j + 1, len_arr - 1, c)), max_out);
			}
			max_cand = max(max_cand, max_in + 2 * max_out);
			
		}
	}
	return max_cand;
	
}





int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		cin >> len_arr;
		memset(count_until, 0 , sizeof(count_until));
		for (int i = 0; i < len_arr; i++) {
			cin >> input_arr[i];
		}
		FillCountUntil();
		cout << MaximumPalindrome() << "\n";
	
	}
    

    return 0;
}

