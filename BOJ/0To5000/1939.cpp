#include <bits/stdc++.h>


using namespace std;


const int MAX = 10001;
const int INF = 1987654321;

int start_island, end_island;
int num_island, num_bridge;

vector<pair<int, int> > graph[MAX];
bool visited[MAX];

int ReachableUnder(int max_weight) {
	memset(visited, 0, sizeof(visited));
	
	
	queue<int> bfs_queue;
	bfs_queue.push(start_island);
	visited[start_island] = true;
	
	while (!bfs_queue.empty()) {
		int here = bfs_queue.front();
		if (here == end_island) {
			return true;
		}
		bfs_queue.pop();
		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i].second;
			int capacity_between = graph[here][i].first;
			if (!visited[there] && capacity_between >= max_weight) {
				bfs_queue.push(there);
				visited[there] = true;
			}
		}
	}
	return false;
}








int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
// 	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
// 	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_island >> num_bridge) {
		int maximum_weight = 0;
		for (int i = 0; i < num_bridge; i++) {
			int from, to, weight;
			cin >> from >> to >> weight;
			graph[from].push_back({weight, to});
			graph[to].push_back({weight, from});
			maximum_weight = max(maximum_weight, weight);
		}
		cin >> start_island >> end_island;
		int lo = 0; 
		int hi = maximum_weight;
		int ret = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			//cout << "mid is " << mid << "\n";
			if (ReachableUnder(mid)) {
				ret = mid;
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}
		cout << ret << "\n";
	}
	
	
    

    return 0;
}

