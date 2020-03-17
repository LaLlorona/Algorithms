#include <iostream>
#include <queue>
using namespace std;

unsigned int target_sum;
int len_signal; 
unsigned int seed;

int MeaningfulSignals() {
    seed = 1983;
    unsigned int sum = 0;
    unsigned int current_signal = 0;
    int ret = 0;
    queue<unsigned int> part;
    int i = 0;
    while (i < len_signal) {
        
        if (sum < target_sum) {
            current_signal = seed % 10000u + 1u;
            part.push(current_signal);
            i++;
            seed = seed * 214013u + 2531011u;
            sum += current_signal;
        }
        
        if (sum >= target_sum) {
            if (sum == target_sum) {
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
