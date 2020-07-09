#include <bits/stdc++.h>


using namespace std;
typedef pair<double, int> pdi; 
int num_stars, num_dist;
vector<pdi> graph[10001];
bool visited[10001];
double coordinate[100][2];

double Prim() {
	double min_cost = 0;
	int begin_point = 0;
	priority_queue<pdi, vector<pdi>, greater<pdi> > pq;
	
	// for (int i = 0; i < graph[begin_point].size(); i++) {
	// 	pq.push(graph[begin_point][i]);
	// }
	pq.push({0, begin_point});
	while (!pq.empty()) {
		int here = pq.top().second;
		double here_cost = pq.top().first;
		
		pq.pop();
		if (visited[here]) {
			continue;
		}
		min_cost += here_cost;
		// cout << here << " ";
		visited[here] = true;
		for (int i = 0 ; i < graph[here].size(); i++) {
			int there = graph[here][i].second;
			double there_cost = graph[here][i].first;
			
			pq.push({there_cost, there});
		}
	}
	return min_cost;
	
}




int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_stars) {
		memset(visited, 0, sizeof(visited));
		num_dist = num_stars * num_stars;
		for (int i = 0; i < 10001; i++) {
			graph[i].clear();
		}
		for (int i = 0; i < num_stars; i++) {
			cin >> coordinate[i][0] >> coordinate[i][1];
		}
		for (int i = 0; i < num_stars; i++) {
			for (int j = 0; j < num_stars; j++) {
				if (i != j) {
					double dist = sqrt(pow(coordinate[i][0] - coordinate[j][0], 2.0) + pow(coordinate[i][1] - coordinate[j][1], 2.0));
					graph[i].push_back({dist, j});
					graph[j].push_back({dist, i});
				}
			}
		}
		cout << Prim() << "\n";
		
	}
    

    return 0;
}

