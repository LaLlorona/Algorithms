
#include <bits/stdc++.h>


using namespace std;

typedef pair<int, int> pii;

vector<pii> meetings;
int num_meetings;

int maxMeetings() {
    int end_time = meetings[0].first;
    int begin_time = meetings[0].second;
    int current_meetings = 1;
    for (int i = 1; i < num_meetings; i++) {
        if (meetings[i].second >= end_time) {
            current_meetings++;
            end_time = meetings[i].first;
            begin_time = meetings[i].second;
        }
    }
    return current_meetings;
}


int main()
{
    std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
    std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
    // std::ifstream in("in.txt");
    // std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    // std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    while (cin >> num_meetings) {
        meetings.clear();
        for (int i = 0; i < num_meetings; i++) {
            int a, b;
            cin >> a >> b;
            meetings.push_back(make_pair(b, a));
        }
        sort(meetings.begin(), meetings.end());
        cout << maxMeetings();

    }
    return 0;
}


