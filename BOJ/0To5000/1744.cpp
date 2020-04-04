#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>



using namespace std;

int n;

vector<int> positive_nums; // also contains 0
vector<int> ones;
vector<int> negative_nums;


void PreProcess() {
	positive_nums.clear();
	negative_nums.clear();
	int input_num;
	for (int i = 0; i < n; i++) {
		cin >> input_num;
		if (input_num > 1) {
			positive_nums.push_back(input_num);
		}
		else if (input_num == 1) {
			ones.push_back(input_num);
		}
		else{
			negative_nums.push_back(input_num);
		}
	}
}
long long MaxSums() {
	long long total = 0;
	sort(positive_nums.begin(), positive_nums.end(), greater<int>());
	sort(negative_nums.begin(), negative_nums.end());
	
	if (positive_nums.size() % 2 == 0) {
		for (int i = 0; i < positive_nums.size() / 2; i++) {
			long long first = positive_nums[2 * i];
			long long second = positive_nums[2 * i + 1];
			total += first * second;
		}
	}
	if (positive_nums.size() % 2 == 1) {
		for (int i = 0; i < positive_nums.size() / 2; i++) {
			long long first = positive_nums[2 * i];
			long long second = positive_nums[2 * i + 1];
			total += first * second;
		}
		total += positive_nums.back();
	}
	
	if (negative_nums.size() % 2 == 0) {
		for (int i = 0; i < negative_nums.size() / 2; i++) {
			long long first = negative_nums[2 * i];
			long long second = negative_nums[2 * i + 1];
			total += first * second;
		}
		
	}
	
	if (negative_nums.size() % 2 == 1) {
		for (int i = 0; i < negative_nums.size() / 2; i++) {
			long long first = negative_nums[2 * i];
			long long second = negative_nums[2 * i + 1];
			total += first * second;
		}
		total += negative_nums.back();
	}
	total += ones.size();
	return total;
	
}
int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> n) {
		PreProcess();
		cout << MaxSums() << endl;
	}
    

    return 0;
}

