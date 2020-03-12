#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

const int MAX_V = 100;
const double INF = 1e300;
int num_vertex, num_cables, x, y;


vector<pair<double, int> > graph[MAX_V]; //adjacent list expression for the given graph, weight and vertex number 

double prim(vector<pair<double, int> >& selected) {
	selected.clear();
	
	vector<bool>added(num_vertex, false); // saves vertex in the minimum spanning tree
	vector<double> min_weight(num_vertex, INF); //saves minimum weight adjacent to the MST,
	vector<int> parent(num_vertex, -1); //save its parent 
	
	double ret = 0.0;
	
	min_weight[0] = 0.0;
	parent[0] = 0;
	
	for (int iter = 0; iter < num_vertex; iter++) {
		int current_min_vertex = -1;
		for (int i = 0; i < min_weight.size(); i++) { // find vertex adjacent to the tree with smallest weight 
			if (!added[i] && (current_min_vertex == -1 || min_weight[current_min_vertex] > min_weight[i])){
				current_min_vertex = i;
			}
		}
	
		if (parent[current_min_vertex] != current_min_vertex) {
			selected.push_back(make_pair(parent[current_min_vertex], current_min_vertex));
		}
	
		added[current_min_vertex] = true;
		ret += min_weight[current_min_vertex];

		for (int i = 0; i < graph[current_min_vertex].size(); i++) {
			double weight = graph[current_min_vertex][i].first;
			int index_vertex = graph[current_min_vertex][i].second;
			min_weight[index_vertex] = min(weight, min_weight[index_vertex] );
			parent[index_vertex] = current_min_vertex;
		}
	}
	
	
	return ret;
}

double distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y2 - y1, 2));
}




int main()
{
	
	std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	cout.precision(11);
    cout << fixed;
	
	int num_testcase;
	int connected1, connected2;
	
	cin >> num_testcase;
	for (int i = 0; i < num_testcase; i++) {
		vector<pair < double, int> > selected(0);
		vector<pair < pair<int, int>, int> > coordinate(0); // x,y coordinate and vertex number
		vector<int> coordinate_x(0);
		vector<int> coordinate_y(0);
		
		for (int l = 0; l < MAX_V; l++) {
			graph[l] = vector<pair <double, int> >(0);
		}
		
		cin >> num_vertex;
		cin >> num_cables;
		
		for (int j = 0; j < num_vertex; j++) { // save coordinate 
			cin >> x;
			coordinate_x.push_back(x);
		
		}
		
		for (int j = 0; j < num_vertex; j++) {
			cin >> y;
			coordinate_y.push_back(y);
			coordinate.push_back(make_pair(make_pair(coordinate_x[j], coordinate_y[j]), j));
		}
		
		for (int j = 0; j < coordinate.size(); j++) {
			for (int l = j + 1; l < coordinate.size(); l++) {
				int first_vertex = coordinate[j].second;
				int first_vertex_x = coordinate[j].first.first;	
				int first_vertex_y = coordinate[j].first.second;
				
				int second_vertex = coordinate[l].second;
				int second_vertex_x = coordinate[l].first.first;
				int second_vertex_y = coordinate[l].first.second;
				
				graph[first_vertex].push_back(make_pair(distance(first_vertex_x, first_vertex_y, second_vertex_x, second_vertex_y), second_vertex));
				graph[second_vertex].push_back(make_pair(distance(first_vertex_x, first_vertex_y, second_vertex_x, second_vertex_y), first_vertex));
				
			}
		}
		
		for (int k = 0; k < num_cables; k++) {
			cin >> connected1;
			cin >> connected2;
			graph[connected1].push_back(make_pair(0.0, connected2));
			graph[connected2].push_back(make_pair(0.0, connected1));
			
			
		}
		
		// for (int y = 0; y < num_vertex; y++) {
		// 	for (int  x = 0; x < num_vertex; x++) {
		// 		cout << graph[y][x].first << " ";
		// 	}
		// 	cout << endl;
		// }
		//cout << num_vertex << endl;
		cout << prim(selected) << endl;
		
	}
	
    

    return 0;
}