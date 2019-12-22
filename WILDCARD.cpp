#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int cache[101][101];
string wildcard, original_text;

bool MatchWildcardAndText(int index_wildcard, int index_text) {
    int& ret = cache[index_wildcard][index_text];
    if (ret != -1) {
        return ret;
    }
    ret = 0;
    
    // step1 : skip until both strings are same
    while (index_wildcard < wildcard.size() && index_text < original_text.size() && 
    (wildcard[index_wildcard] == '?' || wildcard[index_wildcard] == original_text[index_text])) {
        index_wildcard++;
        index_text++;
    }
    
    //step 2: wildcard is finished
    if (index_wildcard == wildcard.size()) {
        if (index_text == original_text.size()) {
            ret = 1;
            return ret;
        }
        else{
            ret = 0;
            return ret;
        }
    }

    //step 3: when wildcard[index_wildcard] is '*'
    if (wildcard[index_wildcard] == '*') {
        for (int skip = 0; skip + index_text <= original_text.size(); skip++) {
            if (MatchWildcardAndText(index_wildcard + 1, index_text + skip)){
                ret = 1;
                return true;
            }
        }
    }
    ret = 0;
    return false;
    
}
int main()
{
    int num_testcase;
    int num_original_text;
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++) {
        cin >> wildcard;
        cin >> num_original_text;
        vector<string> possible_text;
        for (int j = 0; j < num_original_text; j++) {
            memset(cache,-1,sizeof(cache));
            cin >> original_text;
            if (MatchWildcardAndText(0,0)) {
                possible_text.push_back(original_text);
            }
        }
        sort(possible_text.begin(),possible_text.end());
        for (int k = 0; k < possible_text.size(); k++){
            cout << possible_text[k] << endl;
        }
    }
    return 0;
}
