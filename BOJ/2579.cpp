#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int max_point[301];
int seq[301];
int n;

void CalcMaxPoint() {
	max_point[0] = seq[0];
	max_point[1] = seq [0] + seq[1];
	max_point[2] = max(seq[0] + seq[2], seq[1] + seq[2]);
	
	for (int i = 3; i < n; i++) {
		max_point[i] = max(max_point[i - 2] + seq[i], max_point[i - 3] + seq[i] + seq[i - 1]);
	}
	
	
}
int main()
{
	//std::ifstream in("in.txt");
	//std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	//std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> seq[i];	
	}
	CalcMaxPoint();
	cout << max_point[n - 1] << endl;
		
		
	
	
 
	

    return 0;
}


