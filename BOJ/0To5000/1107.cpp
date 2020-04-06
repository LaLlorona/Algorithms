#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>



using namespace std;

vector<int> buttons;

bool broken[10];

const int INF = 987654321;
int target_channel;
int num_broken;


int CheckPressButton(int channel) {
	if (channel < 10) {
		if (broken[channel]) {
			return INF;
		}
		else {
			return 1;
		}
	}
	else{
		int n = channel;
		int len = 0;
		while (n > 0) {
			if (broken[n % 10]) {
				return INF;
			}
			else{
				n /= 10;
				len++;
			}
		}
		return len;
	}
}

int Solve() {
	int min_press = INF;
	for (int i = 0; i <= 1000000; i++) {
		int result = CheckPressButton(i);
		if (result != INF) {
			min_press = min(min_press, result + abs(i - target_channel));
		}
	}
	return min(min_press, abs(target_channel - 100));
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	int broken_button;
	int num_broken;
	
	while (cin >> target_channel) {
		memset(broken, 0 ,sizeof(broken));
		cin >> num_broken;
		for (int i = 0; i < num_broken; i++) {
			cin >> broken_button;
			broken[broken_button] = true;
		}
		cout << Solve() << endl;
		//cout << CheckPressButton(555);
		
	
	}
    

    return 0;
}

