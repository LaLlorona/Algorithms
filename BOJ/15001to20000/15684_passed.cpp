#include <bits/stdc++.h>


using namespace std;

int n;
int initial_stair[100][100]; 
int updated_stair[100][100];

int ret = 4;
int height;
int width;
int num_initial_stair;


bool PossibleToReach() {
	
	bool passed = true;
	for (int i = 1; i <= width; i++) {
		int here_x = i;
		for (int j = 1; j <= height; j++) {
			if (updated_stair[j][here_x] != 0) {
				here_x++;
			}
			else if(here_x > 1 && updated_stair[j][here_x - 1] != 0) {
				here_x--;
			}
			
		}
		if (here_x != i) {
			passed = false;
			break;
		}
	}
	return passed;
}

void DFS(int num_chosen, int current_y) {
	if (num_chosen >= ret) {
		return;
	}
	else if (num_chosen >= 4) {
		return;
	}
	else if (PossibleToReach()) {
		// for (int y = 1; y <= height; y++) {
		// 	for (int x = 1; x <= width; x++) {
		// 		cout << updated_stair[y][x] << " ";
		// 	}
		// 	cout << "\n";
		// }
		// cout << "num_chosen is " << num_chosen << "\n";
		ret = min(ret, num_chosen);
	}
	else {
	
		for (int y = current_y; y <= height; y++) {
			for (int x = 1; x < width; x++) {
				if (updated_stair[y][x] == 0 && updated_stair[y][x - 1] == 0 && updated_stair[y][x + 1] == 0) {
					updated_stair[y][x] = 1;
					DFS(num_chosen + 1, y);
					updated_stair[y][x] = 0;
				}
			}
		}
		
		
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
	while (cin >> width >> num_initial_stair >> height) {
		memset(updated_stair, 0 ,sizeof(updated_stair));
		ret = 4;
		
		for (int i = 0; i < num_initial_stair; i++) {
			
			int position_y;
			int position_x;
			cin >> position_y >> position_x;
			updated_stair[position_y][position_x] = 1;
				
		}
		DFS(0,1);
		if (ret == 4) {
			cout << -1 << "\n";
		}
		else {
			cout << ret << "\n";
		}
		
		
	
	}
    

    return 0;
}

