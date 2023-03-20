#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;

int distanceFrom[MAX];

int N, K;

bool IsInBoundary(int n) {
    return (n >= 0 && n < MAX);
}

int FastestFromNToK() {
    int here = N;
    if (here == K) {
        return 0;
    }
    queue<int> bfsQueue;

    bfsQueue.push(here);
    distanceFrom[here] = 0;

    while(!bfsQueue.empty()) {
        int here = bfsQueue.front();
        bfsQueue.pop();

        int next[3] = {here + 1, here - 1, here * 2};

        for (int i = 0; i < 3; i++) {
            if (next[i] == K) {
                return distanceFrom[here] + 1;
            }
            if (IsInBoundary(next[i]) && distanceFrom[next[i]] == -1) {
                distanceFrom[next[i]] = distanceFrom[here] + 1;
                bfsQueue.push(next[i]);
            }
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

    while (cin >> N >> K) {
        memset(distanceFrom, -1, sizeof(distanceFrom));
        cout << FastestFromNToK() << "\n";


    }

}


  