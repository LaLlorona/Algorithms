#include <bits/stdc++.h>

using namespace std;


const int MAX = 103;
vector<int> graph[MAX];

int numVertice;
int numEdge;
bool visited[MAX];
vector<int> dfsResult;
vector<int> bfsResult;

queue<int> bfsQueue;

void DFS(int from) {
    visited[from] = true;
    cout << "from dfs: " << from << "\n"; 

    for (int i = 0 ; i < graph[from].size(); i++) {
        int there = graph[from][i];
        if (!visited[there]) {
            visited[there] = true;
            dfsResult.push_back(there);
            DFS(there);
        }
    }
}

void Bfs(int begin) {
    visited[begin] = true;
    bfsQueue.push(begin);

    while (!bfsQueue.empty()) {
        int here = bfsQueue.front();
        bfsQueue.pop();
        cout << "from bfs: " << here << "\n"; 

        bfsResult.push_back(here);
        visited[here] = true;

        for (int i = 0; i < graph[here].size(); i++) {
            int there = graph[here][i];
            if (!visited[there]) {
                bfsQueue.push(there);
            }
        }
    }

    
}

void PrintVector(vector<int> result) {
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << "\n";
}

int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(in.rdbuf()); 

    while (cin >> numVertice >> numEdge) {

        for (int i = 0; i <= numVertice; i++) {
            graph[i].clear();
        }
        

        for (int i = 0; i < numEdge; i++) {
            int a, b;
            cin >> a >> b;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for (int i = 1; i <= numVertice; i++) {
            sort(graph[i].begin(), graph[i].end());
        }
        memset(visited, 0 , sizeof(visited));
        DFS(1);
        memset(visited, 0 , sizeof(visited));
        Bfs(1);
        PrintVector(dfsResult);
        PrintVector(bfsResult);
       


    }

}


  