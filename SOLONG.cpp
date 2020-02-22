#include <iostream>
#include <cstring>

using namespace std;

const int ALPHABET = 26;

int ToNumber(char ch) { return ch - 'A'; }

struct TrieNode {
  TrieNode* children[ALPHABET];
  
  int terminal;
  int first;
  
  TrieNode() : terminal(-1) {
    memset(children, 0, sizeof(children));
      
  }
  ~TrieNode() {
    for (int i = 0; i < ALPHABET; i++) {
        if (children[i]) {
        delete children[i];
        }
    }
  }
  
  void insert(const char* key, int id) { // insert a word with id 
    if (first == -1) {
        first = id;
    }  
    
    if (*key == 0) {
        terminal = id;
    }
    
    else {
        int next = ToNumber(*key);
        if (children[next] == NULL) {
        children[next] = new TrieNode();
        }
    children[next]->insert(key + 1, id); 
    }
  }
  int type(const char* key, int id) { // when typing until this node, to type key with id, how many times that we need to type more?
    
  }
  
};
int main()
{
  cout<<"Hello World";

  return 0;
}
