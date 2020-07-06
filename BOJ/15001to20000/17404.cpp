#include <bits/stdc++.h>


using namespace std;

const int INF = 987654321;
int num_houses;


int houses[1000][3];

int red_not_red_first[1000];
int green_not_red_first[1000];
int blue_not_red_first[1000];

int red_not_green_first[1000];
int green_not_green_first[1000];
int blue_not_green_first[1000];

int red_not_blue_first[1000];
int green_not_blue_first[1000];
int blue_not_blue_first[1000];

void UpdateRGB() {
	red_not_red_first[0] = INF;
	green_not_red_first[0] = houses[0][1];
	blue_not_red_first[0] = houses[0][2];
	
	red_not_green_first[0] = houses[0][0];
	green_not_green_first[0] = INF;
	blue_not_green_first[0] = houses[0][2];
	
	red_not_blue_first[0] = houses[0][0];
	green_not_blue_first[0] = houses[0][1];
	blue_not_blue_first[0] = INF;
	
	for (int i = 1; i < num_houses; i++) {
		red_not_red_first[i] = houses[i][0] + min(green_not_red_first[i - 1], blue_not_red_first[i - 1]);
		green_not_red_first[i] = houses[i][1] + min(red_not_red_first[i - 1], blue_not_red_first[i - 1]);
		blue_not_red_first[i] = houses[i][2] + min(green_not_red_first[i - 1], red_not_red_first[i - 1]);
		
		red_not_green_first[i] = houses[i][0] + min(green_not_green_first[i - 1], blue_not_green_first[i - 1]);
		green_not_green_first[i] = houses[i][1] + min(red_not_green_first[i - 1], blue_not_green_first[i - 1]);
		blue_not_green_first[i] = houses[i][2] + min(green_not_green_first[i - 1], red_not_green_first[i - 1]);
		
		red_not_blue_first[i] = houses[i][0] + min(green_not_blue_first[i - 1], blue_not_blue_first[i - 1]);
		green_not_blue_first[i] = houses[i][1] + min(red_not_blue_first[i - 1], blue_not_blue_first[i - 1]);
		blue_not_blue_first[i] = houses[i][2] + min(green_not_blue_first[i - 1], red_not_blue_first[i - 1]);
	}
	
	
}

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_houses) {
		
		vector<int> max_cand;
		for (int i = 0; i < num_houses; i++) {
			int r, g, b;
			cin >> r >> g >> b;
			houses[i][0] = r;
			houses[i][1] = g;
			houses[i][2] = b;
		}
		UpdateRGB();
		max_cand.push_back(red_not_red_first[num_houses - 1]);
		//max_cand.push_back(red_not_green_first[num_houses - 1]);
		//max_cand.push_back(red_not_blue_first[num_houses - 1]);
		
		//max_cand.push_back(green_not_red_first[num_houses - 1]);
		max_cand.push_back(green_not_green_first[num_houses - 1]);
		//max_cand.push_back(green_not_blue_first[num_houses - 1]);
		
		//max_cand.push_back(blue_not_red_first[num_houses - 1]);
		//max_cand.push_back(blue_not_green_first[num_houses - 1]);
		max_cand.push_back(blue_not_blue_first[num_houses - 1]);
		
		sort(max_cand.begin(), max_cand.end());
		cout << max_cand[0] << "\n";
	}
    

    return 0;
}

