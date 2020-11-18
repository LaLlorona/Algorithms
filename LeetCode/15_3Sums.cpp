#include <bits/stdc++.h>


using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int> > result;
	result.clear();
	sort(nums.begin(), nums.end());
	int len_arr = nums.size();
	for (int i = 0; i < len_arr - 2; i++) {
		if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
			int left = i + 1;
			int right = nums.size() - 1;
			int x = nums[i];
			while (left < right) {
				int sums = x + nums[left] + nums[right];
				if (sums == 0) {
					result.push_back(vector<int> {nums[i], nums[left], nums[right]});
					while (left < right && nums[left] == nums[left + 1]) {
						left++;
					}
					while (left < right && nums[right] == nums[right - 1]) {
						right--;
					}
					left++;
					right--;
				}
				else if (sums < 0) {
					left++;
				}
				else {
					right--;
				}
			}
		}
	}
	return result;
}




int main()
{
	
	vector<int> vect({-1,0,1,2,-1,-4});
	sort(vect.begin(), vect.end());
	cout << vect.size() << "\n";
	vector<vector<int> >ret = threeSum(vect);
	cout << ret.size();
	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j] << " ";
		}
		cout << "\n";
	}
	
    

    return 0;
}

