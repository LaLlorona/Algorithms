#include <bits/stdc++.h>
#include <sstream>
using namespace std;

typedef tuple<int, int, string> iis;


int timeToMinute(string time) {
	string hourPart = time.substr(0, 2);
	stringstream intHourPart(hourPart);
	int hour;
	intHourPart >> hour;

	string minutePart = time.substr(3, 2);
	stringstream intMinutePart(minutePart);
	int minute;
	intMinutePart >> minute;

	return hour * 60 + minute;

}

int stringToInt(string inputStr) {
	stringstream intOfInputStr(inputStr);
	int result;
	intOfInputStr >> result;
	return result;
}

vector<string> solution(vector<vector<string>> plans) {
	vector<iis> timePlan;
	for (int i = 0; i < plans.size(); i++) {	
		iis hwInfo;
		hwInfo = {timeToMinute(plans[i][1]), stringToInt(plans[i][2]), plans[i][0]}; //begintime, lefttime, hwname
		timePlan.push_back(hwInfo);
	}
	sort(timePlan.begin(), timePlan.end());

	iis currentWorkingHw;
	stack<iis> hwTodo;

	for (int i = 0; i < timePlan.size(); i++) {
		if (get<1>(currentWorkingHw) == -1) { // when there is no working hw
			currentWorkingHw = timePlan[i];
		}
		else {
			
		}
	}



    vector<string> answer;
    return answer;
}

int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(in.rdbuf()); 

	string a = "12:30";
	string b = "11:20";

	cout << a.compare(b) << "\n";

	cout << b.compare(a) << "\n";

	cout << timeToMinute("12:30") << " " << timeToMinute("00:30") << "\n";

	vector<vector<string>> plan1 = {{"korean", "11:40", "30"}, {"english", "12:10", "20"}, {"math", "12:30", "40"}};

	solution(plan1);



}


  