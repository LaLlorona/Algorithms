#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>



using namespace std;

int n;
int wanted[100002];
int visited[100002];
int done[100002];
int counter = 0;

void DFS(int here) {
	visited[here] = true;
	int next = wanted[here];
	if (!visited[next]) {
		DFS(next);
	}
	else if (visited[next] && !done[next]) {
		for (int i = next; i != here; i = wanted[i]) {
			counter++;
			
		}
		counter++;
		
	}
	done[here] = true;
} 

int main()
{
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	int num_testcase;
	cin >> num_testcase;
	
	while (num_testcase--) {
		cin >> n;
		memset(visited, 0, sizeof(visited));
		memset(done, 0 ,sizeof(done));
		counter = 0;
		for (int i = 1; i <= n; i++) {
			cin >> wanted[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				DFS(i);
			}
		}
		cout << n - counter << endl;
	}
    

    return 0;
}

