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

int num_deck;
int num_mycards; 
vector<int> my_cards;

int BinarySearch(int target) {
	int lo = 0;
	int hi = num_mycards - 1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (my_cards[mid] == target) {
			return 1;
		}
		
		else if (my_cards[mid] > target) {
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	return 0;
}
int main()
{
	
	
	
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	
	while (cin >> num_mycards) {
		my_cards.clear();
		int card;
		for (int i = 0; i < num_mycards; i++) {
			cin >> card;
			my_cards.push_back(card);	
		}
		sort(my_cards.begin(), my_cards.end());
		cin >> num_deck;
		for (int i = 0; i < num_deck; i++) {
			cin >> card;
			cout << BinarySearch(card) << " ";
		}
		
		
	}
    

    return 0;
}

