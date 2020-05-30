#include <bits/stdc++.h>


using namespace std;

int n;
bool shoot_result[50][50];



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
		cin >> n;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				char input_num;
				cin >> input_num;
				shoot_result[y][x] = input_num - '0';
			}
		}
		// for (int y = 0; y < n; y++) {
		// 	for (int x = 0; x < n; x++) {
				
		// 		cout << shoot_result[y][x]; 
		// 	}
		// 	cout << "\n";
		// }
		bool fraud = false;
		for (int y = n - 2; y >= 0; y--) {
			for (int x = n - 2; x >= 0; x--) {
				if (shoot_result[y][x] && (!shoot_result[y + 1][x] && !shoot_result[y][x + 1])) {
					fraud = true;
				}
			}
		}
		if (fraud) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	
		
	}
    

    return 0;
}

