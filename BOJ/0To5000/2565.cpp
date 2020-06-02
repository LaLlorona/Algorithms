#include <bits/stdc++.h>
//#include <iostream>

using namespace std;

const int MAX = 501;
int max_cand;
int cache[MAX];
int num_lines;
int from_to[MAX];
int to_from[MAX];

int ChooseFrom(int from) {
	if (from_to[from] == -1) {
		return -1;
	}
	int& ret = cache[from];
	if (ret !=-1) {
		return ret;
	}
	ret = 1;
	for (int i = from_to[from]; i < MAX; i++) {
		if (to_from[i] > from) {
			ret = max(ret, ChooseFrom(to_from[i]) + 1);
		}
	}
	return ret;
}

int main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	while (cin >> num_lines) {
		max_cand = 0;
		for (int i = 0; i < MAX; i++) {
			cache[i] = -1;
			from_to[i] = -1;
			to_from[i] = -1;
		}
		for (int i = 0; i < num_lines; i++) {
			int a, b;
			cin >> a >> b;
			from_to[a] = b;
			to_from[b] = a;
		}
		for (int i = 1; i < MAX; i++) {
			ChooseFrom(i);
		}
		
		for (int i = 1; i < MAX; i++) {
			max_cand = max(max_cand, cache[i]);
			//cout << max_cand << " ";
		}
		cout << num_lines -  max_cand;
		
		
	}
	
	
	
	return 0;
}



