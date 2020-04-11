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
int input_arr[100001];
const int INF = 987654321;

int Solve() {
	int lo = 0;
	int hi = 0;
	int min_len = INF;
	int current_sum = input_arr[0];
	while (lo <= hi && hi < len_arr) {
		if (current_sum < target_sum) {
			hi++;
			current_sum += input_arr[hi];
		}
		else if (current_sum == target_sum) {
			min_len = min(min_len, hi - lo + 1);
			hi++;
			current_sum += input_arr[hi];
		}
		else {
			min_len = min(min_len, hi - lo + 1);
			current_sum -= input_arr[lo];
			lo++;
			
		}
	}
	
	return (min_len == INF) ? 0 : min_len ;
}

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> len_arr >> target_sum) {
		for (int i = 0; i < len_arr; i++) {
			cin >> input_arr[i];
		}
		cout << Solve() << "\n";
	}
    

    return 0;
}

