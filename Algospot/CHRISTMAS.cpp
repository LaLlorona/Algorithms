  
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int num_box;
int num_children;
int dolls[100001], partialsum[100002];

void fillPartialSum() {
    partialsum[0] = 0;
    
    for (int i = 1; i < num_box + 1; i++) {
        partialsum[i] = (partialsum[i - 1] + dolls[i - 1]) % num_children;
    }
}
long long calculateOneOrder() {
    vector<long long>have_seen(num_children, 0);
    long long ret = 0;
    for (int i = 0; i < num_box + 1; i++) {
        have_seen[partialsum[i]]++;
    }
    for (int i = 0; i < num_children; i++) {
        if (have_seen[i] >= 2) {
            ret = (ret +(have_seen[i] * (have_seen[i] - 1) / 2)) % 20091101;
        }
    }
    return ret;
}

int calculateMultiplerOrder() {
    // int& ret = cache[buy_until];
    // int& prev_same_index = prevcache[buy_until];
    
    
    // if (ret != -1) {
    //     return ret;
    // }
    // if (prev_same_index == -1) {
    //   for (int i = buy_until; i >= 0; i--) {
    //         if (partialsum[i] == partialsum[buy_until + 1]) {
    //             prev_same_index = i;
    //             break;
    //         }
    //     } 
    // }
    

    // ret = calculateMultiplerOrder(buy_until - 1);
    
    // if (prev_same_index != -1) {
    //     ret = max(ret, calculateMultiplerOrder(prev_same_index) + 1);
    // }
    // return ret;
    vector<int> ret(num_box + 1, 0);
    vector<int> prev(num_children, -1);
    for (int i = 0; i < num_box + 1; i++) {
        if (i > 0) {
            ret[i] = ret[i-1];
        }
        else{
            ret[i] = 0;
        }
        int loc = prev[partialsum[i]];
        if (loc != -1) {
            ret[i] = max(ret[i], ret[loc] + 1);
        }
        prev[partialsum[i]] = i;
    }
    return ret.back();
    
}

int main()
{
    int num_testcase;
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++) {
        cin >> num_box;
        cin >> num_children;
        
        
        for (int k = 0; k < num_box; k++) {
            cin >> dolls[k];
        }
        fillPartialSum();
        cout << calculateOneOrder() << " ";
        cout << calculateMultiplerOrder() << endl;;
    }
    

    return 0;
}
