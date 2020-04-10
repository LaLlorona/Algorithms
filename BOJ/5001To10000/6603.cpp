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

int choose;

vector<int> input;
vector<int> temp;
vector<vector<int> > result;

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
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> choose) {
		input.clear();
		temp.clear();
		result.clear();
		for (int i = 0; i < choose; i++) {
			int a;
			cin >> a; 
			input.push_back(a);
		}
		sort(input.begin(), input.end());
		FillResult(0, 6);
		Solve();
	}
    

    return 0;
}

