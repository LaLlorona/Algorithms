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

vector<int> input;
int target_sum;
int result = 0;

void NumberOfSum(int current_index, int current_sum) {
	if (current_index >= input.size()) {
		
	}
	else if (current_sum + input[current_index] == target_sum) {
		result++;
		NumberOfSum(current_index + 1, current_sum + input[current_index]);
		NumberOfSum(current_index + 1, current_sum);
	}
	else{
		NumberOfSum(current_index + 1, current_sum + input[current_index]);
		NumberOfSum(current_index + 1, current_sum);
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
	
	int numbers;
	
	while (cin >> numbers >> target_sum) {
		input.clear();
		for (int i = 0; i < numbers; i++) {
			int a;
			cin >> a;
			input.push_back(a);
		}
		result = 0;
		NumberOfSum(0, 0);
		cout << result << "\n";
	
	}
    

    return 0;
}

