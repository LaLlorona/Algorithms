#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii; //cost, vertex number

const int INF = 987654321;

int numVertice;
int numEdge;
int beginVertex;
const int MAX = 20001;

vector<pii> graph[MAX];
int distanceFrom[MAX];

void Dijkstra(int beginVertex) {
	priority_queue<pii, vector<pii>, greater<pii>> dijkstraQueue;
	distanceFrom[beginVertex] = 0;
	dijkstraQueue.push(pii(0, beginVertex)); //cost, vertex

	while (!dijkstraQueue.empty()) {
		pii here = dijkstraQueue.top();
		int hereVertex = here.second;
		int hereCost = here.first;

		dijkstraQueue.pop();
		// cout << "here: " << hereVertex << " cost: " << hereCost << "\n"; 
		if (distanceFrom[hereVertex] < hereCost) {
			continue;
		}

		
		
		for (int i = 0; i < graph[hereVertex].size(); i++) {
			pii next = graph[hereVertex][i];
			int nextVertex = next.second;
			int costBetween = next.first;
			if (distanceFrom[nextVertex] > distanceFrom[hereVertex] + costBetween) {
				distanceFrom[nextVertex] = distanceFrom[hereVertex] + costBetween;
				dijkstraQueue.push(pii(distanceFrom[nextVertex], nextVertex));
			}
		}
	}
	for (int i = 0; i < numVertice; i++) {
		if (distanceFrom[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << distanceFrom[i] << "\n";
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

	while (cin >> numVertice >> numEdge) {
		for (int i = 0 ; i < numVertice; i++) {
			graph[i].clear();
			distanceFrom[i] = INF;
		}
		cin >> beginVertex;
		beginVertex--;
		for (int i = 0 ; i < numEdge; i++) {
			int from, to, cost;
			cin >> from >> to >> cost;
			from--;
			to--;
			
			graph[from].push_back(pii(cost, to));
		}

		Dijkstra(beginVertex);
	}

}


  