#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> pii;

int num_planet;
vector<pii> graph[100000];
int coordinate[100000][3];
bool visited[100000];


struct Planet {
	int x;
	int y;
	int z;
	int index;
	Planet(int X, int Y, int Z, int INDEX) {
		x = X;
		y = Y;
		z = Z;
		index = INDEX;
	}
};


int Prim() {
	int min_cost = 0;
	int begin_point = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	
	// for (int i = 0; i < graph[begin_point].size(); i++) {
	// 	pq.push(graph[begin_point][i]);
	// }
	pq.push({0, begin_point});
	while (!pq.empty()) {
		int here = pq.top().second;
		int here_cost = pq.top().first;
		
		pq.pop();
		if (visited[here]) {
			continue;
		}
		min_cost += here_cost;
		// cout << here << " ";
		visited[here] = true;
		for (int i = 0 ; i < graph[here].size(); i++) {
			int there = graph[here][i].second;
			int there_cost = graph[here][i].first;
			
			pq.push({there_cost, there});
		}
	}
	return min_cost;
	
}

bool CompX(Planet &p1, const Planet &p2){
    return p1.x < p2.x;
}

bool CompY(Planet &p1, const Planet &p2){
    return p1.y < p2.y;
}

bool CompZ(Planet &p1, const Planet &p2){
    return p1.z < p2.z;
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	while (cin >> num_planet) {
		int x, y, z;
		vector<Planet> planets;
		for (int i = 0; i < num_planet; i++) {
			cin >> x >> y >> z;
			Planet new_planet(x, y, z, i);
			planets.push_back(new_planet);
		}
		sort(planets.begin(), planets.end(), CompX);
		for (int i = 0; i < planets.size() - 1; i++) {
			int from = planets[i].index;
			int to = planets[i + 1].index;
			int dist_x = abs(planets[i].x - planets[i + 1].x);
			int dist_y = abs(planets[i].y - planets[i + 1].y);
			int dist_z = abs(planets[i].z - planets[i + 1].z);
			int dist = min(dist_x, min(dist_z, dist_y));
			graph[from].push_back({dist, to});
			graph[to].push_back({dist, from});
		}
		
		sort(planets.begin(), planets.end(), CompY);
		for (int i = 0; i < planets.size() - 1; i++) {
			int from = planets[i].index;
			int to = planets[i + 1].index;
			int dist_x = abs(planets[i].x - planets[i + 1].x);
			int dist_y = abs(planets[i].y - planets[i + 1].y);
			int dist_z = abs(planets[i].z - planets[i + 1].z);
			int dist = min(dist_x, min(dist_z, dist_y));
			graph[from].push_back({dist, to});
			graph[to].push_back({dist, from});
		}
		
		sort(planets.begin(), planets.end(), CompZ);
		for (int i = 0; i < planets.size() - 1; i++) {
			int from = planets[i].index;
			int to = planets[i + 1].index;
			int dist_x = abs(planets[i].x - planets[i + 1].x);
			int dist_y = abs(planets[i].y - planets[i + 1].y);
			int dist_z = abs(planets[i].z - planets[i + 1].z);
			int dist = min(dist_x, min(dist_z, dist_y));
			graph[from].push_back({dist, to});
			graph[to].push_back({dist, from});
		}
		cout << Prim() << "\n";
		
	}
    

    return 0;
}

