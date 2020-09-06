#include <bits/stdc++.h>


using namespace std;

int num_building;
int build_time[501];
int fastest_build_begin_time[501];
int num_pointed [501];
vector<int> graph[501];

void TopologicalSort() {
	queue<int> q;
	for (int i = 1; i <= num_building; i++) {
		if (num_pointed[i] == 0) {
			fastest_build_begin_time[i] = 0;
			q.push(i);
		}
	}
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i];
			num_pointed[there]--;
			fastest_build_begin_time[there] = max(fastest_build_begin_time[there], fastest_build_begin_time[here] + build_time[here]);
			if (num_pointed[there] == 0) {
				q.push(there);
			}
		}
	}
	for (int i = 1; i <= num_building; i++) {
		cout << fastest_build_begin_time[i] + build_time[i] << "\n";
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
	
	while (cin >> num_building) {
		memset(fastest_build_begin_time, 0, sizeof(fastest_build_begin_time));
		memset(num_pointed, 0, sizeof(num_pointed));
		for (int i = 0; i < 501; i++) {
			graph[i].clear();
		}
		for (int i = 1; i <= num_building; i++) {
			cin >> build_time[i];
			int prerequisite_buildings;
			while (cin >> prerequisite_buildings) {
				if (prerequisite_buildings == -1) {
					break;
				}
				graph[prerequisite_buildings].push_back(i);
				num_pointed[i]++;
			}
		}
		TopologicalSort();
		
	}
    

    return 0;
}

