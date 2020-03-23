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


bool compair(pair<vector<int>, string> a, pair<vector<int>, string> b) {
	if (a.first[0] != b.first[0]) {
		return a.first[0] > b.first[0];
	}
	else if (a.first[1] != b.first[1]) {
		return a.first[1] < b.first[1];
	}
	else if (a.first[2] != b.first[2]) {
		return a.first[2] > b.first[2];
	}
	else {
		return a.second < b.second;
	}
}

int main()
{
	
	std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	cin >> n;
	string name;
	int korean;
	int english;
	int math;
		
	vector<pair<vector<int>, string > > input(0);
	
		
	for (int i = 0; i < n; i++) {
		cin >> name;
		cin >> korean >> english >> math;
		vector<int> scores = {korean, english, math};
		input.push_back(make_pair(scores, name));
	}
    
	sort(input.begin(), input.end(), compair);
	for (int i = 0; i < n; i++){
		cout << input[i].second << "\n";
	}
	
    return 0;
}

