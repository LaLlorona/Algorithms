
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int num_village;
int target_day; // day n
int target_place; // prisoner's position at day n 
int jail; // position of the jail


double cache[101][51];

int village_map[51][51];
int num_adjacent_village[51];


double PossiblityDayPlace(int day, int place) {
    if (day == 0 && place == jail) {
        return 1;
    }
    if (day ==0 && place != jail) {
        return 0;
    }
    
    double& ret = cache[day][place];
    
    if (ret != -1) {
        return ret;
    }
    
    ret = 0;
    
    for (int i = 0; i < num_village; i++) {
        if (village_map[place][i] == 1) { //when i th village is adjacent to current place
            ret += PossiblityDayPlace(day - 1, i) / num_adjacent_village[i];
        }
    }
    
    return ret;
    
    
}
int main()
{
    cout.precision(11);
    cout << fixed;
    int num_testcase;
    int num_village_to_calculate;
    cin >> num_testcase;
    
    for (int i = 0; i < num_testcase; i++) {
        cin >> num_village;
        cin >> target_day;
        cin >> jail;
        
        for (int y = 0; y < 101; y++) {
            for (int x = 0; x < 51; x++) {
                cache[y][x] = -1;
            }
        }
        
        //filling village_map and num_adjacent_village
        int num_adjacent;
        for (int j = 0; j < num_village; j++) {
            num_adjacent = 0;
            for (int k = 0 ; k < num_village; k++) {
                cin >> village_map[j][k];
                if (village_map[j][k] == 1) {
                    num_adjacent++;
                }
            }
            num_adjacent_village[j] = num_adjacent;
        }
        
        
        cin >> num_village_to_calculate;
        for (int m = 0; m < num_village_to_calculate; m++) {
            cin >> target_place;
            cout << PossiblityDayPlace(target_day,target_place) << endl;
        }
    }
    

    return 0;
}
