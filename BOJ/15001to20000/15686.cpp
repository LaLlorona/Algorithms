#include <bits/stdc++.h>


using namespace std;

vector<pair<int, int> > chickens;
vector<pair<int, int> > houses;
vector<pair<int, int> > temp;

vector<vector<pair<int, int> > > combinations;


int map_size;
int num_chickens;
int city[51][51];
const int INF = 987654321;

void FillCombinations(int current_index, int num_choose) {
	if (num_choose == num_chickens) {
		combinations.push_back(temp);
	}
	else if (current_index < chickens.size()) {
		
		temp.push_back(chickens[current_index]);
		FillCombinations(current_index + 1, num_choose + 1);
		temp.pop_back();
		
		FillCombinations(current_index + 1, num_choose);
	}
}

int Solve() {
	int min_cand = INF;
	for (int i = 0; i < combinations.size(); i++) {
		int sum_distance = 0;
		for (int house = 0; house < houses.size(); house++) {
			
			int distance_between = INF;
			for (int chicken = 0; chicken < combinations[i].size(); chicken++) {
				distance_between = min(distance_between, abs(houses[house].first - combinations[i][chicken].first) + abs(houses[house].second - combinations[i][chicken].second));
			}
			sum_distance += distance_between;
		}
		min_cand = min(min_cand, sum_distance);
		
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
	while (cin >> map_size >> num_chickens) {
		chickens.clear();
		temp.clear();
		houses.clear();
		combinations.clear();
		for (int y = 0; y < map_size; y++) {
			for (int x = 0; x < map_size; x++) {
				cin >> city[y][x];
				if (city[y][x] == 1) {
					houses.push_back(make_pair(y, x));
				}
				else if (city[y][x] == 2) {
					chickens.push_back(make_pair(y, x));
				}
			}
		}
		FillCombinations(0, 0);
		// for (int i = 0; i < chickens.size(); i++) {
		// 	cout << chickens[i].first << "," << chickens[i].second << " ";
		// }
		// cout << "\n";
		// for (int i = 0; i < combinations.size(); i++) {
		// 	for (int j = 0; j < combinations[i].size(); j++) {
		// 		cout << combinations[i][j].first << "," << combinations[i][j].second <<" ";
		// 	}
		// 	cout << "\n";
		// }
		
		cout << Solve() << "\n";
		
		
	}
    

    return 0;
}

