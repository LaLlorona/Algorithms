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


void PreProcess() { // fill the base map;
    for (int from = 0; from < 100; from++) {
        for (int to = 0; to < 100 ; to++) {
            base_map[from][to] = sqrt(pow(y_coordinates[to] - y_coordinates[from], 2) + pow(x_coordinates[to] - x_coordinates[from], 2);
        }
    }
}

bool PossibleToCommunicate(double radio_range) {
    vector<bool> visited(num_base, false);
    visited[0] = true;
    queue<int> bfs_queue;
    bfs_queue.push(0);
}
int main()
{
    int num_testcase;
    
    cout<<"Hello World";

    return 0;
}
