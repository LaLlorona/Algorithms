#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num_box;
int num_children;
int dolls[100001], partialsum[100002], cache[100002];

void fillPartialSum() {
    partialsum[0] = 0;
    partialsum[1] = dolls[0] % num_children; 
    
    for (int i = 1; i < num_box; i++) {
        partialsum[i + 1] = (partialsum[i] + dolls[i]) % num_children;
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
            ret += have_seen[i] * (have_seen[i] - 1) / 2 % 20091101;
        }
    }
    return ret;
}

int calculateMultiplerOrder(int buy_until) {
    int& ret = cache[buy_until];
    int prev_same_index = -1;
    
    if (ret != -1) {
        return ret;
    }
    for (int i = buy_until; i >= 0; i--) {
        if (partialsum[i] == partialsum[buy_until + 1]) {
            prev_same_index = i;
            break;
        }
    }

    ret = calculateMultiplerOrder(buy_until - 1);
    
    if (prev_same_index != -1) {
        ret = max(ret, calculateMultiplerOrder(prev_same_index) + 1);
    }
    return ret;
    
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
        for (int j = 0; j < num_box + 1; j++) {
            cout << partialsum[j] << " ";
        }
        cout << endl;
        cout << calculateOneOrder() << endl;
        cout << calculateMultiplerOrder(num_box - 1);
    }
    

    return 0;
}
