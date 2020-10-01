#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> pii;
int min_time_reach[100001];
int target, begin_position;
const int INF = 987654321;

bool IsInBound(int here) {
	return (here >= 0 && here <= 100000);
}

int FindMinTime(int start) {
	priority_queue<pii, vector<pii>, greater<pii> > bfs_queue;
	bfs_queue.push({0, start});
	min_time_reach[start] = 0;
	
	while (!bfs_queue.empty()) {
		int here = bfs_queue.top().second;
		int time_to_reach_here = min_time_reach[here];
		//cout << here << "\n";
		bfs_queue.pop();
		if (here == target) {
			return min_time_reach[here];
		}
		else {
			if (IsInBound(here * 2)) {
				if (min_time_reach[here * 2] > time_to_reach_here) {
					min_time_reach[here * 2] = time_to_reach_here;
					bfs_queue.push({time_to_reach_here, here * 2});
				}
			}
			if (IsInBound(here + 1)) {
				if (min_time_reach[here + 1] > time_to_reach_here + 1) {
					min_time_reach[here + 1] = time_to_reach_here + 1;
					bfs_queue.push({time_to_reach_here + 1, here + 1});
				}
				
			}
			if (IsInBound(here - 1)) {
				if (min_time_reach[here - 1] > time_to_reach_here + 1) {
					min_time_reach[here - 1] = time_to_reach_here + 1;
					bfs_queue.push({time_to_reach_here + 1, here - 1});
				}
			}
		}
	}
	return INF;
}




int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> begin_position >> target) {
		for (int i = 0; i < 100001; i++) {
			min_time_reach[i] = INF;
		}
		cout << FindMinTime(begin_position) << "\n";
	}
	
    

    return 0;
}

