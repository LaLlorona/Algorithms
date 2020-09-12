#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> pii;


const int INF = 1987654321;

int min_dist[1001][1001];

pii before[1001][1001]; // save before state 
int chosen[1001][1001];

pii incident[1001];

int city_size, num_incidents;

int Distance(pii a, pii b) {
	return (abs(a.first - b.first) + abs(a.second - b.second));
}

int CalcMinDist(int last_move_first, int last_move_second) {
	if (last_move_first == 0 && last_move_second == 0) {
		return 0;
	}
	else if (last_move_first == 0 && last_move_second == 1) {
		before[0][1] = {0, 0};
		chosen[0][1] = 2;
		return Distance(incident[1], {city_size, city_size});
	}
	else if (last_move_first == 1 && last_move_second == 0) {
		before[1][0] = {0, 0};
		chosen[1][0] = 1;
		return Distance(incident[1], {1, 1});
	}
	int& ret = min_dist[last_move_first][last_move_second];
	
	if (ret != -1) {
		return ret;
	}
	
	if (last_move_first > last_move_second) {// first car move
		chosen[last_move_first][last_move_second] = 1;
		if (last_move_first > last_move_second + 1) { // the only case is first car come from last_move_first - 1
			ret = CalcMinDist(last_move_first - 1, last_move_second) + Distance(incident[last_move_first], incident[last_move_first - 1]);
			before[last_move_first][last_move_second] = {last_move_first - 1, last_move_second};
			
			
		}
		else if (last_move_first == last_move_second + 1) {// first car can come from (0 ~ last_move_second - 1)
			ret = INF;
			int possible_before = -1;
			for (int i = 0; i <= last_move_second - 1; i++) {
				if (CalcMinDist(i, last_move_second) + Distance(incident[last_move_first], (i == 0) ? make_pair(1, 1) : incident[i]) < ret) {
					ret = CalcMinDist(i, last_move_second) + Distance(incident[last_move_first], (i == 0) ? make_pair(1, 1) : incident[i]);
					possible_before = i;
				}
			}
			before[last_move_first][last_move_second] = {possible_before, last_move_second};
		}
	}
	else if  (last_move_first < last_move_second) {
		chosen[last_move_first][last_move_second] = 2;
		if (last_move_first + 1 < last_move_second) {
			ret = CalcMinDist(last_move_first, last_move_second - 1) + Distance(incident[last_move_second], incident[last_move_second - 1]);
			before[last_move_first][last_move_second] = {last_move_first, last_move_second - 1};
		}
		else if (last_move_first + 1 == last_move_second) {// second car can com from (0 ~ last_move_second - 1)
			ret = INF;
			int possible_before = -1;
			for (int i = 0; i <= last_move_first - 1; i++) {
				if (CalcMinDist(last_move_first, i) + Distance(incident[last_move_second], (i == 0) ? make_pair(city_size, city_size) : incident[i]) < ret) {
					ret = CalcMinDist(last_move_first, i) + Distance(incident[last_move_second], (i == 0) ? make_pair(city_size, city_size) : incident[i]);
					possible_before = i;
				}
			}
			before[last_move_first][last_move_second] = {last_move_first, possible_before};
		}
	}
	return ret;
}



int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> city_size >> num_incidents) {
		memset(min_dist, -1, sizeof(min_dist));
		vector<int> total_choice;
		for (int i = 1; i <= city_size; i++) {
			int y, x;
			cin >> y >> x;
			incident[i] = {y, x};
		}
		int min_cand = INF;
		int final_y_cand;
		int final_x_cand;
		for (int i = 0; i < num_incidents; i++) {
			if (min_cand > CalcMinDist(num_incidents, i)) {
				min_cand = CalcMinDist(num_incidents, i);
				final_y_cand = num_incidents;
				final_x_cand = i;
			}
			if (min_cand > CalcMinDist(i, num_incidents)) {
				min_cand = CalcMinDist(i, num_incidents);
				final_y_cand = i;
				final_x_cand = num_incidents;
			}
		}
		cout << min_cand << "\n";
		while (!(final_y_cand == 0 && final_x_cand == 0)) {
			//cout << final_y_cand << " " << final_x_cand <<  "\n";
			total_choice.push_back(chosen[final_y_cand][final_x_cand]);
			pii before_here = before[final_y_cand][final_x_cand];
			
			final_y_cand = before_here.first;
			final_x_cand = before_here.second;
		}
		
		for (int i = total_choice.size() - 1; i >= 0 ; i--) {
			cout << total_choice[i] << "\n";
		}
		//cout << final_y_cand << " " << final_x_cand << "\n";
		
		// for (int i = 0; i <= num_incidents; i++) {
		// 	for (int j = 0; j <= num_incidents; j++) {
		// 		cout << i << " " << j << " " << CalcMinDist(i, j) << "\n";
		// 	}
		// }
		
	}
	
	
    

    return 0;
}

