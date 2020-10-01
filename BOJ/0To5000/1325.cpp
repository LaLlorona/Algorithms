#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> pii;
const int MAX = 10001;

vector<int> graph[MAX];


int num_computer, num_relation;
bool visited[MAX];
int connected = 0;

void Dfs(int here) {
	visited[here] = true;
	connected++;
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
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_computer >> num_relation) {
		for (int i = 0; i < MAX; i++) {
			graph[i].clear();
		}
		for (int i = 0; i < num_relation; i++) {
			int to, from;
			cin >> to >> from;
			graph[from].push_back(to);
		}
		vector<pii> vectice_info;
		int max_connected_cand = -1;
		for (int i = 1; i <= num_computer; i++) {
			memset(visited, 0, sizeof(visited));
			connected = 0;
			Dfs(i);
			vectice_info.push_back({-connected, i});
			max_connected_cand = max(max_connected_cand, connected);
		}
		sort(vectice_info.begin(), vectice_info.end());
		for (int i = 0; i < num_computer; i++) {
			if (vectice_info[i].first == - max_connected_cand) {
				cout << vectice_info[i].second << " ";
			}
			else {
				break;
			}
		}
		
		
	}
    

    return 0;
}

