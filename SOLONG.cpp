#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int ALPHABET = 26;

int ToNumber(char ch) { return ch - 'A'; }

struct TrieNode {
    TrieNode* children[ALPHABET];
  
    int terminal;
    int first;
    TrieNode() : terminal(-1), first(-1) {
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
    TrieNode* find(const char* key) {
        if (*key == 0) {
            return this;
        }
        else {
            int next = ToNumber(*key);
            if (children[next] == NULL) {
                return NULL;
            }
            else{
                return children[next]->find(key + 1);
            }
        }
    }
    int type(const char* key, int id) { // when typing until this node, to type key with id, how many times that we need to type more?
        if (*key == 0) {
            return 0;
        }
        if (first == id) {
            return 1;
        }
        else {
            int next = ToNumber(*key);
            return 1 + children[next]->type(key + 1, id);
        }
        
    }
  
};

int countKeys(TrieNode* trie, const char* word) {
    TrieNode* cand = trie->find(word);
    if (cand == NULL || cand->terminal == -1) {
        return strlen(word);
    }
    return trie->type(word, cand->terminal);
}

TrieNode* readInput(int words) { // this part should be implemented 
    vector<pair<int, string> > input;
    for (int i = 0; i < words; i++) {
        char buf[11];
        int freq;
        scanf("%s %d", buf, &freq);
        input.push_back(make_pair(-freq, buf));
    }
    sort(input.begin(), input.end());
    TrieNode* trie = new TrieNode();
    for (int i = 0; i < input.size(); i++) {
        trie->insert(input[i].second.c_str(), i);
    }
    trie->first = -1;
    return trie;
}
int main()
{
  int num_testcase;
  int num_words_total;
  int num_words_dict;
  
  int types;
  string word_string;
  const char* word;
  
  cin >> num_testcase;
  for (int i = 0; i < num_testcase; i++) {
      cin >> num_words_dict;
      cin >> num_words_total;
      types = 0;
      TrieNode* root = readInput(num_words_dict);
      for (int j = 0; j < num_words_total; j++) {
          cin >> word_string;
          word = word_string.c_str();
          types += countKeys(root, word);
      }
      types += num_words_total - 1;
      cout << types << endl;
      
  }

  return 0;
}
