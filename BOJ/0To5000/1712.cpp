#include <bits/stdc++.h>


using namespace std;

int a, b, c;



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	while (cin >> a >> b >> c) {
		if (b >= c) {
			cout << -1 << "\n";
		}
		else {
			if (a % (c - b) == 0) {
				cout << a / (c - b) + 1 << "\n";
			}
			else {
				cout << (int)ceil((double)a / (c - b)) << "\n";
			}
		}
	}
    

    return 0;
}

