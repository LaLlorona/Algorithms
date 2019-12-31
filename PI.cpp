
#include <iostream>

using namespace std;

string original_text;

int Classify(string partition) {
    
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
    
}

int main()
{
    cout << Classify("333") << endl;
    cout << Classify("23456") << endl;
    cout << Classify("987") << endl;
    cout << Classify("3232") << endl;
    cout << Classify("87878") << endl;
    cout << Classify("147") << endl;
    cout << Classify("8642") << endl;
}
