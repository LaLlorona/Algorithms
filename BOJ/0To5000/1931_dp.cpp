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
int max_meeting[100002]; //saves maximum number of meeting if ending time is 'i'
int before[100002]; // possible time to choose when you choose a schedule of ending time 'i'
vector<pair <int, int> > schedule; // saves shedule. first : ending time, second: begin time


bool compair(pair<int, int> schedule_a, pair<int, int> schedule_b) {
	if (schedule_a.first != schedule_b.first) {
		return schedule_a.first < schedule_b.first;
	}	
	else{
		return schedule_a.second < schedule_b.second;
	}
}

void PreProcess() {
	memset(before, 0, sizeof(before));
	
	int first_end_time = schedule[0].first;
	int last_end_time = schedule.back().first;
	
	for (int i = 0; i < first_end_time; i++) {
		before[i] = 0;
	}
	
	for (int i = 0; i < num_meeting; i++) {
		before[schedule[i].first] = schedule[i].second;
	}
	

	
	
	
	max_meeting[first_end_time] = 1;
	for (int i = first_end_time + 1; i <= last_end_time; i++ ) {
		max_meeting[i] = max(max_meeting[i], max(max_meeting[i - 1], 1 + max_meeting[before[i]]));
	}
	
}

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int begin_time;
	int end_time;
	while (cin >> num_meeting) {
		schedule.clear();
		for (int i = 0; i < num_meeting; i++) {
			cin >> begin_time >> end_time;
			schedule.push_back(make_pair(end_time, begin_time));
		}
		sort(schedule.begin(), schedule.end(), compair);
		// for (int i = 0; i < num_meeting; i++) {
		// 	cout << schedule[i].first << " " << schedule[i].second << "\n";
		// }
		PreProcess();
		// for (int i = 0; i <= 14; i++) {
		// 	cout << i << "," << max_meeting[i] << " ";
		// }
		cout << max_meeting[schedule.back().first];
		
		
		
	}
    

    return 0;
}

