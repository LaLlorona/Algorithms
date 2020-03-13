#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <string.h> 

using namespace std;

const int INF = 987654321;
int num_vertex;

const int MAX_V = 500;

int capacity[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];
int num_player;
int num_games;
int wins[20]; // saves current wins for each plyaer
int match[200][2]; // saves two participants' back number 



int FordFulkerson(int source, int sink) {
	
	int ret = 0;
	memset(flow, 0, sizeof(flow));
	while (true) {
		vector<int> parent(MAX_V, -1);
		queue<int> bfs_queue;
		
		bfs_queue.push(source);
		parent[source] = source;
		
		while (!bfs_queue.empty() && parent[sink] == -1) {
			int v = bfs_queue.front();
			bfs_queue.pop();
			
			for (int i = 0; i < num_vertex; i++) {
				if (capacity[v][i] - flow[v][i] > 0 && parent[i] == -1) {
					bfs_queue.push(i);
					parent[i] = v;
				}
			}
		}
		
		if (parent[sink] == -1) {
			break;
		}
		int current_vertex = sink;
		int max_flow = INF;
		
		while (current_vertex != source) {
			int parent_current_vertex = parent[current_vertex];
			max_flow = min(max_flow, capacity[parent_current_vertex][current_vertex] - flow[parent_current_vertex][current_vertex]);
			current_vertex = parent_current_vertex;
		}
		
		current_vertex = sink;
		
		while (current_vertex != source) {
			int parent_current_vertex = parent[current_vertex];
			flow[parent_current_vertex][current_vertex] += max_flow;
			flow[current_vertex][parent_current_vertex] -= max_flow;
			current_vertex = parent_current_vertex;
			
		}
		ret += max_flow;
		
		
		
	}
	return ret;
}


bool CanWinWith (int total_wins) {
	if (*max_element(wins + 1, wins + num_player) >= total_wins) {
		return false;
	}
	
	num_vertex = num_games + num_player + 2;
	
	memset(capacity, 0, sizeof(capacity));
	
	for (int i = 0; i < num_games; i++) {
		capacity[0][2 + i] = 1;
		for (int j = 0; j < 2; j++) {
			capacity[2 + i][2 + num_games + match[i][j]] = 1;
		}
		
	}
	for (int i = 0; i < num_player; i++) {
		int max_win = (i == 0? total_wins : total_wins - 1);
		capacity[2 + num_games + i][1] = max_win - wins[i];
	}
	return FordFulkerson(0, 1) == num_games;
}

int main()
{
	
	
	int num_testcase;
	cin >> num_testcase;
	for (int iter = 0; iter < num_testcase; iter++) {
		int opportunity = 0;
		cin >> num_player;
		cin >> num_games;
		for (int j = 0; j < num_player; j++) {
			cin >> wins[j];
		}
		
		for (int j = 0; j < num_games; j++) {
			int player1;
			int player2;
			cin >> player1;
			cin >> player2;
			match[j][0] = player1;
			match[j][1] = player2;
			if (player1 == 0 || player2 == 0) {
				opportunity++;
			}	
		}
		
		for (int i = 0; i <= opportunity + 1; i++) {
			if (i == opportunity + 1) {
				cout << -1 << endl;
				break;
			}
			else if (CanWinWith(wins[0]+ i)) {
				cout << wins[0]+ i << endl;
				break;
			}
			
		}
		
	}
	
    return 0;
}

