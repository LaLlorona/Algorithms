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

string input;
vector<int> input_vector;

int CharToInt(char a) {
	return a - 48;
}
void PreProcess() {
	for (int i = 0; i < input.size(); i++) {
		input_vector.push_back(CharToInt(input[i]));
	}
	sort(input_vector.begin(), input_vector.end(),  greater<int>());
}

void MaxThirty() {
	bool div_three = false;
	bool div_ten = false;
	int div_three_cheker = 0;
	for (int i = 0; i < input_vector.size(); i++) {
		div_three_cheker += input_vector[i];
		if (input_vector[i] == 0) {
			div_ten = true;
		}
	}
	div_three = (div_three_cheker % 3 == 0);
	if (div_three && div_ten) {
		for (int i = 0; i < input_vector.size(); i++) {
			cout << input_vector[i] ;
		}
	}
	else{
		cout << -1;
	}
	cout << "\n";
}
 


int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> input) {
		input_vector.clear();
		PreProcess();
		MaxThirty();
		
	}
    

    return 0;
}

