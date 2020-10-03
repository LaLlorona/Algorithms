#include <bits/stdc++.h>


using namespace std;

const int MAX = 101; 
vector<int> graph[MAX];
bool visited[MAX];
int num;

void Dfs(int here) {
	visited[here] = true;
	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];
		if (!visited[there]) {
			Dfs(there);
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
	
	while (cin >> num) {
		for (int i = 1; i <= num; i++) {
			int to;
			cin >> to;
			graph[i].push_back(to);
		}
		int total_num_in_cycle = 0;
		vector<int> numbers_in_cycle;
		for (int i = 1; i <= num; i++) {
			memset(visited, 0, sizeof(visited));
			for (int j = 0; j < graph[i].size(); j++) {
				int there = graph[i][j];
				Dfs(there);
			}
			if (visited[i]) {
				total_num_in_cycle++;
				numbers_in_cycle.push_back(i);
			}
		}
		cout << total_num_in_cycle << "\n";
		for (int i = 0; i < total_num_in_cycle; i++) {
			cout << numbers_in_cycle[i] << "\n";
		}
	} 
	
	
    

    return 0;
}

