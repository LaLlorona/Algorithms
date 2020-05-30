#include <bits/stdc++.h>


using namespace std;

int n;



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		int card, joker, player;
		cin >> card >> joker >> player;
		int max_joker = min(joker, card / player);
		int other_joker = (int) ceil((double)(joker - max_joker) / (player - 1));
		//cout << other_joker << "\n";
		if (max_joker == joker) {
			cout << max_joker << "\n";
		}
		else {
			
			cout << max_joker - other_joker << "\n";
			
		}
	}
    

    return 0;
}

