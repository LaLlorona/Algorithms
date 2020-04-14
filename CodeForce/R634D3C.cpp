#include <bits/stdc++.h>


using namespace std;

vector<int> input_arr;
int MaxTeamMatching () {
	int num_keys = 0;
	map<int, int> occurance;
	map<int, int> :: iterator it;
	for (int i = 0; i < input_arr.size(); i++) {
		int count = 0;
		it = occurance.find(input_arr[i]);
		if (it == occurance.end()) {
			num_keys++;
			occurance[input_arr[i]] = 1;
		}
		else {
			occurance[input_arr[i]]++;
		}
		
	}
	if (input_arr.size() == 1) {
		return 0;
	}
	else{
		int max_count = 0;
		for (auto iter = occurance.begin(); iter != occurance.end(); iter++) {
			max_count = max(max_count, iter -> second);
		}
		if (num_keys - 1 >= max_count) {
			return max_count;
		}
		else {
			return min(num_keys, max_count - 1);
		}
	}
	
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	int num_testcase;
	int input_num;
	int len_arr;
	cin >> num_testcase;
	
	while (num_testcase--) {
		input_arr.clear();
		cin >> len_arr;
		for (int i = 0; i < len_arr; i++) {
			cin >> input_num;
			input_arr.push_back(input_num);
		}
		cout << MaxTeamMatching() << "\n";
		
	}
    

    return 0;
}

