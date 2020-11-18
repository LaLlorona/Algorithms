#include <bits/stdc++.h>


using namespace std;
int counter = 0;

vector<vector<int>> threeSum(vector<int>& nums) {
	set<vector<int> > result;
	vector<vector<int> > ans;
	int arr_size = nums.size();
	for (int i = 0; i < arr_size - 1; i++) {
		unordered_set<int> s;
		for (int j = i + 1; j < arr_size; j++) {
			if (s.find(-nums[i] - nums[j]) != s.end()) {
				cout << counter << "\n";
				counter++;
				vector<int> one_ans{nums[i], nums[j], 0 - nums[i] - nums[j]};
				sort(one_ans.begin(), one_ans.end());
				result.insert(one_ans);
			}
			else {
				s.insert(nums[j]);
			}
		}
	}
	for (set<vector<int> >::iterator it = result.begin(); it != result.end(); it++) {
		ans.push_back(*it);
	}
	return ans;
}




int main()
{
	
	vector<int> vect{0,0,0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	threeSum(vect);
	
    

    return 0;
}

