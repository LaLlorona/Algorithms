#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;
int numVertice;
int numEdge;
int beginVertex;
vector<int> graph[MAX];

int visited[MAX];
int visitOrder = 1;

queue<int> bfsQueue;

void BFS(int beginPoint) {
    
    bfsQueue.push(beginPoint);

    

    while (!bfsQueue.empty()) {
        int here = bfsQueue.front();
        bfsQueue.pop();
        if (visited[here] == 0) {
            visited[here] = visitOrder;
            visitOrder++;
            for (int i = 0 ; i < graph[here].size(); i++) {
                int there = graph[here][i];
                if (visited[there] == 0) {
                    bfsQueue.push(there);
                }
            }
        }

    }
    
}


int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    // std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); 
	// std::cin.rdbuf(in.rdbuf()); 


    while (cin >> numVertice >> numEdge >> beginVertex) {
        memset(visited, 0, sizeof(visited));
        visitOrder = 1;
        for (int i = 0; i < numVertice; i++) {
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

        BFS(beginVertex);

        

        for (int i = 1 ;i <= numVertice; i++) {
            cout << visited[i] << "\n";
        }
    }

}


  