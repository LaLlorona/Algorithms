#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
int n;

ll increasing_num[65][10]; // increasing_num[i][j]: number of increasing num if it has i digit and last number is j

void FillIncreasingNum() {
	memset(increasing_num, 0, sizeof(increasing_num));
	for (int i = 0; i <= 9; i++) {
		increasing_num[1][i] = 1;
	}
	for (int i = 2; i <= 64; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				increasing_num[i][j] += increasing_num[i - 1][k];
			}
		} 
	}
}



int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	FillIncreasingNum();
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		ll result = 0;
		int digit;
		cin >> digit;
		for (int i = 0; i <= 9; i++) {
			result += increasing_num[digit][i];
		}
		cout << result << "\n";
	}
    

    return 0;
}

