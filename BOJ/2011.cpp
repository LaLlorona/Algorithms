#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

const int NEG_INF = -987654321;
long long num_encrypt[5001];
string input;
int n;



vector<int> judge(string two_char) {
	vector<int> possible (0);
	if (two_char[0] == '0') { //01 ~ 09 
		
	}
	else if (two_char[1] == '0'  &&(two_char[0] == '1' || two_char[0] == '2')) { // 10, 20
		possible.push_back(2);
	}
	else if (two_char[1] == '0') { // 30, 40, 50, 60, 70, 80 ,90
	}
	else if (two_char[0] == '1') { // 11~ 19
		possible.push_back(1);
		possible.push_back(2);
	}
	else if (two_char[0] == '2' && two_char[1] <= '6') {
		possible.push_back(1);
		possible.push_back(2);
	}
	else{ // 27 ~ 99 - {30, 40 ~ 90}
		possible.push_back(1);
	}
	return possible;
	
}

int CalcEncrypt() {
	if (n == 1) {
		return (input[n -1] - '0' == 0) ? 0 : 1;
	}
	else if (n == 2) {
		return (judge(input).size());
	}
	else{
		num_encrypt[n - 1] = (input[n -1] - '0' == 0) ? 0 : 1;
		
		num_encrypt[n - 2] = (judge(input.substr(n - 2, 2)).size());
		
		
		for (int i = n - 3; i >= 0; i--) {
			vector<int> possible_analysis = judge(input.substr(i, 2));
			for (int j = 0; j < possible_analysis.size(); j++) {
				num_encrypt[i] += (num_encrypt[i + possible_analysis[j]]) % 1000000;
			}
		}
		return num_encrypt[0] % 1000000;
	}
	
}

int main()
{
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	// while (cin >> input) {
	// 	memset(num_encrypt, 0 ,sizeof(num_encrypt));
	// 	n = input.length();
	// 	cout << CalcEncrypt() << "\n";
	// }
	cin >> input;
	memset(num_encrypt, 0 ,sizeof(num_encrypt));
	n = input.length();
	cout << CalcEncrypt() << "\n";
	
	
	
	
	
	
	
	
 
	

    return 0;
}

