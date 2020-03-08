#include <iostream>
#include <algorithm>

using namespace std;

int num_city;
int num_current_road;
int num_future_road;
int graph[200][200];
int useless = 0;
const int INF = 987654321;

void floyd() {
    for (int i = 0; i < num_city; i++) {
        graph[i][i] = 0;
    }
    for (int k = 0; k < num_city; k++) {
        for (int from = 0; from < num_city; from++) {
            for (int to = 0; to < num_city; to++) {
                graph[from][to] = min(graph[from][to],graph[from][k] + graph[k][to]);
            }
        }
    }
}

bool update(int a, int b, int weight) {
    if (graph[a][b] <= weight) {
        return false;
    }
    for (int from = 0; from < num_city; from++) {
        for (int to = 0; to < num_city; to++) {
            graph[from][to] = min(graph[from][to], min(graph[from][a] + weight + graph[b][to], graph[from][b] + weight + graph[a][to] ));
        }
    }
    return true;
}

int main()
{
    int num_testcase;
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++) {
        cin >> num_city;
        cin >> num_current_road;
        cin >> num_future_road;
        int from;
        int to;
        int weight;
        useless = 0;
        for (int x = 0; x < num_city; x++) {
             for (int y = 0; y < num_city; y++) {
                 graph[y][x] = INF;
             }
        }
        for (int j = 0; j < num_current_road; j++) {
            cin >> from;
            cin >> to;
            cin >> weight;
            graph[from][to] = weight;
            graph[to][from] = weight;
        }
        floyd();
        for (int j = 0; j < num_future_road; j++) {
            cin >> from;
            cin >> to;
            cin >> weight;
            if (!update(from, to , weight)){
                useless++;
            }
        }
        
        cout << useless << endl;
        
    }
    

    return 0;
}
