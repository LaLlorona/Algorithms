
#include <iostream>
#include <queue>
using namespace std;

int len_sequence;
int seed_a;
int seed_b;

struct RNG{
    int seed, a, b;
    RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}
    int next() {
        int ret = seed;
        seed = (seed * ((long long) a) + b) % 20090711;
        return ret;
    }
};
int RunningMedian(RNG rng) {
    priority_queue<int, vector<int>, less<int> > max_queue; // save smaller half of the sequence
    priority_queue<int, vector<int>, greater<int> > min_queue; // save larger half of the sequence
    int ret = 0;
    int max_queue_top;
    int min_queue_top;
    for (int i = 0; i < len_sequence; i++) {
        if (max_queue.size() == min_queue.size()) {
            max_queue.push(rng.next());
        }
        else {
            min_queue.push(rng.next());
        }
    
        
    
        if ((!max_queue.empty() && !min_queue.empty()) && max_queue.top() > min_queue.top()) {
            max_queue_top = max_queue.top();
            min_queue_top = min_queue.top();
            max_queue.pop();
            min_queue.pop();
            max_queue.push(min_queue_top);
            min_queue.push(max_queue_top);
        }  
        ret  = (ret + max_queue.top()) % 20090711;
    }
    
    return ret;
    
    
}

int main()
{
    int num_testcase;
    cin >> num_testcase;
    
    for (int i = 0; i < num_testcase; i++) {
        cin >> len_sequence;
        cin >> seed_a;
        cin >> seed_b;
        RNG rng = RNG(seed_a, seed_b);
        cout << RunningMedian(rng) << endl;
    }
    

    return 0;
}
