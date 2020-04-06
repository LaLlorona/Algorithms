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

int weights[11][11]; // saves weight from, to
bool visited[11];
vector<int> path;
const int INF = 987654321;
int num_city;

int TSP(vector<int>& current_path, int current_length) {
	int minimum_weight = INF;
	if (current_path.size() == num_city) { // when complete traversal
		return current_length + weights[current_path.back()][current_path[0]];
	}
	else {
		int from = current_path.back();
		for (int to = 0; to < num_city; to++) {
			if (!visited[to] && weights[from][to] != INF) {
				current_path.push_back(to);
				visited[to] = true;
				minimum_weight = min(minimum_weight, TSP(current_path, current_length + weights[from][to])); 
				current_path.pop_back();
				visited[to] = false;
				
			}
		}
	}
	return minimum_weight;
}


int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	int weight;
	
	while (cin >> num_city) {
		for (int y = 0; y < num_city; y++) {
			for (int x = 0; x < num_city; x++) {
				cin >> weight;
				if (weight == 0) {
					weights[y][x] = INF;
				}
				else{
					weights[y][x] = weight;
				}
			}
		}
		path.push_back(0);
		visited[0] = true;
		cout << TSP(path, 0);
	}
    

    return 0;
}

