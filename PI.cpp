#include <iostream>
#include <cstring>

using namespace std;

string original_text;
int cache[10001];
const int INF = 987654321;

int Classify(string partition) {
    
    // difficulty 10 : size is smaller than 3
    if (partition.size() < 3) {
        return 10;
    }
    // difficulty 1
    if (partition == string(partition.size(),partition[0])) {
        return 1;
    }
    // difficulty 2
    
    bool progression_with_one = true;
    bool progression = true;
    for (int i = 0; i < partition.size() - 1; i++) {
        if (partition[i + 1] - partition[i] != partition[1] - partition[0]) {
            progression_with_one = false;
            progression = false;
        }
        if ((partition[1] - partition[0] != 1) && (partition[1] - partition[0] != -1)) {
            
            progression_with_one = false;
        }
    }
    if (progression_with_one) return 2;
    
    
    // difficulty 4
    bool alternative = true;
    for (int j = 0; j < partition.size() - 2; j += 2){
        if (partition[j] != partition[j + 2]) {
            alternative = false;
        }
    }
    for (int k = 1 ; k < partition.size() -2; k += 2) {
        if (partition[k] != partition[k + 2]) {
            alternative = false;
        }
    }
    if (alternative) return 4;
    
    // difficulty 5
    if (progression) return 5;

    // difficulty 10
    return 10;
}

int TotalDifficulty(int index_start) {
    if (index_start >= original_text.size()) {
        return 0;
    }
    
    int& ret = cache[index_start];
    
    if (ret != -1) {
        return ret;
    }
    
    ret = INF;
    for (int size = 3 ; size < 6; size++ ) {
        ret = min(ret, TotalDifficulty(index_start + size) + Classify(original_text.substr(index_start,size)));
    }
    
    return ret;
    
    
    
    
    
    
}

int main()
{
    int num_testcase;
    cin >> num_testcase;
    
    for (int i = 0; i < num_testcase; i++) {
        cin >> original_text;
        memset(cache,-1,sizeof(cache));
        cout << TotalDifficulty(0) << endl;
    }
}
