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


bool compair(pair<int,int> a, pair<int, int> b){
	if (a.first != b.first) {
		return a.first < b.first;
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
	int first;
	int second;
		
	vector<pair<int ,int> > input(0);
	
		
	for (int i = 0; i < n; i++) {
		cin >> first;
		cin >> second;
		input.push_back(make_pair(first, second));
		
		
	}
    
	sort(input.begin(), input.end(), compair);
	for (int i = 0; i < n; i++){
		cout << input[i].first << " " << input[i].second << "\n";
	}
    return 0;
}

