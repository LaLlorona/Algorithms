#include <bits/stdc++.h>

using namespace std;


const int MAX = 1003;
vector<int> graph[MAX];

int numVertice;
int numEdge;
int beginPoint;
bool visited[MAX];
vector<int> dfsResult;
vector<int> bfsResult;

queue<int> bfsQueue;

void DFS(int from) {
    visited[from] = true;
    dfsResult.push_back(from);


    for (int i = 0 ; i < graph[from].size(); i++) {
        int there = graph[from][i];
        if (!visited[there]) {
            visited[there] = true;
        
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


        bfsResult.push_back(here);
        visited[here] = true;

        for (int i = 0; i < graph[here].size(); i++) {
            int there = graph[here][i];
            if (!visited[there]) {
                visited[there] = true;
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

    

    // std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); 
	// std::cin.rdbuf(in.rdbuf()); 

    while (cin >> numVertice >> numEdge >> beginPoint) {

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
        DFS(beginPoint);
        memset(visited, 0 , sizeof(visited));
        Bfs(beginPoint);
        PrintVector(dfsResult);
        PrintVector(bfsResult);
       


    }

}


  