#include <bits/stdc++.h>


using namespace std;

int n;
int board[101][101];
char commands[10001];
int dct_y[4] = {0, 1, 0, -1};
int dct_x[4] = {1, 0, -1, 0};

bool IsInBound(int y, int x) {
	return (y >= 0 && y < n && x >= 0 && x < n);
}

int UpdateDirection(int current_direction, char input_command) {
	if (input_command == 'D') {
		current_direction++;
		return current_direction % 4;
	}
	else {
		current_direction--;
		if (current_direction == -1) {
			return 3;
		}
		else {
			return current_direction;
		}
	}
}


int PlayGame() {
	deque<pair<int, int > > snake;
	board[0][0] = 1;
	snake.push_back(make_pair(0, 0));
	int direction = 0;
	int current_x = 0;
	int current_y = 0;
	int current_second = 0;
	while (current_second <= 10000) {
		current_second++;
		
		// cout << "current direction is " << direction << "\n";
		int next_y = dct_y[direction] + current_y;
		int next_x = dct_x[direction] + current_x;
		
		if (!IsInBound(next_y, next_x)) {
			return current_second;
		}
		else if (board[next_y][next_x] == 1) {
			return current_second;
		}
		else {
			if (board[next_y][next_x] == 2) {
				board[next_y][next_x] = 1;
				snake.push_front(make_pair(next_y, next_x));
			}
			else {
				snake.push_front(make_pair(next_y, next_x));
				board[next_y][next_x] = 1;
				pair<int, int> tail = snake.back();
				snake.pop_back();
				board[tail.first][tail.second] = 0;
			}
		}
		// cout << current_second << "\n";
		// for (int y = 0; y < n; y++) {
		// 	for (int x = 0; x < n; x++) {
		// 		cout << board[y][x] << " ";
		// 	}
		// 	cout << "\n";
		// }
		current_x = next_x;
		current_y = next_y;
		if (commands[current_second] != 0) {
			// cout << "changed\n";
			direction = UpdateDirection(direction, commands[current_second]);
		}
	}
	return -1;
	
}

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
//     std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//     std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> n) {
		int num_apples;
		int num_commands;
		cin >> num_apples;
		memset(board, 0 ,sizeof(board));
		memset(commands, 0, sizeof(commands));
		
		
		for (int i = 0; i < num_apples; i++) {
			int apple_y;
			int apple_x;
			cin >> apple_y;
			cin >> apple_x;
			--apple_x;
			--apple_y;
			board[apple_y][apple_x] = 2;
		}
		
		cin >> num_commands;
		for (int i = 0; i < num_commands; i++) {
			int excute_second;
			char excute_direction;
			cin >> excute_second >> excute_direction;
			commands[excute_second] = excute_direction;
		}
		
		cout << PlayGame() << "\n";
		
		
		
		
		
	}
    

    return 0;
}

