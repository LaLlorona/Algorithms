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



using namespace std;
vector<vector<int> > permutations;
vector<int> temp;
vector<int> input_array;
bool chosen[8];
int N;

void FillPermutation(int k) {
	if (k == N) {
		permutations.push_back(temp);
	}
	else{
		for (int i = 0; i < N; i++) {
			if (!chosen[i]) {
				temp.push_back(i);
				chosen[i] = true;
				FillPermutation(k + 1);
				chosen[i] = false;
				temp.pop_back();
			}
		}
	}
}

int Solve() {
	int max_candidate = 0;
	for (int i = 0; i < permutations.size(); i++) {
		int temp = 0;
		for (int j = 0; j < input_array.size() - 1; j++) {
			temp += abs(input_array[permutations[i][j]] - input_array[permutations[i][j + 1]]);
		}
		max_candidate = max(max_candidate, temp);
	}
	return max_candidate;
	
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> N) {
		int input_num;
		permutations.clear();
		temp.clear();
		input_array.clear();
		memset(chosen, 0 ,sizeof(chosen));
		
		for (int i = 0; i < N; i++) {
			cin >> input_num;
			input_array.push_back(input_num);
		}
		FillPermutation(0);
		// for (int i = 0; i < permutations.size(); i++) {
		// 	for (int j = 0; j < permutations[0].size(); j++) {
		// 		cout << permutations[i][j];
		// 	}
		// 	cout << " ";
		// }
		cout << Solve() << "\n";
	
	}
    

    return 0;
}

