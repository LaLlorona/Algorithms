#include <bits/stdc++.h>
//#include <iostream>

using namespace std;
const int MAX = 101;
bool connected[MAX][MAX];
int num_people, num_relation;

void FloydWalshall() {
	for (int k = 1; k <= num_people; k++) {
		for (int i = 1; i <= num_people; i++) {
			for (int j = 1; j <= num_people; j++) {
				connected[i][j] = connected[i][j] | (connected[i][k] & connected[k][j]);
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	while (cin >> num_people >> num_relation) {
		for (int i = 0; i < num_relation; i++) {
			int from, to;
			cin >> from >> to;
			connected[from][to] = true;
		}
		FloydWalshall();
		
		for (int i = 1; i <= num_people; i++) {
			int clear_relation = 0;
			for (int j = 1; j <= num_people; j++) {
				if (i != j) {
					if (connected[i][j] || connected[j][i]) {
						clear_relation++;
					}
				}
			}
			cout << num_people - clear_relation - 1 << "\n";
		}
	}
	
	
	
	return 0;
}


