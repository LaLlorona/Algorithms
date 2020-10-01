#include <bits/stdc++.h>


using namespace std;
const int MAX = 501;
const int INF = 987654321;
vector<int> graph[MAX];
int relate_with_me[MAX];
int num_friend, num_relation;


int Bfs() {
	queue<int> bfs_queue;
	bfs_queue.push(1);
	relate_with_me[1] = 0;
	while (!bfs_queue.empty()) {
		int here = bfs_queue.front();
		bfs_queue.pop();
		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i];
			if (relate_with_me[there] == INF) {
				relate_with_me[there] = relate_with_me[here] + 1;
				bfs_queue.push(there);
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < MAX; i++) {
		if (relate_with_me[i] == 1 || relate_with_me[i] == 2) {
			ret++;
		}
	}
	return ret;
	
}


int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while( cin >> num_friend >> num_relation) {
		for (int i = 0; i < MAX; i++) {
			relate_with_me[i] = INF;
		}
		
		for (int i = 0; i < num_relation; i++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
			
		}
		cout << Bfs() << "\n";
		
	}
    

    return 0;
}

