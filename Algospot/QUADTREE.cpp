#include <iostream>
#include <vector>
using namespace std;


string ReverseQuadTree(string::iterator& string_pointer) {
    char current_word = *string_pointer;
    string_pointer++;
    
    if (current_word == 'b' || current_word == 'w'){
        return string(1,current_word);
    }
    
    else{
        string upper_left = ReverseQuadTree(string_pointer);
        string upper_right = ReverseQuadTree(string_pointer);
        string lower_left = ReverseQuadTree(string_pointer);
        string lower_right = ReverseQuadTree(string_pointer);
        
        return "x" + lower_left + lower_right + upper_left + upper_right;
    }
}



int main()
{
    int num_testcase;
    string quadtree;
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++) {
        cin >> quadtree;
        string::iterator pointer = quadtree.begin();
        cout << ReverseQuadTree(pointer) << endl;
    }
    
    

    return 0;
}
