#include <bits/stdc++.h>


using namespace std;
const int MAX = 100001;
const int INF = 987654321;
int begin_pos;
int target_pos;
int min_time_reach[MAX];
int before_here[MAX];

bool IsInBound(int here) {
	return (here >= 0 && here < MAX);
}
void FillMinTime() {
	queue<int> bfs_queue;
	min_time_reach[begin_pos] = 0;
	before_here[begin_pos] = begin_pos;
	bfs_queue.push(begin_pos);
	
	while (!bfs_queue.empty()) {
		int here = bfs_queue.front();
		bfs_queue.pop();
		if (here == target_pos) {
			break;
		}
		if (IsInBound(here + 1) && min_time_reach[here + 1] == INF) {
			min_time_reach[here + 1] = min_time_reach[here] + 1;
			before_here[here + 1] = here;
			bfs_queue.push(here + 1);
		}
		if (IsInBound(here - 1) && min_time_reach[here - 1] == INF) {
			min_time_reach[here - 1] = min_time_reach[here] + 1;
			before_here[here - 1] = here;
			bfs_queue.push(here - 1);
			
		}
		if (IsInBound(here * 2) && min_time_reach[here * 2] == INF) {
			min_time_reach[here * 2] = min_time_reach[here] + 1;
			before_here[here * 2] = here;
			bfs_queue.push(here * 2);
		}
	}
}
void PrintAnswer() {
	cout << min_time_reach[target_pos] << "\n";
	int here = target_pos;
	vector<int> path;
	while (here != begin_pos) {
		path.push_back(here);
		here = before_here[here];
	}
	path.push_back(begin_pos);
	
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << " ";
	}
	cout << "\n";
}


int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	while (cin >> begin_pos >> target_pos) {
		memset(before_here, -1, sizeof(before_here));
		for (int i = 0; i < MAX; i++) {
			min_time_reach[i] = INF;
		}
		FillMinTime();
		PrintAnswer();
	}
    

    return 0;
}

