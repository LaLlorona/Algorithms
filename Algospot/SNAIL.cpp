#include <iostream>

using namespace std;

int deadline;
int standard_point;
double cache[1001][2002];

double PossibiltyToEscapeAtDayHeight(int height, int day) {
    if (height >= standard_point) {
        return 1;
    }
    
    if (day >= deadline) {
        return 0;
    }
    
    double& ret = cache[day][height];
    
    if (ret != -1) {
        return ret;
    }
    
    return ret = PossibiltyToEscapeAtDayHeight(height + 2, day + 1) * 0.75 + PossibiltyToEscapeAtDayHeight(height + 1, day + 1) * 0.25;
    
    

}
int main()
{
    cout.precision(11);
    cout << fixed;
    int num_testcase;
    
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++) {
        cin >> standard_point;
        cin >> deadline;
        for (int j = 0; j < 1001; j++) {
            for (int k = 0; k < 2002; k++) {
                cache[j][k] = -1;
            }
        }
        cout << PossibiltyToEscapeAtDayHeight(0,0) << endl;
    }

    return 0;
}
