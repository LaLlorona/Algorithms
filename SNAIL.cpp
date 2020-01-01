#include <iostream>

using namespace std;

int deadline;
int standard_point;
float cache[1001][1001];

float PossibiltyToEscapeAtDayHeight(int height, int day) {
    if (height >= standard_point) {
        return 1;
    }
    
    if (day >= deadline) {
        return 0;
    }
    
    float& ret = cache[day][height];
    
    if (ret != -1) {
        return ret;
    }
    
    return ret = PossibiltyToEscapeAtDayHeight(day + 1, height + 2) * 0.75 + PossibiltyToEscapeAtDayHeight(day + 1, height + 1) * 0.25;
    
    

}
int main()
{
    int num_testcase;
    
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++) {
        cin >> standard_point;
        cin >> deadline;
        for (int j = 0; j < 1001; j++) {
            for (int k = 0; k < 1001; k++) {
                cache[j][k] = -1;
            }
        }
        cout << PossibiltyToEscapeAtDayHeight(0,0) << endl;
    }

    return 0;
}
