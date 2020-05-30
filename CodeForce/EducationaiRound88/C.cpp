#include <bits/stdc++.h>


using namespace std;

int h, c, t;



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		cin >> h >> c >> t;
		if (h == t) {
			cout << 1 << "\n";
		}
		else if (2 * t <= (h + c)) {
			cout << 2 << "\n";
		}
		else {
			int k = (h - t) / (2 * t - h - c);
			int left = abs((2 * k + 1) * ((h * (k + 2)) + c * (k + 1)) - (2 * k + 1) * (2 * k + 3) * t);
			int right = abs((2 * k + 3) * ((h * (k + 1)) + c * (k)) - (2 * k + 1) * (2 * k + 3) * t);
			if (left >= right) {
				cout << 2 * k + 1 << "\n";
			}
			else {
				cout << 2 * k + 3 << "\n";
			}
		}
	}
    

    return 0;
}

