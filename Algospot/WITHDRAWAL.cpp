#include <iostream>
#include <algorithm>

using namespace std;

int num_courses;
int num_minimum_courses;
double list_total_students[1000];
double list_my_grade[1000];
double list_standard[1000];

bool PossibleToGetCumulativeRankLessThan(double threshold) {
    double decision = 0;
    
    for (int i = 0 ; i < num_courses; i++) {
        list_standard[i] = threshold * list_total_students[i] - list_my_grade[i];
    }
    sort(list_standard, list_standard + num_courses, greater<double>());
    
    for (int j = 0; j < num_minimum_courses; j++) {
        decision += list_standard[j];
    }
    
    return (decision >= 0.0);
    
}

double BinarySearch() {
    double low = -1e-9;
    double high = 1.0;
    double mid = 0.0;
    
    for (int i = 0; i < 100; i++) {
        mid = (low + high) / 2.0;
        if (PossibleToGetCumulativeRankLessThan(mid)) {
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
    cin >> num_testcase;
    cout.precision(10);
    cout << fixed;
    for (int i = 0; i < num_testcase; i++) {
        cin >> num_courses;
        cin >> num_minimum_courses;
        
        for (int j = 0; j < num_courses; j++) {
            cin >> list_my_grade[j];
            cin >> list_total_students[j];
        }
        
        
        
        cout << BinarySearch() << endl;
        
    }
    

    return 0;
}
