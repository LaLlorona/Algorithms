

#include <iostream>

using namespace std;

int cache[101][101];
String wildcard, original_text;
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
        index_text;;
    }
    
    //step 2: wildcard is finished
    if (index_wildcard == wildcard.size()) {
        return index_text == original_text.size();
    }

    //step 3: when wildcard[index_wildcard] is '*''  
    if (wildcard[index_wildcard] == '*') {
        for (int skip = 0; skip + index_text < original_text.size(); skip++) {
            if (MatchWildcardAndText(index_wildcard + 1, index_text + skip)){
                return true;
            }
        }
    }
    return false;
    
}
int main()
{
    cout<<"Hello World";

    return 0;
}
