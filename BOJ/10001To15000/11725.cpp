#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>



using namespace std;

int n;
const int MAX = 100000 + 1;
vector<int> tree[MAX];
bool visited[MAX];
int parent[MAX];

void FindParent(int here) {
	visited[here] = true;
	for (int i = 0; i < tree[here].size(); i++) {
		int there = tree[here][i];
		if (!visited[there]) {
			parent[there] = here;
			FindParent(there);
		}
	}
}


int main()
{
	
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	int a, b;
	while (cin >> n) {
		memset(parent, 0, sizeof(parent));
		memset(visited, 0 , sizeof(visited));
		for (int i = 0 ; i < n; i++) {
			tree[i].clear();
		}
		for (int i = 0; i < n - 1; i++) {
			cin >> a >> b;
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
		
		FindParent(1);
		for (int i = 2; i < n + 1; i++) {
			cout << parent[i] << "\n";
		}
	}
    

    return 0;
}

