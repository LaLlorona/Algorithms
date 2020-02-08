#include <iostream>
#include <queue>

using namespace std;

int num_people;
int num_jump;

void PrintTwoSurvivor() {
    queue<int> current_survivor;
    
    for (int i = 0; i < num_people; i++) {
        current_survivor.push(i + 1);
    }
    for (int i = 0; i < num_people - 2; i++) { // kill num_people -2 people 
        current_survivor.pop(); 
        for (int j = 0; j < num_jump - 1; j++) {
            int pass = current_survivor.front();
            current_survivor.pop();
            current_survivor.push(pass);
        }
    }
    
    int first_survivor = current_survivor.front();
    current_survivor.pop();
    int second_survivor = current_survivor.front();
    if (first_survivor > second_survivor) {
        cout << second_survivor << ' ' << first_survivor << endl;
    }
    else{
        cout << first_survivor << ' ' << second_survivor << endl;
    }
}
int main()
{
    int num_testcase;
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++) {
        cin >> num_people;
        cin >> num_jump;
        PrintTwoSurvivor();
    }
    

    return 0;
}
