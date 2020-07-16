#include <bits/stdc++.h>
//#include <iostream>
//#include <queue>
//#include <vector>
using namespace std;

const int MAX = 32001;
vector<int> graph[MAX];
int num_pointed[MAX];
int num_problems, num_information;


void PrintBestOrder() {
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 0; i < num_problems; i++) {
		if (num_pointed[i] == 0) {
			pq.push(i);
		}
	}
	while (!pq.empty()) {
		int here = pq.top();
		cout << here + 1 << " ";
		pq.pop();
		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i];
			num_pointed[there] = num_pointed[there] - 1;
			if (num_pointed[there] == 0) {
				pq.push(there);
			}
		}
	}
	
}

int main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	cin >> num_problems >> num_information;
	for (int i = 0; i < num_information; i++) {
		int first, second;
		cin >> first >> second;
		first = first - 1;
		second = second - 1;
		graph[first].push_back(second);
		num_pointed[second]++;
	}
	PrintBestOrder();
	
	
	
	return 0;
}



