#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;

const int INF = 987654321;
const int MAX = 1001;
int n;
int min_time_make[MAX][MAX]; // current number of emoticons on the screen and the number of emoticons on the clipboard



int FillMinTimeMake() {
	priority_queue<piii, vector<piii>, greater<piii> > pq; // {time, {number of emoticon on the screen, and clipboard}
	min_time_make[1][0] = 0;
	pq.push({0, {1, 0}});
	while (!pq.empty()) {
		int make_time = pq.top().first;
		int number_of_emoticon_screen = pq.top().second.first;
		int number_of_emoticon_clipboard = pq.top().second.second;
		if (number_of_emoticon_screen == n) {
			return make_time;
		}
		pq.pop();
		
		if (min_time_make[number_of_emoticon_screen][number_of_emoticon_clipboard] == 0) { // when current state is not visited
			//cout << make_time << " " << number_of_emoticon_screen << " " << number_of_emoticon_clipboard << "\n";
			min_time_make[number_of_emoticon_screen][number_of_emoticon_clipboard] = make_time;
			//1. save in the clipboard
			pq.push({make_time + 1, {number_of_emoticon_screen, number_of_emoticon_screen}});
			
			//2. paste on the screen
			if (number_of_emoticon_screen + number_of_emoticon_clipboard <= MAX) {
				pq.push({make_time + 1, {number_of_emoticon_screen + number_of_emoticon_clipboard, number_of_emoticon_clipboard}});
			}
			
			
			//3. remove one of the emoticon
			if (number_of_emoticon_screen >= 1) {
				pq.push({make_time + 1, {number_of_emoticon_screen - 1, number_of_emoticon_clipboard}});
			}
		}
	}
	return INF;
	
	
}
int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	memset(min_time_make, 0, sizeof(min_time_make));
	
	while (cin >> n) {
		cout << FillMinTimeMake() << "\n";
	}
    

    return 0;
}

