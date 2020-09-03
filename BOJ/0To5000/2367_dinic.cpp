#include <bits/stdc++.h>


using namespace std;


const int MAX = 302;
const int INF = 987654321;
int capacity[MAX][MAX];
int flow[MAX][MAX];
int work[MAX];
int level[MAX];
vector<int> graph[MAX];
int num_people, num_food, food_limit;
int source, sink;

bool BFSDinic() { // check whether level graph exists and make it 
	memset(level, -1, sizeof(level));
	queue<int> bfs_queue;
	bfs_queue.push(source);
	level[source] = 0;
	while (!bfs_queue.empty()) {
		int here = bfs_queue.front();
		bfs_queue.pop();
		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i];
			if (level[there] == -1 && capacity[here][there] - flow[here][there] > 0) {
				level[there] = level[here] + 1;
				bfs_queue.push(there);
			}
		}
	}
	if (level[sink] == -1) {// if level graph that reaches sink cannot be made 
		return false;
	}
	return true;
}
int DFSDinic(int here, int flow_now) {//when current flow to 'here' is 'flow' calculate flow of the current level graph
	if (here == sink) {
		return flow_now;
	}
	for (int &i = work[here]; i < graph[here].size(); i++) {
		int there = graph[here][i];
		if (level[there] == level[here] + 1 && (capacity[here][there] - flow[here][there] > 0)) {
			int ret = DFSDinic(there, min(flow_now, capacity[here][there] - flow[here][there]));
			if (ret > 0) {
				flow[here][there] += ret;
				flow[there][here] -= ret;
				return ret;
			}
		}
	}
	return 0;
}
int Dinic() {
	int total_flow = 0;
	while (BFSDinic()) {
		memset(work, 0, sizeof(work));
		while (true) {
			int current_flow = DFSDinic(source, INF);
			if (current_flow == 0) {
				break;
			}
			total_flow += current_flow;
		} 
	}
	return total_flow;
}




void AddEdge(int from, int to, int amount) {
	capacity[from][to] = amount;
	graph[from].push_back(to);
	graph[to].push_back(from);
}

int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_people >> food_limit >> num_food) {
		memset(capacity, 0, sizeof(capacity));
		memset(flow, 0, sizeof(flow));
		source = 0;
		sink = 301;
		for (int i = 0; i < MAX; i++) {
			graph[i].clear();
		}
		for (int i = 1; i <= num_food; i++) {
			int num;
			cin >> num;
			AddEdge(i + 200, 301, num);
		}
		for (int i = 1; i <= num_people; i++) {
			AddEdge(0, i, food_limit);
			int possible_bring;
			cin >> possible_bring;
			for (int j = 0; j < possible_bring; j++) {
				int food;
				cin >> food;
				AddEdge(i, food + 200, 1);
			}
		}
		cout << Dinic() << "\n";
		
		
		
		
	}
    

    return 0;
}

