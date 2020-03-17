
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> KMPFailFunction(string &input) {
    int begin = 1;
    int match = 0;
    int len = input.size();
    vector<int> fail_function(len, 0);
    while (begin + match < len) {
        
        if (input[begin + match] == input[match]) {
            match++;
            fail_function[begin + match - 1] = match;
        }
        else{
            if (match == 0) {
                begin++;
            }
            else{
                begin += match - fail_function[match - 1];
                match = fail_function[match - 1];  
            }
            
        }
    }
    return fail_function;
}
int main()
{
    string input1;
    string input2;
    cin >> input1;
    cin >> input2;
    string input = input1 + input2;
    vector<int> fail_function = KMPFailFunction(input);
    vector<int> possible_length;
    
    int k = fail_function.size();
    while (k > 0) {
        possible_length.push_back(k);
        k = fail_function[k - 1];
    }
    sort(possible_length.begin(), possible_length.end());
    
    for (int i = 0; i < possible_length.size(); i++) {
        cout << possible_length[i] << " ";
    }
    
    

    return 0;
}
