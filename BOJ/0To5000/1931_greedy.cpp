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
int max_meeting[100002]; //saves maximum number of meeting when considering ith meeting
int before[100002]; // when choosing ith meeting, before[i] is the time where we can select the meeting that does not overlapping
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
	
	
	int begin_time;
	int end_time;
	while (cin >> num_meeting) {
		schedule.clear();
		for (int i = 0; i < num_meeting; i++) {
			cin >> begin_time >> end_time;
			schedule.push_back(make_pair(end_time, begin_time));
		}
		sort(schedule.begin(), schedule.end(), compair);
		cout << FindMaximumMeeting() << "\n";
		
		
		
		
	}
    

    return 0;
}

