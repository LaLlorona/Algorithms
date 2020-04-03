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

int num_people;
vector<int> wait_time;



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_people) {
		long long total_time = 0;
		wait_time.clear();
		int time_withdraw;
		for (int i = 0; i < num_people; i++) {
			cin >> time_withdraw;
			wait_time.push_back(time_withdraw);
		}
		sort(wait_time.begin(), wait_time.end());
		for (int i = 0; i < num_people; i++) {
			total_time += (num_people - i) * wait_time[i]; 
		}
		cout << total_time << "\n";
	}
    

    return 0;
}

