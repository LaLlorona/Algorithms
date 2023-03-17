#include <bits/stdc++.h>

using namespace std;


const int MAX = 103;
vector<int> graph[MAX];

int numVertice;
int numEdge;
bool visited[MAX];

void DFS(int from) {
    visited[from] = true;

    for (int i = 0 ; i < graph[from].size(); i++) {
        int there = graph[from][i];
        if (!visited[there]) {
            visited[there] = true;
            DFS(there);
        }
    }
}

int CheckVisitedVertice() {
    int cnt = 0;
    for (int i = 1; i <= numVertice; i++) {
        if (visited[i]) {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    // std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); 
	// std::cin.rdbuf(in.rdbuf()); 

    while (cin >> numVertice >> numEdge) {
        memset(visited, 0 , sizeof(visited));

        for (int i = 0; i < numEdge; i++) {
             int a, b;
            cin >> a >> b;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        DFS(1);
        cout << CheckVisitedVertice() - 1 << "\n";
       


    }

}


  