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

int len_arr, target_sum;
int input_arr[10001];

int Solve() {
	int ret = 0;
	int current_sum;
	for (int i = 0; i < len_arr; i++) {
		current_sum = 0;
		for (int j = 0; j + i < len_arr; j++) {
			current_sum += input_arr[i + j];
			if (current_sum > target_sum) {
				break;
			}
			else if (current_sum == target_sum) {
				ret++;
				break;
			}
		}
	} 
	return ret;
}

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> len_arr >> target_sum) {
		for (int i = 0; i < len_arr; i++) {
			cin >> input_arr[i];
		}
		cout << Solve() << "\n";
	}
    

    return 0;
}

