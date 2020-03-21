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

int n;
long long padoban[101];

void PadobanSequence() {
	padoban[1] = 1;
	padoban[2] = 1;
	padoban[3] = 1;
	padoban[4] = 2;
	padoban[5] = 2;
	for (int i = 6; i < 101; i++){
		padoban[i] = padoban[i - 1] + padoban[i - 5];	
	}
}

int main()
{
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	cin >> num_testcase;
	PadobanSequence();
	for (int i = 0; i < num_testcase; i++) {
		cin >> n;
		cout << padoban[n] << "\n";
	}
	
}


