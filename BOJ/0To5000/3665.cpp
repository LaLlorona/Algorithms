#include <bits/stdc++.h>


using namespace std;

int n;
const int MAX = 501;
int team_rank[MAX]; // team_rank[a]: team a's team_rank
int num_pointed[MAX];
bool graph[MAX][MAX]; // graph[a][b] is true if team_rank of a is higher than b.  if team_rank[a] < team_rank[b], graph[a][b] is true;
int num_teams;
int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
//     std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//     std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		cin >> num_teams;
		memset(graph, 0, sizeof(graph));
		memset(num_pointed, 0, sizeof(num_pointed));
		for (int i = 1 ; i <= num_teams; i++) {
			int team;
			cin >> team;
			team_rank[team] = i;
		}
		for (int i = 1; i <= num_teams; i++) {
			for (int j = 1; j <= num_teams; j++) {
				if (team_rank[i] < team_rank[j]) {
					graph[i][j] = true;
					num_pointed[j]++;
				}
			}
		}
		int num_changed;
		cin >> num_changed;
		for (int i = 0; i < num_changed; i++) {
			int a, b;
			cin >> a >> b;
			if (team_rank[a] < team_rank[b]) { // a won last year, but b win this year
				graph[a][b] = false;
				graph[b][a] = true;
				num_pointed[a]++;
				num_pointed[b]--;
			}
			else { //when team_rank[a] > team_rank [b]. b won last year, but a win this year
				graph[b][a] = false;
				graph[a][b] = true;
				num_pointed[b]++;
				num_pointed[a]--;
			}
		}
		queue<int> free_teams;
		vector<int> ans;
		bool certain = true;
		for (int i = 1; i <= num_teams; i++) {
			if (num_pointed[i] == 0) {
				free_teams.push(i);
			}
		}
		while (!free_teams.empty()) {
			if (free_teams.size() > 1) {
				certain = false;
				break;
			}
			int here = free_teams.front();
			free_teams.pop();
			ans.push_back(here);
			for (int i = 1; i <= num_teams; i++) {
				if (graph[here][i] == 1) {
					num_pointed[i]--;
					if (num_pointed[i] == 0) {
						free_teams.push(i);
					}
				}
			}
		}
		if (!certain) {
			cout << "?\n";
		}
		else if (ans.size() == num_teams) {
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i] << " ";
			}
			cout << "\n";
		}
		else {
			cout << "IMPOSSIBLE\n";
		}
	}
    

    return 0;
}

