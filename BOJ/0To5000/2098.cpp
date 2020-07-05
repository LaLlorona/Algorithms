#include <bits/stdc++.h>


using namespace std;

const int INF = 987654321;




int graph[16][16];
int num_city;
int cache[16][1 << 16]; //cache[path][last_visit] = cost


int TSP(int here, int visited) {
	
	if (visited == ((1 << num_city) - 1)) {
		if (graph[here][0] == 0) {
			return INF;
		}
		else {
			return graph[here][0];
		}
	}
	else {
		int& ret = cache[here][visited];
		if (ret != -1) {
			return ret;
		}
		ret = INF;
		for (int i = 0; i < num_city; i++) {
			if (graph[here][i] != 0) {
				if ((visited & (1 << i)) == 0) {
					ret = min(ret, graph[here][i] + TSP(i, (visited | (1 << i))));
				}
			}
		}
		return ret;
		
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_city) {
		int dist;
		
		memset(cache, -1, sizeof(cache));
		memset(graph, 0 ,sizeof(graph));
		for (int from = 0; from < num_city; from++) {
			for (int to = 0; to < num_city; to++) {
				cin >> dist;
				graph[from][to] = dist;
			}
		}
		
		cout << TSP(0, 1) << "\n";
		
		// for (int i = 0; i < num_city; i++) {
		// 	for (int j = 0; j < (1 << num_city); j++) {
		// 		cout << cache[i][j] << " ";	
		// 	}
		// 	cout << "\n";
		// }
	}
	
	


    

    return 0;
}

