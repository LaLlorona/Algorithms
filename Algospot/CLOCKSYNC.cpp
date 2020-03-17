
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > button({
    vector<int>( { 0, 1, 2 }),
    vector<int>( { 3, 7, 9, 11 }),
    vector<int>( { 4, 10, 14, 15 }),
    vector<int>( { 0, 4, 5, 6, 7 }),
    vector<int>( { 6, 7, 8, 10, 12 }),
    vector<int>( { 0, 2, 14, 15 }),
    vector<int>( { 3, 14, 15 }),
    vector<int>( { 4, 5, 7, 14, 15 }),
    vector<int>( { 1, 2, 3, 4, 5 }),
    vector<int>( { 3, 4, 5, 9, 13 })
});

int num_testcase;
vector<int> input_clock_state(16);

const int INF = 9999;

int UpdateClock(int clock_time) {
    int updated_time = clock_time + 3;
    return updated_time % 12;
    
}

int ChooseMinimum(int x, int y){
    if (x > y){
        return y;
    }
    else {
        return x;
    }
}


int NumButtonPush(vector<int>& clock_state, int current_button){
    bool is_clock_synchronized = true;
  
    for (int i = 0; i < 16; i++) {
        if (clock_state[i] != 0) {
            is_clock_synchronized = false;
        }
    }
    if (current_button >= 10) {
        if (is_clock_synchronized) {
            return 0;
        }
        else {
            return INF;
        }
    }
    
    int ret = INF;
    for (int push = 0; push < 4; push++) {
        ret = ChooseMinimum(ret, NumButtonPush(clock_state, current_button + 1) + push);
        for (int affected_clock = 0; affected_clock < button[current_button].size() ; affected_clock++) {
            int time_to_update = button[current_button][affected_clock];
            clock_state[time_to_update] = UpdateClock(clock_state[time_to_update]);
        }
        
    }
    return ret;
  
}

int ReturnMinusOneWhenInfinite(int input){
    if (input == INF) {
        return -1;
    }
    return input;
    
}

void checkAnswer(){
    cin >> num_testcase;
    for (int test = 0; test < num_testcase; test++){
        for (int i = 0; i < 16; i++) {
            int hour;
            cin >> hour;
            input_clock_state[i] = hour % 12;
        }
        cout << ReturnMinusOneWhenInfinite(NumButtonPush(input_clock_state,0)) << endl;
    }
    
  
}

int main()
{
    checkAnswer();

    return 0;
}
