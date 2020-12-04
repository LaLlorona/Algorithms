#include <bits/stdc++.h>


using namespace std;


const int MAX = 100001;
int len_arr;
int input_arr[MAX];



int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> len_arr) {
		for (int i = 0; i < len_arr; i++) {
			cin >> input_arr[i];
		}
		sort(input_arr, input_arr + len_arr);
		int left_ptr = 0; 
		int right_ptr = len_arr - 1;
		int current_sum = 2000000000 + 1;
		int left_cand = -1;
		int right_cand = -1;
		bool found = false;
		while (left_ptr < right_ptr) {
			if (input_arr[left_ptr] + input_arr[right_ptr] < 0) {
				if (abs(input_arr[left_ptr] + input_arr[right_ptr]) < current_sum) {
					left_cand = input_arr[left_ptr];
					right_cand = input_arr[right_ptr];
					current_sum = abs(input_arr[left_ptr] + input_arr[right_ptr]);
				}
				left_ptr++;
				
			}
			else if (input_arr[left_ptr] + input_arr[right_ptr] > 0) {
				if (abs(input_arr[left_ptr] + input_arr[right_ptr]) < current_sum) {
					left_cand = input_arr[left_ptr];
					right_cand = input_arr[right_ptr];
					current_sum = abs(input_arr[left_ptr] + input_arr[right_ptr]);
				}
				right_ptr--;
			}
			else {
				found = true;
				cout << input_arr[left_ptr] << " " << input_arr[right_ptr] << "\n";
				break;
			}
		}
		if (!found) {
			cout << left_cand << " " << right_cand << "\n";
		}
	}
    

    return 0;
}

