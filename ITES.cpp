#include <iostream>
#include <queue>
using namespace std;

int target_sum;
int len_signal; 
unsigned int seed;

unsigned int RNG(unsigned int seed) {
    return seed * 214013 + 2531011;
}

int MeaningfulSignals() {
    seed = 1983;
    int sum = 0;
    int current_signal = 0;
    int ret = 0;
    queue<int> part;
    
    for (int i = 0; i < len_signal; i++) {
        current_signal = seed % 10000 + 1;
        part.push(current_signal);
        seed = seed * 214013u + 2531011u;
        sum += current_signal;
        
        if (current_signal >= target_sum) {
            if (current_signal == target_sum) {
                ret++;
            }
            sum -= part.front();
            part.pop();
        }
    }
    return ret;
}

int main()
{
    int num_testcase;
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++) {
        cin >> target_sum;
        cin >> len_signal;
        cout << MeaningfulSignals() << endl;
        
    }
    

    return 0;
}
