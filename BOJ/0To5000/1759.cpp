#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <map>


using namespace std;

int L, C;

vector<char> input;
vector<char> temp;
vector<vector<char> > result;

void FillResult(int current_index, int remain_num) {
	if (remain_num == 0) {
		result.push_back(temp);
	}
	else if (remain_num != 0 && current_index >= input.size()) {
		
	}
	else{
		temp.push_back(input[current_index]);
		FillResult(current_index + 1, remain_num - 1);
		temp.pop_back();
		FillResult(current_index + 1, remain_num);
	}
} 
void Solve() {
	int num_consonant = 0;
	int num_vowel = 0;
	for (int i = 0; i < result.size(); i++) {
		num_vowel = 0;
		num_consonant = 0;
		for (int j = 0; j < result[i].size(); j++) {
			if (result[i][j] == 'a' || result[i][j] == 'e' || result[i][j] == 'i' || result[i][j] == 'o' || result[i][j] == 'u') {
				num_vowel++;
			}
			else {
				num_consonant++;
			}
		}
		if (num_consonant >= 2 && num_vowel >= 1) {
			for (int j = 0; j < result[i].size(); j++) {
				cout << result[i][j];
			}
			cout << "\n";
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
	
	while (cin >> L >> C) {
		input.clear();
		temp.clear();
		result.clear();
		for (int i = 0; i < C; i++) {
			char a;
			cin >> a; 
			input.push_back(a);
		}
		sort(input.begin(), input.end());
		FillResult(0, L);
		Solve();
	}
    

    return 0;
}

