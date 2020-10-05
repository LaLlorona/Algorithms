#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> pii; //time to reach point, numbering of the point
const int MAX = 100001;
const int INF = 987654321;
int begin_pos;
int target_pos;
int min_time_reach[MAX];
int num_path_there[MAX];

bool IsInBound(int here) {
	return (here >= 0 && here < MAX);
}

void FillMinTime() {
	queue<int> bfs_queue;
	min_time_reach[begin_pos] = 0;
	num_path_there[begin_pos] = 1;
	bfs_queue.push(begin_pos);
	
	while (!bfs_queue.empty()) {
		int here = bfs_queue.front();
		bfs_queue.pop();
		if (here == target_pos) {
			break;
		}
		
		if (here == 1 && min_time_reach[here + 1] == INF) {
			min_time_reach[here + 1] = min_time_reach[here] + 1;
			num_path_there[here + 1] += num_path_there[here] * 2;
			bfs_queue.push(here + 1);
		}
		
		else {
			if (IsInBound(here + 1) && min_time_reach[here + 1] == min_time_reach[here] + 1) {
				num_path_there[here + 1] += num_path_there[here];
			}
			if (IsInBound(here - 1) && min_time_reach[here - 1] == min_time_reach[here] + 1) {
				num_path_there[here - 1] += num_path_there[here];
			}
			if (IsInBound(here * 2) && min_time_reach[here * 2] == min_time_reach[here] + 1) {
				num_path_there[here * 2] += num_path_there[here];
			}

			if (IsInBound(here + 1) && min_time_reach[here + 1] == INF) {
				min_time_reach[here + 1] = min_time_reach[here] + 1;
				num_path_there[here + 1] += num_path_there[here];
				bfs_queue.push(here + 1);
			}
			if (IsInBound(here - 1) && min_time_reach[here - 1] == INF) {
				min_time_reach[here - 1] = min_time_reach[here] + 1;
				num_path_there[here - 1] += num_path_there[here];
				bfs_queue.push(here - 1);
			}
			if (IsInBound(here * 2) && min_time_reach[here * 2] == INF) {
				min_time_reach[here * 2] = min_time_reach[here] + 1;
				num_path_there[here * 2] += num_path_there[here];
				bfs_queue.push(here * 2);
			}
		}
		
	}
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
		
		memset(num_path_there, 0, sizeof(num_path_there));
		for (int i = 0; i < MAX; i++) {
			min_time_reach[i] = INF;
		}
		FillMinTime();
		cout << min_time_reach[target_pos] << "\n" << num_path_there[target_pos] << "\n";
		
	}
    

    return 0;
}

