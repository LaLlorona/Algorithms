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

int num_people;
int stats[21][21];
const int INF = 987654321;




vector<vector<int> > combinations;
vector<int> temp;

void FillComb(int current_index, int left_num) {
	
	if (left_num == 0) {
		combinations.push_back(temp);
	}
	else if (current_index >= num_people){
		
	}
	else{
		
		
		temp.push_back(current_index);
		FillComb(current_index + 1, left_num - 1);
		temp.pop_back();
		
		FillComb(current_index + 1, left_num);
	}
}
int CalculateDiffTeamStats() {
	combinations.clear();
	temp.clear();
	FillComb(0, num_people / 2);
	int min_cand = INF;
	for (int i = 0; i < combinations.size(); i++) {
		
		vector<int> team_one;
		vector<int> team_two;
		vector<int>::iterator iter;
		for (int j = 0 ; j < num_people; j++) {
			iter = find(combinations[i].begin(), combinations[i].end(), j);
			if (iter == combinations[i].end()) {
				team_one.push_back(j);
			}
			else{
				team_two.push_back(j);
			}
		}
		// for (int i = 0; i < team_two.size(); i++) {
		// 	cout << team_two[i] << " ";
		// }
		
		int total_stats_team1 = 0;
		int total_stats_team2 = 0;
		for (int i = 0; i < team_one.size(); i++) {
			for (int j = i + 1; j < team_one.size(); j++) {
				total_stats_team1 += stats[team_one[i]][team_one[j]];
				total_stats_team1 += stats[team_one[j]][team_one[i]];
			}
		}
		for (int i = 0; i < team_two.size(); i++) {
			for (int j = i + 1; j < team_two.size(); j++) {
				total_stats_team2 += stats[team_two[i]][team_two[j]];
				total_stats_team2 += stats[team_two[j]][team_two[i]];
			}
		}
		min_cand = min(min_cand, abs(total_stats_team2 - total_stats_team1));
		
	
		
		
		
	}
	return min_cand;
	
	
}
int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	while (cin >> num_people) {
		
	
		for (int y = 0; y < num_people; y++) {
			for (int x = 0; x < num_people; x++) {
				cin >> stats[y][x];
			}
		}
		cout << CalculateDiffTeamStats() << "\n";
	}
    

    return 0;
}

