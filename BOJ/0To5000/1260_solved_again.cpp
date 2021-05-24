#include <bits/stdc++.h>


using namespace std;

const int MAX = 1001;
int num_person, num_relationship, start_point;
vector<int> graph[MAX];
bool visited[MAX];


void Dfs(int here) {
	cout << here << " ";
	visited[here] = true;
	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];
		if (!visited[there]) {
			Dfs(there);
		}
	}

}
void Bfs(int here) {
	cout << here << " ";
	visited[here] = true;
	queue<int> bfs_queue;
	bfs_queue.push(here);
	while (!bfs_queue.empty()) {
		int current_pos = bfs_queue.front();
		bfs_queue.pop();
		for (int i = 0; i < graph[current_pos].size(); i++) {
			int there = graph[current_pos][i];
			if (!visited[there]) {
				visited[there] = true;
				cout << there << " ";
				bfs_queue.push(there);
			}
		}
	}

}

int main()
{
	/*std::ios_base::sync_with_stdio(false);
	std::cin.tie(null);
	std::cout.tie(null);*/

	 //std::ifstream in("input.txt");
	 //std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	 //std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	 while (cin >> num_person >> num_relationship >> start_point) {
		 for (int i = 0; i < MAX; i++) {
			 graph[i].clear();
		 }
		 for (int i = 0; i < num_relationship; i++) {
			 int from, to;
			 cin >> from >> to;
			 graph[from].push_back(to);
			 graph[to].push_back(from);
		 }

		 for (int i = 0; i < MAX; i++) {
			 sort(graph[i].begin(), graph[i].end());
		 }

		 
		 memset(visited, 0, sizeof(visited));
		 Dfs(start_point);
		 cout << "\n";
		 memset(visited, 0, sizeof(visited));
		 Bfs(start_point);
	 }


	return 0;
}

