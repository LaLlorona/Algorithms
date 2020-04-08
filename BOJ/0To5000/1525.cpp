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
#include <string>
#include <map>

using namespace std;
string target = "123456789";
int direct_x[4] = {0, -1, 1, 0};
int direct_y[4] = {-1, 0, 0, 1};

int FindNine(string input) {
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '9') {
			return i;
		}
	}
	return -1;
}

bool IsInBound(int y, int x) {
	return (y >= 0 && y < 3 && x >= 0 && x < 3);
}


int BFS(string start) {
	
	map<string, int> distance_from; // saves distance_from for each state. 
	queue<string> BFS_queue;
	
	BFS_queue.push(start);
	distance_from[start] = 0;
	bool found = false;
	
	while (!BFS_queue.empty() && !found) {
		string here = BFS_queue.front();
		string temp = here;
		BFS_queue.pop();
		if (here == target) {
			found = true;
		}
		int nine_position = FindNine(temp);
		int nine_y = nine_position / 3;
		int nine_x = nine_position % 3;
		for (int i = 0; i < 4; i++) {
			if (IsInBound(nine_y + direct_y[i], nine_x + direct_x[i])) { // possible to reach
				swap(temp[nine_position], temp[(nine_y + direct_y[i]) * 3 + nine_x + direct_x[i]]); 
				if (distance_from.count(temp) == 0) {
					distance_from[temp] = distance_from[here] + 1;
					BFS_queue.push(temp);
				}
				swap(temp[nine_position], temp[(nine_y + direct_y[i]) * 3 + nine_x + direct_x[i]]); 
				
			}
		}
	}
	if (distance_from.count(target) == 0) {
		return -1;
	}
	else{
		return distance_from[target];
	}
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	string input;
	while (cin >> input) {
		if (input == "0") {
			input = "9";
		}
		string initial = "";
		initial += input;
		for (int i = 0; i < 8; i++) {
			cin >> input;
			if (input == "0") {
			input = "9";
			}
			initial += input;
		}
		cout << BFS(initial) << "\n";
	
	}
    

    return 0;
}

