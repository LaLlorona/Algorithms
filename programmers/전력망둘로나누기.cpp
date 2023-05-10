#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;
const int INF = 987654321;
vector<int> graph[MAX];
bool visited[MAX];

int connectedCount = 0;
map<int, int> currentlyDisconnectedEdge;

void DFS(int here) {
	visited[here] = true;
	connectedCount += 1;

	for (int i = 0; i < graph[here].size(); i++) {
		int next = graph[here][i];

		if(currentlyDisconnectedEdge[here] != next && !visited[next]) {
			visited[next] = true;
			DFS(next);
		}
	}
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INF;
	for (int i = 0; i < wires.size(); i++) {
		graph[wires[i][0]].push_back(wires[i][1]);
		graph[wires[i][1]].push_back(wires[i][0]);
	}
	for (int i = 0 ; i <wires.size(); i++) {
		memset(visited, 0 ,sizeof(visited));

		currentlyDisconnectedEdge.clear();
		currentlyDisconnectedEdge[wires[i][0]] = wires[i][1];
		currentlyDisconnectedEdge[wires[i][1]] = wires[i][0];

		connectedCount = 0;
		DFS(1);
		// cout << "connected count is .... " <<connectedCount << "\n";
		answer = min(answer, abs(connectedCount - (n - connectedCount)));
	}
    return answer;
}


int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(in.rdbuf());

	cout << solution(9, {{1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9}}) << "\n";

}


  