#include <bits/stdc++.h>

using namespace std;


int n, m;
const int MAX = 9;

vector<int> backtrackingVector;
bool visited[MAX] ;


void PrintVector() {
    for (int i = 0; i < m; i++) {
        cout << backtrackingVector[i] << " ";
    }
    cout << "\n";
}

void DFS(int counter) {
    if (counter == m) {
        PrintVector();
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;   
        }
        visited[i] = true;
        backtrackingVector.push_back(i + 1);
        DFS(counter + 1);
       

        visited[i] = false;
        backtrackingVector.pop_back();
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

    while (cin >> n >> m) {
        backtrackingVector.clear();
        DFS(0);
    }

    

}

