#include <bits/stdc++.h>


using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> is_seen;
	vector<int> result;
	for (int i = 0; i < nums.size(); i++) {
		is_seen[nums[i]] = i; //number, index
	}
	for (int i = 0; i < nums.size(); i++) {
		if (is_seen.find(target - nums[i]) != is_seen.end() && is_seen[target - nums[i]] != i) {
			result.push_back(i);
			result.push_back(is_seen[target - nums[i]]);
			return result;
		}
	}
	return result;
}
 
void PrintVector(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}




int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	vector<int> test;
	test.push_back(2);
	test.push_back(7);
	test.push_back(11);
	test.push_back(15);
	vector<int> result;
	result = twoSum(test, 9);
	PrintVector(result);
	
    

    return 0;
}

