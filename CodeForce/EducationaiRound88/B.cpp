#include <bits/stdc++.h>


using namespace std;

int n, m, price_one, price_two;
bool tile[100][1000];




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
		cin >> n >> m >> price_one >> price_two;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				char a;
				cin >> a;
				if (a == '.') {
					tile[y][x] = 0;
				}
				else {
					tile[y][x] = 1;
				}
			}
		}
		int to_pay = 0;
		for (int y = 0; y < n; y++) {
			int to_fill = 0;
			for (int x = 0; x < m; x++) {
				if (tile[y][x] == 0 ) {
					to_fill++;
					if (x == m - 1) {
						//cout << to_fill << "\n";
						
						if (to_fill % 2 == 0) {
							to_pay += min(to_fill / 2 * price_two , to_fill * price_one);
						}
						else {
							//cout << min(to_fill / 2 * price_two + price_one, to_fill * price_one) << "\n";
							to_pay += min(to_fill / 2 * price_two + price_one, to_fill * price_one);
						}
						to_fill = 0;
						
					}
				}
				else {
					if (to_fill % 2 == 0) {
							to_pay += min(to_fill / 2 * price_two , to_fill * price_one);
						}
					else {
						//cout << min(to_fill / 2 * price_two + price_one, to_fill * price_one) << "\n";
						to_pay += min(to_fill / 2 * price_two + price_one, to_fill * price_one);
					}
					to_fill = 0;
				}
			}
		}
		cout << to_pay << "\n";
		

	}
    

    return 0;
}

