#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

vector<vector<pair<double, int> > > graph; // int : adjacent vertex index, double: weight between current vertex 
double weight[10001];

double INF = 1e300;

int num_computer;
int num_edge;

double Dijkstra(int start) {
    priority_queue<pair<double, int> > pq;
    pq.push(1.0, start);
    while (!pq.empty()) {
        int current_vertex = pq.top().second;
        double current_weight = pq.top().first;
        pq.pop();
        for (int i = 0; i < graph[current_vertex].size(); i++) {
            int adjacent_vertex = graph[current_vertex][i].second;
            double weight_between = graph[current_vertex][i].first;
            
            
        }
    }
    
}

int main()
{
    int num_testcase;
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++) {
        graph.clear();
        cin >> num_computer;
        cin >> num_edge;
        int vertex1;
        int vertex2;
        double weight;
        for (int j = 0; j < num_edge; j++) {
            cin >> vertex1;
            cin >> vertex2;
            cin >> weight;
            graph[vertex1].push_back(make_pair(vertex2, weight));
            graph[vertex2].push_back(make_pair(vertex1, weight));
        }
        cout << Dijkstra(0);
        
        
    }
    cout<<"Hello World";

    return 0;
}
