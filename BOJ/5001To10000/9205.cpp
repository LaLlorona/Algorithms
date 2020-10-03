#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> pii;
int num_village;
vector<pii> positions;
vector<int> graph[103];
bool reachable[103];

void Dfs(int here) {
	reachable[here] = true;
	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];
		if (!reachable[there]) {
			Dfs(there);
		}
	}
}


int DistBetween(pii a, pii b) {
	return (abs(a.first - b.first) + abs(a.second - b.second));
}

int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		cin >> num_village;
		num_village += 2;
		positions.clear();
		for (int i = 0; i < 103; i++) {
			graph[i].clear();
		}
		for (int i = 0; i < num_village; i++) {
			int x, y;
			cin >> x >> y;
			positions.push_back({y, x});
		}
		for (int i = 0; i < num_village; i++) {
			for (int j = 0; j < num_village; j++) {
				if (i != j) {
					if (DistBetween(positions[i], positions[j]) <= 1000) {
						graph[i].push_back(j);
					}
				}
			}
		}
		memset(reachable, 0, sizeof(reachable));
		Dfs(0);
		if (reachable[num_village - 1]) {
			cout << "happy\n";
		}
		else {
			cout << "sad\n";
		}
		
	}
    

    return 0;
}

