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

int width;
int height;
int cost[1002][1002];
string result = "";

pair<int, int> FindMinCostPair() {
	int min_x = 0;
	int min_y = 0;
	int minimum_value = cost[min_y][min_x];
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if ((y + x) % 2 == 1 && cost[y][x] < minimum_value) {
				minimum_value = cost[y][x];
				min_y = y;
				min_x = x;
			}
		}
	}
	return make_pair(min_y, min_x);
}

string FindMaximumCost() {
	result = "";
	if (width % 2 == 1) {
		for (int i = 0; i < width / 2; i++) {
			for (int j = 0; j < height - 1; j++) {
				result += "D";
			}
			result += "R";
			for (int j = 0; j < height - 1; j++) {
				result += "U";
			}
			result +="R";
		}
		for (int j = 0; j < height - 1; j++) {
			result += "D";
		}
	}
	else if (height % 2 == 1) {
		for (int i = 0; i < height / 2; i++) {
			for (int j = 0; j < width - 1; j++) {
				result += "R";
			}
			result += "D";
			for (int j = 0; j < width - 1; j++) {
				result += "L";
			}
			result +="D";
		}
		for (int j = 0; j < width - 1; j++) {
			result += "R";
		}
		
	}
	else {
		pair<int, int> min_yx = FindMinCostPair();
		int current_x = 0;
		int current_y = 0;
		int min_y = min_yx.first;
		int min_x = min_yx.second; 
		int change_path_y = (min_y % 2 == 0) ? min_y : min_y - 1;
		int change_path_x = (min_x % 2 == 0) ? min_x : min_x - 1;
		//cout << min_y << " " << min_x << " " << change_path_y << " " << change_path_x;
		//result += "part 1 \n";
		//cout << min_y << " " << min_x << "\n";
		for (int y = 0; y < change_path_y / 2; y++) { // part 1
			
			for (int x = 0; x < width - 1; x++) {
				result += "R";
				current_x++;
			} 
			result += "D";
			current_y++;
			for (int x = 0; x < width - 1; x++) {
				result += "L";
				current_x--;
			} 
			result += "D";
			current_y++;
		}
		
		//result += "part 2 \n";
		for (int x = 0; x < change_path_x; x += 2) { // part2
			result += "DRUR";
			current_x += 2;
		}
		
		//result += "part 3 \n";
		
		if (min_x % 2 == 0) { // part 3
			result += "RD";
			current_x++;
			current_y++;
		}
		else {
			result += "DR";
			current_x++;
			current_y++;
		}
		
		//result += "part 4 \n";
		//connection between part 3 and 4
		if (current_x == width - 1 && current_y == height - 1) { // if traversal is finished
		}
		else if (current_x == width - 1 && current_y != height - 1) { // traversal is not finished but skip part 4 and  part 5 should begin
			result += "D";
			current_y++;
		}
		else { // connection between part 3 and part 4
			result += "R";
			current_x++;
			for (int x = change_path_x + 2; x < width; x += 2) {// part 4
				result += "URD";
				current_x++;
				if (current_x == width - 1 && current_y == height - 1) { // if traversal is finished
				}
				else if (current_x == width - 1 && current_y != height - 1) {
					result += "D";
					current_y++;
				}
				else{
					result += "R";
					current_x++;
				}
			}
		}
		
		//result += "part 5 \n";
		
		for (int y = 0; y < (height - change_path_y - 2) / 2; y++) {
			for (int x = 0; x < width - 1; x++) {
				result += "L";
				current_x--;
			}
			result += "D";
			current_y++;
			for (int x = 0; x < width - 1; x++) {
				result += "R";
				current_x++;
			}
			//cout << current_y << " " << current_x << "\n";
			if (current_y != height - 1) {
				//cout << current_x << " " << current_y << "\n";
				result +="D";
				current_y++;
			}
			
		}
		
		
		
	}
	return result;
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> height >> width) {
		memset(cost, 0, sizeof(cost));
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				cin >> cost[y][x];
			}
		}
		cout << FindMaximumCost() << "\n";
		//cout << FindMinCostPair().first << " " << FindMinCostPair().second;
		
	}
    

    return 0;
}

]