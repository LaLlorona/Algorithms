#include <bits/stdc++.h>


using namespace std;
const int MAX = 100001;

int max_increasing_sequence[MAX];
int max_decreasing_sequence[MAX];
int input_sequence[MAX];
int num_input;

int FillMaxSequence() {
	int ret = 1;
	max_increasing_sequence[0] = 1;
	max_decreasing_sequence[0] = 1;
	for (int i = 1; i < num_input; i++) {
		if (input_sequence[i] >= input_sequence[i - 1]) {
			max_increasing_sequence[i] = max_increasing_sequence[i - 1] + 1;
		}
		else {
			max_increasing_sequence[i] = 1;
		}
		
		if (input_sequence[i] <= input_sequence[i - 1]) {
			max_decreasing_sequence[i] = max_decreasing_sequence[i - 1] + 1;	
		}
		else {
			max_decreasing_sequence[i] = 1;
		}
		ret = max(ret, max(max_decreasing_sequence[i], max_increasing_sequence[i]));
	}
	return ret;
}



int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_input) {
		for (int i = 0; i < num_input; i++) {
			cin >> input_sequence[i];
		}
		if (num_input == 0) {
			cout << "0\n";
		}
		else {
			cout << FillMaxSequence() << "\n";
		}
		
		// for (int i = 0; i < num_input; i++) {
		// 	cout << max_increasing_sequence[i] << " ";
		// }
		// cout << "\n";
		// for (int i = 0; i < num_input; i++) {
		// 	cout << max_decreasing_sequence[i] << " ";
		// }
	}
    

    return 0;
}

