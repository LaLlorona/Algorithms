#include <bits/stdc++.h>


using namespace std;

int n, m;
const int MAX_N = 1000;
const int MAX_M = 1000;

bool adj[MAX_N][MAX_M];

vector<int> a_match, b_match;

vector<bool> visited;

bool dfs(int a) {
	if (visited[a]) return false;
	
	visited[a] = true;
	for (int b = 0; b < m; b++) {
		if (adj[a][b]) {
			if (b_match[b] == -1 || dfs(b_match[b])) {
				a_match[a] = b;
				b_match[b] = a;
				return true;
			}
		}
	}
	return false;
}

int BipartiteMatch() {
	a_match = vector<int> (n, -1);
	b_match = vector<int> (m, -1);
	int size = 0;
	for (int start = 0; start < n; start++) {
		visited = vector<bool> (n, false);
		if (dfs(start)) {
			size++;
		}
	}
	return size;
}


int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
//     std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//     std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) {
			int num_work_to_do, work_to_do;
			cin >> num_work_to_do;
			for (int j = 0; j < num_work_to_do; j++) {
				cin >> work_to_do;
				adj[i][work_to_do - 1] = true;
			}
		}
		cout << BipartiteMatch() << "\n";
	}
    

    return 0;
}

