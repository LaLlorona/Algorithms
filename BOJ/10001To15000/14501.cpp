#include <bits/stdc++.h>


using namespace std;

const int INF = 987654321;

int day_until_resignation;
int pay[16];
int time_to_counceling[16];

int cache[16];


int MaxPayFromDay(int from) {
	if (from > day_until_resignation + 1) {
		return - INF;
	}
	if (from == day_until_resignation + 1) {
		return 0;
	}
	if (from == day_until_resignation) {
		if (time_to_counceling[from] == 1) {
			return pay[from];
		}
		else {
			return 0;
		}
	}
	int& ret = cache[from];
	
	if (ret != -1) {
		return ret;
	}
	
	ret = 0;
	ret = max(pay[from] + MaxPayFromDay(from + time_to_counceling[from]), MaxPayFromDay(from + 1));
	return ret;
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	while (cin >> day_until_resignation) {
		int daily_pay;
		int daily_time;
		for (int i = 1; i <= day_until_resignation; i++) {
			cin >> daily_time >> daily_pay;
			pay[i] = daily_pay;
			time_to_counceling[i] = daily_time;
		}
		memset(cache, -1, sizeof(cache));
		cout << MaxPayFromDay(1) << "\n";
	
	}
    

    return 0;
}

