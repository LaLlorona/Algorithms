#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
//#include <queue>

using namespace std;
typedef long long ll;
const int MAX = 1001;
int build_time[MAX];
int begin_time[MAX];
vector<int> graph[MAX];
int num_pointed[MAX];

int num_building, num_route;

void FillTimes() {
	//cout << "fill times running";
  queue<int> currently_building;
	for (int i = 0; i < num_building; i++) {
		if (num_pointed[i] == 0) {
			currently_building.push(i);
			begin_time[i] = 0;
		}
	}
	while (!currently_building.empty()) {
		int here = currently_building.front();
		//cout << here;
		currently_building.pop();
		int time_begin_build = begin_time[here];
		int time_end_build = begin_time[here] + build_time[here];
		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i];
			begin_time[there] = max(begin_time[there], time_end_build);
			num_pointed[there] = num_pointed[there] - 1;
			if (num_pointed[there] == 0) {
				currently_building.push(there);
			}
		}
	}
	
	
}
int main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase != 0) {
		num_testcase = num_testcase - 1;
		for (int i = 0; i < MAX; i++) {
			graph[i].clear();
		}
		memset(begin_time, 0, sizeof(begin_time));
		memset(build_time, 0, sizeof(build_time));
		memset(num_pointed, 0, sizeof(num_pointed));
		cin >> num_building >> num_route;
		for (int i = 0; i < num_building; i++) {
			cin >> build_time[i];
		}
		for (int i = 0; i < num_route; i++) {
			int from;
			int to;
			cin >> from >> to;
			from = from - 1;
			to = to - 1;
			num_pointed[to]++;
			graph[from].push_back(to);
		}
		int target;
		cin >> target;
		target = target - 1;
		FillTimes();
		cout << begin_time[target] + build_time[target] << "\n";
		
		
	}
	
	
	
	return 0;
}



