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

int num_meeting;
vector<pair <int, int> > schedule; // saves shedule. first : ending time, second: begin time


bool compair(pair<int, int> schedule_a, pair<int, int> schedule_b) {
	if (schedule_a.first != schedule_b.first) {
		return schedule_a.first < schedule_b.first;
	}	
	else{
		return schedule_a.second < schedule_b.second;
	}
}

int FindMaximumMeeting() {
	int earliest = 0;
	int total_schedules = 0;
	for (int i = 0; i < num_meeting; i++) {
		int current_begin_time = schedule[i].second;
		int current_end_time = schedule[i].first;
		if (current_begin_time >= earliest) {
			total_schedules++;
			earliest = current_end_time;
		}
	}
	return total_schedules;
}

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int begin_time;
	int end_time;
	while (cin >> num_meeting) {
	
		
		
		
	}
    

    return 0;
}

