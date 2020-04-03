#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>



using namespace std;

int n;
vector<int> moves;
void Hanoi(int from, int to, int disks) {
	if (disks == 1) {
		moves.push_back(from);
		moves.push_back(to);
	}
	else{
		int left_one = 6 - from - to;
		Hanoi(from, left_one, disks - 1);
		moves.push_back(from);
		moves.push_back(to);
		Hanoi(left_one, to, disks - 1);
	}
}
int main()
{
	// std::ios_base::sync_with_stdio(false); 
	// std::cin.tie(NULL); 
	// std::cout.tie(NULL);
	while (cin >> n) {
		moves.clear();
		Hanoi(1, 3, n);
		int seperation_two = 0;
		cout << moves.size() / 2 << "\n";
		for (int i = 0; i < moves.size(); i++) {
			cout << moves[i] << " ";
			seperation_two++;
			if (seperation_two == 2) {
				cout << "\n";
				seperation_two = 0;
			}
		}
	} 
	
    

    return 0;
}

