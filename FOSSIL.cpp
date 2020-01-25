
#include <iostream>
#include <vector>
#include <utility>


using namespace std;

int num_points_first_polygon;
int num_points_second_polygon;
double x_first_polygon[100], y_first_polygon[100], x_second_polygon[100], y_second_polygon[100];


int main()
{
    int num_testcase;
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++) {
        cin >> num_points_first_polygon;
        cin >> num_points_second_polygon;
        for (int j = 0; j < num_points_first_polygon; j++) {
            cin >> x_first_polygon[j];
            cin >> y_first_polygon[j];
        }
        for (int k = 0; k < num_points_second_polygon; k++) {
            cin >> x_second_polygon[k];
            cin >> y_second_polygon[k];
        }
    }
    
    cout<<"Hello World";

    return 0;
}
