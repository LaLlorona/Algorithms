#include <bits/stdc++.h>


using namespace std;

int num_vertice;
const int MAX = 10000;
vector<int> graph[MAX + 2];
vector<int> tree[MAX + 2];
vector<int> route;
int weight_vertice[MAX + 2];
int max_independent_set[MAX + 2][2];
bool used[MAX + 2];

void Dfs(int here, int prev) {
	for (int i = 0; i < graph[here].size(); i++) {
		int next = graph[here][i];
		if (next != prev) {
			tree[here].push_back(next);
			Dfs(next, here);
		}
	}
}

int MaxWeightUnder(int here, int am_i_choosed) {
	int& ret = max_independent_set[here][am_i_choosed];
	if (ret != -1) {
		return ret;
	}
	if (am_i_choosed == 1) {
		ret = weight_vertice[here];
		for (int i = 0; i < tree[here].size(); i++) {
			int there = tree[here][i];
			ret += MaxWeightUnder(there, 0);
		}
		return ret;
	}
	else {//do not choose here
		ret = 0;
		for (int i = 0; i < tree[here].size(); i++) {
			int there = tree[here][i];
			int not_choose_there = MaxWeightUnder(there, 0);
			int choose_there = MaxWeightUnder(there, 1);
			if (choose_there > not_choose_there) {
				ret += choose_there;
				used[there] = true;
			}
			else {
				ret += not_choose_there;
			}
		}
		return ret;
	}
}

void Trace(int here, int used_here) {
	if (used_here == 1) {
		route.push_back(here);
		for (int i = 0; i < tree[here].size(); i++) {
			int there = tree[here][i];
			Trace(there, 0);
		}
	}
	else {
		for (int i = 0; i < tree[here].size(); i++) {
			int there = tree[here][i];
			Trace(there, used[there]);
		}
	}
}




int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
// 	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
// 	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	while (cin >> num_vertice) {
		memset(max_independent_set, -1, sizeof(max_independent_set));
		route.clear();
		for (int i = 0; i < MAX + 2; i++) {
			graph[i].clear();
			tree[i].clear();
		}
		
		for (int i = 1; i <= num_vertice; i++) {
			cin >> weight_vertice[i];
		}
		for (int i = 0; i < num_vertice - 1; i++) {
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
		}
		Dfs(1, -1);
		int choose_root = MaxWeightUnder(1, 1);
		int not_choose_root = MaxWeightUnder(1, 0);
		if (choose_root > not_choose_root) {
			used[1] = true;
		}
		cout << max(choose_root, not_choose_root) << "\n";
		Trace(1, used[1]);
		sort(route.begin(), route.end());
		for (int i = 0; i < route.size(); i++) {
			cout << route[i] << " ";
		}
		cout << "\n";
		
	}
		
    

    return 0;
}

