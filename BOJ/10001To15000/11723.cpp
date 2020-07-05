#include <bits/stdc++.h>


using namespace std;

int num_command;
string command;
int command_num;
int problem_set = 0;

void ExcuteCommand(string command, int num) {
	if (command == "add") {
		problem_set = problem_set | (1 << (num - 1));
	}
	else if (command == "remove") {
		problem_set = problem_set & ~(1 << (num - 1));
	}
	else if (command == "check") {
		if (problem_set & (1 << (num - 1))) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
	}
	else if (command == "toggle") {
		problem_set = problem_set ^ (1 << (num - 1));
	}
	else if (command == "all") {
		problem_set = ((1 << 20) - 1);
	}
	else {
		problem_set = 0;
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
	int num_command;
	cin >> num_command;


	command_num = 0;
	problem_set = 0;
	for (int i = 0; i < num_command; i++) {
		cin >> command;
		if (command != "all" && command != "empty") {
			cin >> command_num;
		}
		ExcuteCommand(command, command_num);
		
	}


    

    return 0;
}

