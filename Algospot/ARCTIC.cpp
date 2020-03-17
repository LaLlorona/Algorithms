/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <math.h>
#include <queue>



using namespace std;

int num_base;
double x_coordinates[100], y_coordinates[100];
double base_map[100][100];


void PreProcess() { // fill the base map
    for (int from = 0; from < 100; from++) {
        for (int to = 0; to < 100 ; to++) {
            base_map[from][to] = sqrt(pow(y_coordinates[to] - y_coordinates[from], 2) + pow(x_coordinates[to] - x_coordinates[from], 2));
        }
    }
}

bool PossibleToCommunicate(double radio_range) {
    vector<bool> visited(num_base, false);
    visited[0] = true;
    queue<int> bfs_queue;
    bfs_queue.push(0);
    int num_visited = 1;
    
    while(!bfs_queue.empty()) { // BFS search 
        int from = bfs_queue.front();
        bfs_queue.pop();
        
        for (int to = 0; to < num_base; to++) {
            if ((base_map[from][to] <= radio_range) && !visited[to]) { // when base to go is closer than radio_range and not visited
                bfs_queue.push(to);
                visited[to] = true;
                num_visited++;
            }
        }
    }
    
    return num_visited == num_base;
    
}

double BinarySearch() {
    double low = 0;
    double high = 1001;
    double mid = 0;
    
    for (int i = 0; i < 100; i++) {
        mid = (low + high) / 2.0;
        if (PossibleToCommunicate(mid)) {
            high = mid;
        }
        else{
            low = mid;
        }
    }
    return low;
    
}
int main()
{
    int num_testcase;
    cout.precision(2);
    cout << fixed;
    
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++) {
        cin >> num_base;
        for (int j = 0; j < num_base; j++) {
            cin >> x_coordinates[j];
            cin >> y_coordinates[j];
        }
        PreProcess();
        cout << BinarySearch() << endl;
    }
    
    

    return 0;
}
