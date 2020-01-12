#include <iostream>

using namespace std;

int num_camera;
int num_stations;
double position_stations[200];

bool PossibleToPlace(double minimum_interval) {
    int placed_camera = 1;
    double position_last_stations = position_stations[0];
    
    for (int i = 1; i < num_stations ; i++) {
        if (position_stations[i] - position_last_stations >= minimum_interval) { // when it is possible to place a camera in ith station 
            placed_camera++;
            position_last_stations = position_stations[i];
        }
    }
    return placed_camera >= num_camera;
}

double BinarySearch() {
    double low = 0;
    double high = 241;
    
    for (int i = 0; i < 100 ; i++) {
        double mid = (low + high) / 2.0;
        if (PossibleToPlace(mid)) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return low;
}

int main()
{
    cout.precision(2);
    cout << fixed;
    int num_testcase;
    cin >> num_testcase;
    for (int i = 0 ; i < num_testcase; i++) {
        cin >> num_camera;
        cin >> num_stations;
        for (int j = 0; j < num_stations; j++) {
            cin >> position_stations[j]; 
        }
        cout << BinarySearch() << endl;
    }
    
    

    return 0;
}
