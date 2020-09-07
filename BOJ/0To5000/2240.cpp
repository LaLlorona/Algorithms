#include <bits/stdc++.h>


using namespace std;

int max_plums_time_move_pos[1002][31][2];
int plum_pos_at_time[1001];
int total_time, max_move;


const int INF = 987654321;

int ChangePos(int n) {
	if (n == 1) {
		return 0;
	}
	
	return 1;
}

int CalcMaxPlums(int time, int left_move, int pos) {
	//cout << time << " " << left_move << " " << pos << "\n";
	if (time == 0) {
		return 0;
	}
	else if (time == 1 && pos == 1) {
		if (plum_pos_at_time[time] == pos) {
			return CalcMaxPlums(time, left_move - 1, ChangePos(pos)) + 1;
		}
		else {
			return CalcMaxPlums(time, left_move - 1, ChangePos(pos));
		}
		
	}
	else if (left_move < 0) {
		return -INF;
	}
	
	int& ret = max_plums_time_move_pos[time][left_move][pos];
	if (ret != -1) {
		return ret;
	}
	
	
	if (plum_pos_at_time[time] != pos) { // when plum does not drop at the current position
		ret = CalcMaxPlums(time - 1, left_move, pos);
	}
	else {//when a plum drops at the current position
		ret = max(CalcMaxPlums(time - 1, left_move, pos), CalcMaxPlums(time, left_move - 1, ChangePos(pos))) + 1;
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
	
	while (cin >> total_time >> max_move) {
		memset(max_plums_time_move_pos, -1, sizeof(max_plums_time_move_pos));
		for (int i = 1; i <= total_time; i++) {
			cin >> plum_pos_at_time[i];
			plum_pos_at_time[i]--;
		}
		int max_cand = -INF;
		for (int last_left_move = 0; last_left_move <= max_move; last_left_move++) {
			for (int last_pos = 0; last_pos < 2; last_pos++) {
				max_cand = max(max_cand, CalcMaxPlums(total_time, last_left_move, last_pos));
			}
		} 
		cout << max_cand << "\n";
	}
    

    return 0;
}

