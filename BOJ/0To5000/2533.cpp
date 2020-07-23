#include <bits/stdc++.h>


using namespace std;

int num_vertice;
const int MAX = 1000000;
vector<int> graph[MAX + 2];
vector<int> tree[MAX + 2];
int num_early_adapter[MAX + 2][2];
void Dfs(int here, int prev) {
	for (int i = 0; i < graph[here].size(); i++) {
		int next = graph[here][i];
		if (next != prev) {
			tree[here].push_back(next);
			Dfs(next, here);
		}
	}
}

int CalcEarly(int here, int am_i_early) {
	int& ret = num_early_adapter[here][am_i_early];
	if (ret != -1 ) {
		return ret;
	}
	if (am_i_early == 1) {
		ret = 1;
		for (int i = 0; i < tree[here].size(); i++) {
			int there = tree[here][i];
			ret += min(CalcEarly(there, 0), CalcEarly(there, 1));
		}
	}
	else {
		ret = 0;
		for (int i = 0; i < tree[here].size(); i++) {
			int there = tree[here][i];
			ret += CalcEarly(there, 1);
		}
	}
	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	while (cin >> num_vertice) {
		memset(num_early_adapter, -1, sizeof(num_early_adapter));
		for (int i = 0; i < num_vertice; i++) {
			graph[i].clear();
			tree[i].clear();
		}
		for (int i = 0; i < num_vertice - 1; i++) {
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
		}
		Dfs(1, -1);
		cout << min(CalcEarly(1, 0), CalcEarly(1, 1));
		// cout << CalcEarly(1, 0) << " " <<  CalcEarly(1, 1);
		
		// for (int i = 1; i <= num_vertice; i++) {
		// 	cout << i << " " << num_early_adapter[i][0] << " " << num_early_adapter[i][1] << "\n";
		// }
	}
		
    

    return 0;
}

