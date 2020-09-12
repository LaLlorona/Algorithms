#include <bits/stdc++.h>


using namespace std;

const int MAX = 10001;
const int INF = 987654321;
int num_work;
int fast_begin_time[MAX];
int work_time[MAX];
int num_dependent[MAX];
vector<int> graph[MAX];

void FillFastBeginTime() {
	queue<int> bfs_queue;
	for (int i = 1; i <= num_work; i++) {
		if (num_dependent[i] == 0) {
			bfs_queue.push(i);
			fast_begin_time[i] = 0;
		}
	}
	while (!bfs_queue.empty()) {
		int here = bfs_queue.front();
		bfs_queue.pop();
		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i];
			fast_begin_time[there] = max(fast_begin_time[there], fast_begin_time[here] + work_time[here]);
			num_dependent[there]--;
			if (num_dependent[there] == 0) {
				bfs_queue.push(there);
			}
		}
	}
}





int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
//     std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//     std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_work) {
		memset(fast_begin_time, -1, sizeof(fast_begin_time));
		for (int i = 1; i <= num_work; i++) {
			int dependency, time_to_do;
			cin >> time_to_do >> dependency;
			num_dependent[i] = dependency;
			work_time[i] = time_to_do;
			for (int j = 0; j < dependency; j++) {
				int master;
				cin >> master;
				graph[master].push_back(i);
			}
		}
		FillFastBeginTime();
		int result = -INF;
		for (int i = 1; i <= num_work; i++) {
			result = max(result, fast_begin_time[i] + work_time[i]);
		}
		cout << result << "\n";
	}
    

    return 0;
}

