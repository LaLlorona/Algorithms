#include <bits/stdc++.h>


using namespace std;

int n;
int lab_initial[51][51];
int lab_after_spreading[51][51];
int time_to_spread[51][51];
const int INF = 987654321;

int num_total_active_virus;
vector<pair<int, int> >possible_virus_position, temp;
vector<vector<pair<int, int> > > combinations;
int direction_y[4] = {-1, 0, 0, 1};
int direction_x[4] = {0, -1, 1, 0};

void FillCombinations(int current_index, int num_choose) {
	if (num_choose == num_total_active_virus) {
		combinations.push_back(temp);
	}
	else if (current_index < possible_virus_position.size()) {
		temp.push_back(possible_virus_position[current_index]);
		FillCombinations(current_index + 1, num_choose + 1);
		temp.pop_back();
		
		FillCombinations(current_index + 1, num_choose);
	}
}

bool IsInBound(int y, int x) {
	return (y >= 0 && y < n && x >= 0 && x < n);
}

void PreProcess() {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> lab_initial[y][x];
			lab_after_spreading[y][x] = lab_initial[y][x];
			if (lab_initial[y][x] == 2){
				possible_virus_position.push_back(make_pair(y, x));
			}
			time_to_spread[y][x] = INF;
		}
	}
	
}
void BFS(int try_index) {
	queue<pair<int, int> > BFS_queue;

	for (int i = 0; i < combinations[try_index].size(); i++) {
		int activated_y = combinations[try_index][i].first;
		int activated_x = combinations[try_index][i].second;
		lab_after_spreading[activated_y][activated_x] = 3;
		time_to_spread[activated_y][activated_x] = 0;
		BFS_queue.push(make_pair(activated_y, activated_x));
	}
	while (!BFS_queue.empty()) {
		int current_y = BFS_queue.front().first;
		int current_x = BFS_queue.front().second;
		BFS_queue.pop();
		for (int i = 0 ; i < 4; i++) {
			int next_y = current_y + direction_y[i];
			int next_x = current_x + direction_x[i];
			if (IsInBound(next_y, next_x) && lab_after_spreading[next_y][next_x] != 1 && time_to_spread[next_y][next_x] > time_to_spread[current_y][current_x] + 1) {
				
				lab_after_spreading[next_y][next_x] = 3;
				time_to_spread[next_y][next_x] = time_to_spread[current_y][current_x] + 1;
				BFS_queue.push(make_pair(next_y, next_x));
			}
		}
	}
	
	
}
int Solve() {
	int min_time_spread = INF;
	for (int i = 0; i < combinations.size(); i++) {
		int max_time_spread_this_case = 0;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				lab_after_spreading[y][x] = lab_initial[y][x];
				time_to_spread[y][x] = INF;
			}
		}
		BFS(i);
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (lab_after_spreading[y][x] != 1 && lab_initial[y][x] != 2){
					max_time_spread_this_case = max(max_time_spread_this_case, time_to_spread[y][x]);
				}
			}
		}
		// if (min_time_spread > max_time_spread_this_case) {
		// 	for (int k = 0; k < combinations[i].size(); k++) {
		// 		cout << combinations[i][k].first << "," << combinations[i][k].second << " ";
		// 	}
		// 	cout << "\n";
		// 	for (int y = 0; y < n; y++) {
		// 		for (int x = 0; x < n; x++) {
		// 			cout << time_to_spread[y][x] << " ";
		// 		}
		// 		cout << "\n";
		// 	}
		// 	for (int y = 0; y < n; y++) {
		// 		for (int x = 0; x < n; x++) {
		// 			cout << lab_after_spreading[y][x] << " ";
		// 		}
		// 		cout << "\n";
		// 	}
		// }
		min_time_spread = min(min_time_spread, max_time_spread_this_case);
		
	}
	if (min_time_spread == INF) {
		return -1;
	}
	else{
		return min_time_spread;
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

	while (cin >> n >> num_total_active_virus) {
		combinations.clear();
		possible_virus_position.clear();
		temp.clear();
		
		PreProcess();
		FillCombinations(0, 0);
		// for (int i = 0 ;i < combinations.size(); i++) {
		// 	for (int j = 0; j < combinations[i].size(); j++) {
		// 		cout << combinations[i][j].first << "," << combinations[i][j].second << " ";
		// 	}
		// 	cout << "\n";
		// }
		cout << Solve() << "\n";
	
	}
    

    return 0;
}

