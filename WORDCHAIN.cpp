
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num_words;

vector<string> graph[26][26];
vector<vector<int> > adjacent; //number of adjacent vertex between ith, jth edge
vector<int> indegree, outdegree;
vector<int> result_circuit;

void MakeGraph(vector<string>& words) {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            graph[i][j].clear();
        }
    } // clear the graph
    
    adjacent = vector<vector<int> > (26, vector<int>(26 , 0));
    indegree = outdegree = vector<int> (26, 0);
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        int begin_word = word[0] - 'a';
        int last_word = word[word.size() - 1] - 'a';
        
        graph[begin_word][last_word].push_back(word); 
        adjacent[begin_word][last_word]++;
        indegree[last_word]++;
        outdegree[begin_word]++;
    } // fill the graph
    
    
    
}


void GetEulerCircuit(int here, vector<int>& circuit) { // find circuit that goes through every EDGES of the graph
    for (int there = 0; there < 26; there++) {
        while (adjacent[here][there] > 0) {
            adjacent[here][there]--;
            GetEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}

vector<int> GetEulerCircuitOrTrail() {
    vector<int> circuit;
    for (int i = 0; i < 26; i++) {
        if (outdegree[i] == indegree[i] + 1) {
            GetEulerCircuit(i, circuit);
            return circuit;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        if (outdegree[i]) {
            GetEulerCircuit(i, circuit);
            return circuit;
        }
    }
    
    return circuit;
}

bool CheckExistenceEuler() {
    int flag_out_one_more = 0;
    int flag_in_one_more = 0;
    int out_minus_in = 0;
    for (int i = 0; i < 26; i++) {
        out_minus_in = outdegree[i] - indegree[i];
        if (out_minus_in > 1 || out_minus_in < -1) {
            return false;
        }
        if (out_minus_in == 1) {
            flag_out_one_more++;
        }
        else if (out_minus_in == -1) {
            flag_in_one_more++;
        }
    }
    if ((flag_in_one_more == 1 && flag_out_one_more == 1) || (flag_out_one_more == 0 && flag_in_one_more == 0)) {
        return true;
    }
    return false;
}

string solve(vector<string>& words) {
    MakeGraph(words);
    if (!CheckExistenceEuler()) {
        return "IMPOSSIBLE";
    }
    vector<int> euler = GetEulerCircuitOrTrail();
    if (euler.size() != words.size() + 1) {
        return "IMPOSSIBLE";
    }
    reverse(euler.begin(), euler.end());
    
    string ret;
    for (int i = 1; i < euler.size(); i++) {
        int begin_word = euler[i - 1];
        int last_word = euler[i];
        if (ret.size()) {
            ret += " ";
        }
        ret += graph[begin_word][last_word].back();
        graph[begin_word][last_word].pop_back();
    }
    return ret;
}
int main()
{
    int num_testcase;
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++) {
        cin >> num_words;
        vector<string> given_words;
        string word_testcase;
        for (int j = 0; i < num_words; j++) {
            cin >> word_testcase;
            given_words.push_back(word_testcase);
        }
        solve(given_words);
    }

    return 0;
}
