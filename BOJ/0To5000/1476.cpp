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

int divide_or_sustain(int a, int b) {
	if (a == b) {
		return a;
	}
	else if (a % b == 0) {
		return b;
	}
	else{
		return a % b;
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
	
	int a, b, c;
	
	while (cin >> a >> b >> c) {
		for (int i = 1; i <= 15 * 28 * 19; i++) {
			if (divide_or_sustain(i, 15) == a && divide_or_sustain(i, 28) == b && divide_or_sustain(i, 19) == c) {
				cout << i << "\n";
				break;
			}
		}
	}
    

    return 0;
}

