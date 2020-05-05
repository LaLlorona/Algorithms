#include <bits/stdc++.h>


using namespace std;
int width, height;

int dice_axis[4] = {0, 0, 0, 0};
int dice_left[2] = {0, 0};
int dct_x[4] = {1, -1, 0, 0};
int dct_y[4] = {0, 0, -1, 1};
int board[21][21];
int commands[1001];
int initial_y;
int initial_x;
int num_commands;

bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 && x < width);
}

void RoleDiceOneTime(int direction) {
	if (direction == 0) {
		int temp = dice_axis[3];
		dice_axis[3] = dice_axis[2];
		dice_axis[2] = dice_axis[1];
		dice_axis[1] = dice_axis[0];
		dice_axis[0] = temp;
	}
	else if (direction == 1) {
		int temp = dice_axis[0];
		dice_axis[0] = dice_axis[1];
		dice_axis[1] = dice_axis[2];
		dice_axis[2] = dice_axis[3];
		dice_axis[3] = temp;
	}
	else if (direction == 2) {
		int left_one = dice_left[0];
		int left_two = dice_left[1];
		dice_left[0] = dice_axis[2];
		dice_left[1] = dice_axis[0];
		dice_axis[0] = left_one;
		dice_axis[2] = left_two;
	}
	else {
		int left_one = dice_left[0];
		int left_two = dice_left[1];
		dice_left[0] = dice_axis[0];
		dice_left[1] = dice_axis[2];
		dice_axis[0] = left_two;
		dice_axis[2] = left_one;
	}
}

void RoleDiceSeveralTimes() {
	int current_y = initial_y;
	int current_x = initial_x;
	for (int i = 0; i < num_commands; i++) {
		int next_y = dct_y[commands[i]] + current_y;
		int next_x = dct_x[commands[i]] + current_x;
		if (IsInBound(next_y, next_x)) {
			RoleDiceOneTime(commands[i]);
			cout << dice_axis[0] << "\n";
			
			if (board[next_y][next_x] == 0) {
				board[next_y][next_x] = dice_axis[2];
			}
			else {
				dice_axis[2] = board[next_y][next_x];
				board[next_y][next_x] = 0;
			}
			
			current_y = next_y;
			current_x = next_x;
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
	
	
	
	while (cin >> height >> width >> initial_y >> initial_x >> num_commands) {
		memset(dice_axis, 0 ,sizeof(dice_axis));
		memset(dice_left, 0 , sizeof(dice_left));
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				cin >> board[y][x];
			}
		}
		for (int i = 0; i < num_commands; i++) {
			cin >> commands[i];
			commands[i]--;
		}
		RoleDiceSeveralTimes();
		
		
	}
    

    return 0;
}

