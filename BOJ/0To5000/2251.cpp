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
#include <map>


using namespace std;

int capacity[3];
bool water_on_AB[201][201];

void FillWaterAB() {
	queue<pair<int, int> > waters;
	waters.push(make_pair(0, 0));
	while (!waters.empty()) {
		int water_A = waters.front().first;
		int water_B = waters.front().second;
		int water_C = capacity[2] - water_A - water_B;
		waters.pop();
		if (water_on_AB[water_A][water_B] == 0) {
			water_on_AB[water_A][water_B] = 1;
			if (water_A > 0) {
				if (capacity[1] - water_B > 0) { // when possible to move water from A to B 
					waters.push(make_pair(max(0, water_A - (capacity[1] - water_B)), min(water_B + water_A, capacity[1])));
				} 
				if (capacity[2] - water_C > 0) { // when possible to move water from A to C
					waters.push(make_pair(max(0, water_A - (capacity[2] - water_C)), water_B));
				}
			} 
			if (water_B > 0) {
				if (capacity[0] - water_A > 0) { //when possible to move water from B to A
					waters.push(make_pair(min(water_B + water_A, capacity[0]), max(0, water_B - (capacity[0] - water_A))));
				}
				if (capacity[2] - water_C > 0) {// move from b to c
					waters.push(make_pair(water_A, max(0, water_B - (capacity[2] - water_C))));
				}
			}
			if (water_C > 0) {
				if (capacity[0] - water_A > 0) { //move from c to a
					waters.push(make_pair(min(capacity[0], water_A + water_C), water_B));
				}
				if (capacity[1] - water_B > 0) { // move from c to b
					waters.push(make_pair(water_A, min(capacity[1], water_B + water_C)));
				}
			}
		}
	}
}
void Solve() {
	map<int, int> water_on_C;
	vector<int> possible_keys;
	for (int i = 0; i <= capacity[0]; i++) {
		for (int j = 0; j <= capacity[1]; j++) {
			if (water_on_AB[i][j] == 1) {
				//cout << i << " " << j << " " << capacity[2] - i - j << "\n";
				water_on_C[capacity[2] - j] = 1;
			}
		}
	}
	for(map<int,int>::iterator it = water_on_C.begin(); it != water_on_C.end(); ++it) {
  		possible_keys.push_back(it->first);
	}
	sort(possible_keys.begin(), possible_keys.end());
	for (int i = 0; i < possible_keys.size(); i++) {
		cout << possible_keys[i] << " ";
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
	
	int A, B, C;
	
	while (cin >> A >> B >> C) {
		capacity[0] = A;
		capacity[1] = B;
		capacity[2] = C;
		FillWaterAB();
		Solve();
	}
    

    return 0;
}

