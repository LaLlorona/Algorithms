#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>


using namespace std;

int num_testcase;
const int INF = 987654321;

bool is_prime[10001];
bool visited[10001];
int distance_from[10001];
vector<int> primes;
vector<int> graph[10001];

void Eratosthenes() {
	memset(is_prime, 1, sizeof(is_prime));
	is_prime[0] = false;
	is_prime[1] = false;
	int square = (int)sqrt(10000);
	for (int i = 2; i <= square; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= 10000; j += i) {
				is_prime[j] = false;
			}
		}
	}
	for (int i = 1000; i <= 10000; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
		}
	}
}
bool PossibleToConnect(int from, int to) {
	bool reachable = false;
	int digit_thousand, digit_hundred, digit_ten, digit_one;
	int temp = from;
	digit_one = temp % 10;
	temp /= 10;
	digit_ten = temp % 10;
	temp /= 10;
	digit_hundred = temp % 10;
	temp /= 10;
	digit_thousand = temp;
	for (int i = - digit_one; i <= 9 - digit_one; i++) {
		if (from + i == to) {
			reachable = true;
		}
	}
	
	for (int i = - digit_ten; i <= 9 - digit_ten; i++) {
		if (from + i * 10 == to) {
			reachable = true;
		}
	}
	
	for (int i = - digit_hundred; i <= 9 - digit_hundred; i++) {
		if (from + i * 100 == to) {
			reachable = true;
		}
	}
	
	for (int i = - digit_thousand + 1; i <= 9 - digit_thousand; i++) {
		if (from + i * 1000 == to) {
			reachable = true;
		}
	}
	return reachable;
}

void FillGraph() {
	
	for (int i = 0; i < primes.size(); i++) {
		for (int j = 0; j < primes.size(); j++) {
			if (PossibleToConnect(primes[i], primes[j])) {
				//cout << primes[i] << " " << primes[j] << "\n";
				graph[primes[i]].push_back(primes[j]);
			}
		}
	}
}

void BFS(int start) {
	queue<int> BFS_queue;
	BFS_queue.push(start);
	visited[start] = true;
	distance_from[start] = 0;
	while (!BFS_queue.empty()) {
		int here = BFS_queue.front();
		BFS_queue.pop();
		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i];
			if (!visited[there]) {
				BFS_queue.push(there);
				visited[there] = true;
				distance_from[there] = min(distance_from[there], distance_from[here] + 1);
			}
		}
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
	
	Eratosthenes();
	FillGraph();
	int a, b;
	
	while (cin >> num_testcase) {
		for (int i = 0; i < num_testcase; i++) {
			memset(visited, 0 ,sizeof(visited));
			for (int i = 0; i < 10001; i++) {
				distance_from[i] = INF;
			}

			cin >> a >> b;
			BFS(a);
			cout << distance_from[b] << "\n";
		}
		
		
		
	
	}
    

    return 0;
}

