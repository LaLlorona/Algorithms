
#include <iostream>
#include <cmath>

using namespace std;
const int MAX_NUM = 10000000;

int min_factor[MAX_NUM + 1]; // min_factor[i] is minimum factor of integer i
int power_factor[MAX_NUM + 1]; // power_factor[i] is power of minimum factor of integer i
int num_factor[MAX_NUM + 1]; // num_factor is number of total factor of integer i

int target_num_divisor;
int range_low;
int range_high;

void calculateMinFactor() { //fill min_factor
    min_factor[0] = 0;
    min_factor[1] = 1;
    min_factor[2] = 2;
    for (int n = 2; n <= MAX_NUM; n++) {
        min_factor[n] = n;
    }
    int sqrn = int(sqrt(MAX_NUM));
    for (int n = 2; n <= sqrn; n++) {
        if (min_factor[n] == n) { // when n is a prime number
            for (int mul = n * n; mul <= MAX_NUM; mul += n) {
                if (min_factor[mul] == mul) {
                    min_factor[mul] = n;
                }
                
            }
        }
        
    }
}
void calculateNumFactor() {
    num_factor[1] = 1;
    power_factor[1] = 0;
    min_factor[1] = 1;
    
    for (int n = 2; n <= MAX_NUM; n++) {
        
        if (min_factor[n] == n) { // when n is a prime number
            power_factor[n] = 1;
            num_factor[n] = 2;
            
        }
        else { // when n is not a prime number 
            int m = n / min_factor[n];
            if (min_factor[m] == min_factor[n]) {
                power_factor[n] = power_factor[m] + 1;
                num_factor[n] = num_factor[m] * (power_factor[m] + 2) / (power_factor[m] + 1);
            }
            else{
                power_factor[n] = 1;
                num_factor[n] = num_factor[m] * 2;
            }
        }
    }
}
int main()
{
    int num_testcase;
    calculateMinFactor();
    calculateNumFactor();
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++) {
        cin >> target_num_divisor;
        cin >> range_low;
        cin >> range_high;
        int num_candidate = 0;
        
        
        for (int candidate = range_low; candidate <= range_high; candidate++) {
            if (num_factor[candidate] ==target_num_divisor) {
                num_candidate++;
            }
        }
        cout << num_candidate << endl;
        
    }
    

    return 0;
}
