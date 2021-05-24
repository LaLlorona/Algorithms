#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

typedef pair<ll, ll> pii;


ll start_num, target_num;
map<ll, ll> min_path;


ll findMinimumPath() {
	queue<pii> bfs_queue;
	bfs_queue.push(pii(start_num, 1));
	min_path[start_num] = 1;
	while (!bfs_queue.empty()) {
		pii here = bfs_queue.front();
		bfs_queue.pop();
		ll current_num = here.first;
		ll current_pos = here.second;

		//cout << current_pos << " " << current_num << "\n";

		if (min_path.find(current_num * 10 + 1) == min_path.end() &&  current_num * 10 + 1 <= target_num) {
			if (current_num * 10 + 1 == target_num) {
				return current_pos + 1;
			}

			min_path[current_num * 10 + 1] = current_pos + 1;
			bfs_queue.push(pii(current_num * 10 + 1, current_pos + 1));
		}
		if (min_path.find(current_num * 2) == min_path.end() &&  current_num * 2 <= target_num) {
			if (current_num * 2 == target_num) {
				return current_pos + 1;
			}
			min_path[current_num * 2] = current_pos + 1;
			bfs_queue.push(pii(current_num * 2, current_pos + 1));
		}
	}
	return -1;

}



int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	 //std::ifstream in("input.txt");
	 //std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	 //std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	 while (cin >> start_num >> target_num) {
		 min_path.clear();
		 /*cout << start_num << " " << target_num << "\n";*/
		 cout << findMinimumPath() << "\n";
	 }
	 
	 


	return 0;
}

