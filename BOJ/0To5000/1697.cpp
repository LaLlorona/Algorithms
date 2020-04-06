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
const int INF = 987654321;
bool visited[100001];
int departure;
int destination;
int current_best = INF;


int ShortestTime(int from, int to) {
	queue<pair<int, int> > BFS_queue;
	BFS_queue.push(make_pair(from, 0));
	while (true) {
		int here = BFS_queue.front().first;
		int elapsed_time = BFS_queue.front().second;
		BFS_queue.pop();
		if (here == to) {
			return elapsed_time;
		}
		else if (here <= 100000 && here >= 0 && !visited[here] ){
			visited[here] = true;
			BFS_queue.push(make_pair(here * 2, elapsed_time + 1));
			BFS_queue.push(make_pair(here + 1, elapsed_time + 1));
			BFS_queue.push(make_pair(here - 1, elapsed_time + 1));
		}
		
	}
	
	
	
	
	
	
}


int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> departure >> destination) {
		memset(visited, 0 ,sizeof(visited));
		cout << ShortestTime(departure, destination);
		
	}
    

    return 0;
}

