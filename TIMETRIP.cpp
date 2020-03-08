#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

const int MAX_VERTEX = 101;
const int INF = 987654321;

int num_edge;
int num_vertex;
int weight_between[MAX_VERTEX][MAX_VERTEX];
int minus_weight_between[MAX_VERTEX][MAX_VERTEX];
vector<pair<int, int> > graph[MAX_VERTEX]; // graph[i] : adjacent list for (adjacent vertex, weight)
vector<pair<int, int> > minus_graph[MAX_VERTEX];


void found_reachable(int weight_between[][MAX_VERTEX]) {
    for (int i  = 0; i < MAX_VERTEX; i++) {
        weight_between[i][i] = 0;
    }
    for (int k = 0; k < MAX_VERTEX; k++) {
        for (int i = 0; i < MAX_VERTEX; i++) {
            for (int j = 0; j < MAX_VERTEX; j++) {
                weight_between[i][j] = min (weight_between[i][j], weight_between[i][k] + weight_between[k][j]);
            }
        }
    }
}

int bellmanFord(int src, vector<pair<int, int> > (&graph)[MAX_VERTEX], int weight_between[][MAX_VERTEX]) {
    vector<int> upper(MAX_VERTEX, INF);
    upper[src] = 0;
    bool updated;
    for (int iter = 0; iter < num_vertex - 1; iter++) {
        for (int here = 0; here < num_vertex; here++) {
            for (int i = 0; i < graph[here].size(); i++) {
                int there = graph[here][i].first;
                int cost = graph[here][i].second;
                if (upper[there] > upper[here] + cost) {
                    upper[there] = upper[here] + cost;
                }
            }
        }
    }
    for (int here = 0; here < num_vertex; here++) { // Vth relax, to check whether negative INF cycle exists, and reachable from vertex 0
        for (int i = 0; i < graph[here].size(); i++) {
            int there = graph[here][i].first;
            int cost = graph[here][i].second;
            if (upper[there] > upper[here] + cost) { // negative cycle exists
              
                if ((weight_between[src][here] < INF - 10000000) && (weight_between[here][1] < INF - 10000000)) { // if it is reachable, return INFINITY
                    return -INF;
                }
            }
        }
    }
    return upper[1];
}
int main()
{
    int num_testcase;
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++) {
        cin >> num_vertex;
        cin >> num_edge;
        for (int j = 0; j < MAX_VERTEX; j++) {
            graph[j].clear();
            minus_graph[j].clear();
        }
        for (int k = 0; k < MAX_VERTEX; k++) {
            for (int l = 0; l < MAX_VERTEX; l++) {
                weight_between[k][l] = INF;
                minus_weight_between[k][l] = INF;
            }
        }
        int first;
        int second;
        int weight;
        for (int j = 0; j < num_edge; j++) {
            cin >> first;
            cin >> second;
            cin >> weight;
            graph[first].push_back(make_pair(second, weight));
            
            
            minus_graph[first].push_back(make_pair(second, -weight));
            
            
            weight_between[first][second] = weight;
            
            
            minus_weight_between[first][second] = -weight;
            
        }
        found_reachable(weight_between);
        if (weight_between[0][1] == INF) {
            cout << "UNREACHABLE" << endl;
        }
        else{
            int result = bellmanFord(0, graph, weight_between);
            if (result == -INF) {
                cout << "INFINITY ";
            }
            else{
                cout << result << " ";
            }
            found_reachable(minus_weight_between);
            result = bellmanFord(0,minus_graph, minus_weight_between);
            if (result == -INF) {
                cout << "INFINITY" << endl;
            }
            else{
                cout << -result << endl;
            }
            
            
        }

    }
    

    return 0;
}
