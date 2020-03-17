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
int board_size;

const int MAX_V = 500;

int chess_board[8][8];
int biparty[8][8][2];

int capacity[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];



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

void make_graph() {
	int dx[2] = {-1 ,1};
	int dy[2] = {1, 1};
	int count = 2;
	memset(biparty, -1, sizeof(biparty));
	
	for (int y = 0; y < board_size; y++) {
		for (int x = 0; x < board_size; x++) {
			if (chess_board[y][x] == 1){
				int current_x = x;
				int current_y = y;
				bool updated = false;
				while (current_x >= 0 && current_y >= 0 && current_x < board_size && current_y < board_size && biparty[current_y][current_x][0] == -1 && chess_board[current_y][current_x] == 1) {
					biparty[current_y][current_x][0] = count;
					current_x += dx[0];
					current_y += dy[0];
					updated = true;
				}
				if (updated) {
					count++;
				}
				current_x = x;
				current_y = y;
				updated = false;
				while (current_x >= 0 && current_y >= 0 && current_x < board_size && current_y < board_size && biparty[current_y][current_x][1] == -1 && chess_board[current_y][current_x] == 1) {
					biparty[current_y][current_x][1] = count;
					current_x += dx[1];
					current_y += dy[1];
					updated = true;
				}
				if (updated) {
					count++;
				}
				
			}
		}
	}
	num_vertex = count;
	for (int y = 0; y < board_size; y++) {
		for (int x = 0; x < board_size; x++) {
			int group1 = biparty[y][x][0];
			int group2 = biparty[y][x][1];
			
			if (group1 != -1 && group2 != -1) {
				
				
				capacity[0][group1] = 1;
				capacity[group1][group2] = 1;
				capacity[group2][1] = 1;
			}
		}
	}
	
}






int main()
{
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	
	int num_testcase;
	cin >> num_testcase;
	for (int i = 0; i < num_testcase; i++) {
		cin >> board_size;
		memset(capacity, 0 ,sizeof(capacity));
		
		for (int j = 0; j < board_size; j++) {
			string line;
			cin >> line;
			for (int k = 0; k < board_size; k++	){
				if (line[k] == '.') {
					chess_board[j][k] = 1;
				}
				else{
					chess_board[j][k] = 0;
				}
			}
		}
		make_graph();
		// for (int y = 0; y < board_size; y++) {
		// 	for (int x = 0; x < board_size; x++) {
		// 		cout << biparty[y][x][0] << "," << biparty[y][x][1] << "    ";
		// 	}
		// 	cout << endl;
		// }
		
		// for (int y = 0; y < 7; y++) {
		// 	for (int x = 0; x < 7; x++) {
		// 		cout << capacity[y][x] << " ";
		// 	}
		// 	cout << endl;
		// }
		cout << FordFulkerson(0, 1) << endl;
		
	}
	
	
    return 0;
}

