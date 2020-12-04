#include <bits/stdc++.h>


using namespace std;




int jump(vector<int>& nums) {
	int arr_size = nums.size();
	int time_to_reach[30001];
	queue<int> bfs_queue;
	
	memset(time_to_reach, -1, sizeof(time_to_reach));
	
	time_to_reach[0] = 0;
	bfs_queue.push(0);
	while (!bfs_queue.empty()) {
		int here = bfs_queue.front();
		bfs_queue.pop();
		if (here == arr_size - 1) {
			return time_to_reach[here];
		}
		int here_step = nums[here];
		for (int there = min(arr_size - 1, here + here_step); there >= max(0, here - here_step); there--) {
			if (time_to_reach[there] == -1) {
				time_to_reach[there] = time_to_reach[here] + 1;
				bfs_queue.push(there);
			}
		}
	}
	return 987654321;
	
	
}


int main()
{
	vector<int> temp = {2,3,0,1,4};
	cout << jump(temp);
    

    return 0;
}

