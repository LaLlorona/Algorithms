#include <bits/stdc++.h>


using namespace std;

int len_arr, num_questions, from, to;
int input_array[2001];
bool IsPalindrome[2001][2001];
void FillIsPalindrome() {
	for (int i = 0; i < len_arr; i++) {
		IsPalindrome[i][i] = true;
		for (int j = 1; j <= min(i, len_arr - 1 - i); j++) {
			if (input_array[i - j] == input_array[i + j]) {
				IsPalindrome[i - j][i + j] = true;
			}
			else {
				break;
			}
		}
	}
	for (int i = 0; i < len_arr - 1; i++) {
		if (input_array[i] == input_array[i + 1]) {
			IsPalindrome[i][i + 1] = true;
			for (int j = 1; j <= min(i, len_arr - 2 - i); j++) {
				if (input_array[i - j] == input_array[i + 1 + j]) {
					IsPalindrome[i - j][i + 1 + j] = true;
				}
				else {
					break;
				}
			}
		}
	}
	
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	
	while (cin >> len_arr) {
		memset(IsPalindrome, 0, sizeof(IsPalindrome));
		for (int i = 0; i < len_arr; i++) {
			cin >> input_array[i];
		}
		FillIsPalindrome();
		cin >> num_questions; 
		for (int i = 0; i < num_questions; i++) {
			cin >> from >> to;
			from--;
			to--;
			cout << IsPalindrome[from][to] << "\n";
		}
		// for (int i = 0; i < len_arr; i++) {
		// 	for (int j = 0; j < len_arr; j++) {
		// 		if (IsPalindrome[i][j]) {
		// 			cout << i << "," << j << "\n";
		// 		}
		// 	}
		// }
		//cout << "\n\n";
	}
    

    return 0;
}

