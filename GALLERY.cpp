#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

vector<pair<double, int> >  graph[10001]; // int : adjacent vertex index, double: weight between current vertex 
double weights[10001];

double INF = 1e300;

int num_computer;
int num_edge;

double Dijkstra(int start) {
    priority_queue<pair<double, int>, vector<pair<double, int> >,greater<pair<double, int> > > pq;
    pq.push(make_pair(1.0, start));
    weights[start] = 1.0;
    while (!pq.empty()) {
        int current_vertex = pq.top().second;
        cout << "vertex is " << current_vertex ;
        
        double current_weight = pq.top().first;
        cout << " and its weight is " << current_weight << endl;
        pq.pop();
        if (weights[current_vertex] < current_weight) {
            cout << "ignored\n";
            continue;
        }
        else{
            weights[current_vertex] = current_weight;
        }
        for (int i = 0; i < graph[current_vertex].size(); i++) {
            int adjacent_vertex = graph[current_vertex][i].second;
            double weight_between = graph[current_vertex][i].first;
            cout << "weight between " << i << " and " << adjacent_vertex << " is " << weight_between << endl;
           
            if (weights[current_vertex] * weight_between < weights[adjacent_vertex]) {
                weights[adjacent_vertex] = weights[current_vertex] * weight_between;
                cout << "adjacent_vertex is " << adjacent_vertex;
                cout << " and its weight is  " << weights[adjacent_vertex] << endl;
                
                pq.push(make_pair(weights[adjacent_vertex], adjacent_vertex));
                
            }
            
        }
    }
    return weights[num_computer - 1];
    
}

int main()
{
    int num_testcase;
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++) {
        cin >> num_computer;
        cin >> num_edge;
        int vertex1;
        int vertex2;
        double weight;
        for (int k = 0; k < 10001; k++) {
            graph[k].clear();
        }
        for (int k = 0; k < num_computer; k++) {
            weights[k] = INF;
        }
        for (int j = 0; j < num_edge; j++) {
            cin >> vertex1;
            cin >> vertex2;
            cin >> weight;
            graph[vertex1].push_back(make_pair(weight, vertex2));
            graph[vertex2].push_back(make_pair(weight, vertex1));
        }
        cout << Dijkstra(0);
        
        
    }

    return 0;
}
