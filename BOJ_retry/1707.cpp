#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii; //color, vertex index.


const int MAX = 200002;
int numTestcase;
int numVertice;
int numEdge;

vector<int> graph[MAX];
int verticeColor[MAX];

void BFS(int beginPoint) {
    
    queue<pii> bfsQueue;
    bfsQueue.push(pii(-1, beginPoint));

    while (!bfsQueue.empty()) {
        pii here = bfsQueue.front();
        bfsQueue.pop();

        for (int i = 0; i < graph[here.second].size(); i++) {
            int to = graph[here.second][i];
            // if (verticeColor[to] == here.first) {
            //     return false;
            // }
            if (verticeColor[to] == 0) {
                verticeColor[to] = -here.first;
                bfsQueue.push(pii(verticeColor[to], to));
            }
        }
    }
}

bool IsBiparty() {
    for (int from = 1; from <= numVertice; from++){
        for (int j = 0; j < graph[from].size(); j++) {
            int to = graph[from][j];
            if (verticeColor[from] == verticeColor[to] || verticeColor[from] == 0) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    // std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); 
	// std::cin.rdbuf(in.rdbuf()); 

    cin >> numTestcase;

    while (numTestcase--) {
        cin >> numVertice >> numEdge;
        for (int i = 1; i <= numVertice; i++) {
            graph[i].clear();
        }
        memset(verticeColor, 0, sizeof(verticeColor));
        for (int i = 1 ; i <= numEdge; i++) {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);


        }
        for (int i = 1; i <=numVertice; i++) {
            if (verticeColor[i] == 0) {
                BFS(i);
            } 
        }
        

        if (IsBiparty()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

        // for (int i = 1; i <= numVertice; i++) {
        //     cout <<verticeColor[i] << " ";
        // }
        // cout << "\n";
    }

}


  