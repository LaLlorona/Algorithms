#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>



using namespace std;

int n;
map<char, pair<char, char> >tree;

void PreOrder(char from) {
	if (from != '.') {
		cout << from;
		PreOrder(tree[from].first);
		PreOrder(tree[from].second);
	}
}

void InOrder(char from) {
	if (from != '.') {
		InOrder(tree[from].first);
		cout << from;
		InOrder(tree[from].second);
	}
}

void PostOrder(char from) {
	if (from != '.') {
		PostOrder(tree[from].first);
		PostOrder(tree[from].second);
		cout << from;
	}
}

int main()
{
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int n;
	char a, b, c;
	while (cin  >> n) {
		for (int i = 0; i < n; i++) {
			cin >> a >> b >> c;
			tree[a] = make_pair(b, c);
		}
		PreOrder('A');
		cout << endl;
		InOrder('A');
		cout << endl;
		PostOrder('A');
		cout << endl;
		
		
	}
	 
	

    return 0;
}

