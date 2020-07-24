#include <bits/stdc++.h>


using namespace std;
const int MAX = 10000;
vector<int> graph[MAX + 2];
vector<int> tree[MAX + 2];
int num_good_citizen[MAX + 2];
int max_good_citizen_from[MAX + 2][2];
int num_city;

void Dfs(int here, int prev) {
	for (int i = 0; i < graph[here].size(); i++) {
		int next = graph[here][i];
		if (next != prev) {
			tree[here].push_back(next);
			Dfs(next, here);
		}
	}
}

int FillMaxGoodCitizenFrom(int from, int am_i_chosen) {
	int& ret = max_good_citizen_from[from][am_i_chosen];
	if (ret != -1) {
		return ret;
	}
	else if (am_i_chosen == 1) {
		ret = num_good_citizen[from];
		for (int i = 0; i < tree[from].size(); i++) {
			int there = tree[from][i];
			ret += FillMaxGoodCitizenFrom(there, 0);
		}
		return ret;
	}
	else { // when current root is not chosen 
		ret = 0;
		for (int i = 0; i < tree[from].size(); i++) {
			int there = tree[from][i];
			int if_choose_there = FillMaxGoodCitizenFrom(there, 1); // number of citizens when choosing the child of 'from'
			int if_not_choose_there = 0; // number of citizens when choosing children of child
			for (int j = 0; j < tree[there].size(); j++) {
				int child_there = tree[there][j];
				if_not_choose_there += max(FillMaxGoodCitizenFrom(child_there, 1), FillMaxGoodCitizenFrom(child_there, 0));
			}
			ret += max(if_not_choose_there, if_choose_there);
		}
		return ret;
	}
}


int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
//     std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//     std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	while (cin >> num_city) {
		for (int i = 0; i < MAX + 2; i++) {
			tree[i].clear();
			graph[i].clear();
		}
		memset(max_good_citizen_from, -1, sizeof(max_good_citizen_from));
		for (int i = 1; i <= num_city; i++) {
			cin >> num_good_citizen[i];
		}
		for (int i = 0; i < num_city - 1; i++) {
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
		}
		Dfs(1, -1); // suppose root is 1
		cout << max(FillMaxGoodCitizenFrom(1, 0), FillMaxGoodCitizenFrom(1, 1)) << "\n";
		// for (int i = 1; i <= num_city; i++) {
		// 	cout << i << " ";
		// 	for (int j = 1; j >= 0; j--) {
		// 		cout << max_good_citizen_from[i][j] << " ";
		// 	}
		// 	cout << "\n";
		// }
		
		
	}
    

    return 0;
}

