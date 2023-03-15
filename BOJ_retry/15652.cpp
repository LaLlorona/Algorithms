#include <bits/stdc++.h>

using namespace std;
const int MAX = 10;
int N, M;
bool visited[MAX]; 
vector<int> middleResult;

void PrintMiddleResult() {
    for (int i = 0 ; i < middleResult.size(); i ++) {
        cout << middleResult[i] << " ";
    }
    cout << "\n";
}

void Dfs(int numSelected, int minNum) {

    if (numSelected == M) {
        PrintMiddleResult();
        return;
    }

    for (int i = 0; i < N; i++) {

        if (i >= minNum) {
            middleResult.push_back(i + 1);
            Dfs(numSelected + 1, i);
            middleResult.pop_back();
        }
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
        middleResult.clear();

        Dfs(0, 0);
    }

    

}


  