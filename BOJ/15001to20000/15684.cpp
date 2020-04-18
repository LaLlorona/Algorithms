#include <bits/stdc++.h>


using namespace std;

int n;
int initial_stair[100][100]; // stair[a][b] indicates another stair that can be reached from 'b' th stair in height 'a'. when there is no stair, the value is -1
int updated_stair[100][100];

int ret;
int height;
int width;
int num_initial_stair;

vector<pair<int, int> >  temp;
vector<vector<pair<int, int> > > build_position;

bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 && x < width);
}

void FillBuildPosition(int current_stair, int num_chosen, int num_total) {
	if (num_chosen == num_total) {
		build_position.push_back(temp);
	}
	else if (current_stair >= width * height) {
		
	}
	else {
		int current_y = current_stair / width;
		int current_x = current_stair % width;
		if (IsInBound(current_y, current_x) && IsInBound(current_y, current_x + 1) && updated_stair[current_y][current_x] == -1 && updated_stair[current_y][current_x + 1] == -1) { //when building a stair between current_x and current_x + 1
			temp.push_back(make_pair(current_y, current_x));
			updated_stair[current_y][current_x] = current_x + 1;
			updated_stair[current_y][current_x + 1] = current_x;
			
			FillBuildPosition(current_stair + 1, num_chosen + 1, num_total);
			
			temp.pop_back();
			updated_stair[current_y][current_x] = -1;
			updated_stair[current_y][current_x + 1] = -1;
		
		}
		FillBuildPosition(current_stair + 1, num_chosen, num_total);
	}
}

bool PossibleToReach() {
	
	bool passed = true;
	for (int i = 0; i < width; i++) {
		int here_x = i;
		for (int j = 0; j < height; j++) {
			if (updated_stair[j][here_x] != -1) {
				here_x = updated_stair[j][here_x];
			}
			
		}
		if (here_x != i) {
			passed = false;
			break;
		}
	}
	return passed;
}

bool UpdateStairStatusAndCheck() {
	bool finished = false;
	for (int i = 0; i < build_position.size(); i++) {
		
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				updated_stair[y][x] = initial_stair[y][x];
			}
		}
		for (int j = 0; j < build_position[i].size(); j++) {
			int update_y = build_position[i][j].first;
			int update_x = build_position[i][j].second;
			updated_stair[update_y][update_x] = update_x + 1;
			updated_stair[update_y][update_x + 1] = update_x;
		}
		finished = PossibleToReach();
		if (finished) {
			break;
		}
	}
	return finished;
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
		memset(initial_stair, -1 ,sizeof(initial_stair));
		memset(updated_stair, -1 ,sizeof(updated_stair));
		
		for (int i = 0; i < num_initial_stair; i++) {
			
			int position_y;
			int position_x;
			cin >> position_y >> position_x;
			position_y--;
			position_x--;
			initial_stair[position_y][position_x] = position_x + 1;
			initial_stair[position_y][position_x + 1] = position_x;	
			updated_stair[position_y][position_x] = position_x + 1;
			updated_stair[position_y][position_x + 1] = position_x;	
		}
		
		for (int i = 0; i <= 3; i++) {
			bool check_finished = false;
			temp.clear();
			build_position.clear();
			FillBuildPosition(0, 0, i);
			check_finished = UpdateStairStatusAndCheck();
			if (check_finished) {
				cout << i << "\n";
				break;
			}
			else if (!check_finished && i == 3) {
				cout << -1 << "\n";
			}
		}
	}
    

    return 0;
}

