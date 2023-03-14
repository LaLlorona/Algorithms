#include <bits/stdc++.h>

using namespace std;


int n, m;
const int MAX = 9;


vector<int> sequence;

void PrintVector() {
    for (int i = 0 ; i < m; i++) {
        cout << sequence[i] << " ";
    }
    cout << "\n";
}

void DFS(int numChosen, int minNum) {
    if (numChosen == m) {
        PrintVector();
    }

    else if (numChosen !=m && minNum >= n) {
        return;
    }

    for (int i = minNum; i < n; i++) {

        sequence.push_back(i + 1);

        DFS(numChosen + 1, i + 1);


        sequence.pop_back();


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
 
        sequence.clear();
        DFS(0, 0);
    }

    

    

}

