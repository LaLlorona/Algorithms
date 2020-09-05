#include <bits/stdc++.h>


using namespace std;

int num_line;

int current_max_score[3];
int current_min_score[3];

int before_max_score[3];
int before_min_score[3];

int current_input_score[3];



int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
//     std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//     std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_line) {
		for (int j = 0; j < 3; j++) {
			cin >> current_input_score[j];
			current_max_score[j] = current_input_score[j];
			current_min_score[j] = current_input_score[j];
			before_min_score[j] = current_input_score[j];
			before_max_score[j] = current_input_score[j];
		}
		for (int i = 1; i < num_line; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> current_input_score[j];
			}
			current_max_score[0] = max(before_max_score[0], before_max_score[1]) + current_input_score[0];
			current_max_score[1] = max(max(before_max_score[0], before_max_score[1]), before_max_score[2]) + current_input_score[1];
			current_max_score[2] = max(before_max_score[1], before_max_score[2]) + current_input_score[2];
			
			current_min_score[0] = min(before_min_score[0], before_min_score[1]) + current_input_score[0];
			current_min_score[1] = min(min(before_min_score[0], before_min_score[1]), before_min_score[2]) + current_input_score[1];
			current_min_score[2] = min(before_min_score[1], before_min_score[2]) + current_input_score[2];
			
			
			for (int j = 0; j < 3; j++) {
				before_max_score[j] = current_max_score[j];
				before_min_score[j] = current_min_score[j];
			}
		}
		cout << max(max(current_max_score[0], current_max_score[1]), current_max_score[2]) << " " << min(min(current_min_score[0], current_min_score[1]), current_min_score[2]) << "\n";
	}
    

    return 0;
}

