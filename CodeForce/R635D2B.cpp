#include <bits/stdc++.h>
#include <utility>
 
 
using namespace std;
 
int initial_HP;
int num_absortion;
int num_Lightning;
 
void BFS() {
	queue<pair<int, pair<int, int> > >BFS_queue;
	int current_HP = initial_HP;
	int left_ab = num_absortion;
	while (current_HP >= 100 && left_ab >= 1) {
		current_HP = current_HP / 2 + 10;
		left_ab--;
	}
	BFS_queue.push(make_pair(current_HP, make_pair(left_ab, num_Lightning)));
	bool defeated = false;
	while (!BFS_queue.empty()) {
		int current_HP = BFS_queue.front().first;
		int left_absortion = BFS_queue.front().second.first;
		int left_lightning = BFS_queue.front().second.second;
		BFS_queue.pop();
		if (current_HP <= 0) {
			defeated = true;
			break;
		}
		
		if (left_absortion >= 1) {
			BFS_queue.push(make_pair(current_HP / 2 +10, make_pair(left_absortion - 1, left_lightning)));
		}
		if (left_lightning >= 1) {
			BFS_queue.push(make_pair(current_HP - 10, make_pair(left_absortion, left_lightning - 1)));
		}
		
	}
	if (defeated) {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}
}
 
 
 
int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		cin >> initial_HP >> num_absortion >> num_Lightning;
		BFS();
	}
    
 
    return 0;
}