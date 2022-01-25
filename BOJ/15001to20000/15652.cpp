#include <bits/stdc++.h>

using namespace std;
const int MAX = 10;
int N, M;
bool visited[MAX]; 
vector<int> middle_result;



void Dfs(int numChosen, int minNum) {
    if (numChosen == M) {
        for (int i = 0; i < middle_result.size(); i++) {
            cout << middle_result[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = minNum; i < N; i++) {
        middle_result.push_back(i + 1);
        Dfs(numChosen + 1, i);
        middle_result.pop_back();
    }
    

    
    
    
}
int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    // std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); 
	// std::cin.rdbuf(in.rdbuf()); 

    
    while (cin >> N >> M) {
        memset(visited, 0, sizeof(visited));
       
       
        middle_result.clear();

        Dfs(0, 0);

        
    }
}


  