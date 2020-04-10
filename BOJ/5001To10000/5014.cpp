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

int target_floor;
int initial_floor;
int max_floor;
int updown[2];
int up, down;
int num_press_to_reach_floor[1000001];
const int INF = 987654321;

bool IsInBound(int x) {
	return (x >= 1 && x <= max_floor);
}

void FillPress() {
	queue<int> reachable;
	reachable.push(initial_floor);
	num_press_to_reach_floor[initial_floor] = 0;
	while (!reachable.empty()) {
		int here = reachable.front();
		reachable.pop();
		for (int i = 0; i < 2; i++) {
			int there = here + updown[i];
			if (IsInBound(there) && num_press_to_reach_floor[there] == INF) {
				reachable.push(there);
				num_press_to_reach_floor[there] = num_press_to_reach_floor[here] + 1;
			}
		}
	}
}

string Solve() {
	if (num_press_to_reach_floor[target_floor] == INF) {
		return "use the stairs";
	}
	return to_string(num_press_to_reach_floor[target_floor]);
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> max_floor >> initial_floor >> target_floor >> up >> down) {
		updown[0] = up;
		updown[1] = -down;
		for (int i = 0; i < 1000001; i++) {
			num_press_to_reach_floor[i] = INF;
		}
		FillPress();
		cout << Solve() << "\n";
	}
    

    return 0;
}

