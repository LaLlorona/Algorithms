#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

int n;
int begin_num;
int target_num;
ll num_comb[101][21]; // when calculating until i th number, the number of combination of sum j is num_comb[i][j]
int input_arr[101];



int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	while (cin >> n) {
		memset(num_comb, 0, sizeof(num_comb));
		
		for (int i = 0; i < n; i++) {
			cin >> input_arr[i];
		}
		
		num_comb[0][input_arr[0]]++;
		for (int i = 1; i < n - 1; i++) {
			for (int j = 0; j < 21; j++) {
				if (num_comb[i - 1][j] > 0) {
					int current_num = input_arr[i];
					if (j + current_num <= 20) { // 
						num_comb[i][j + current_num] += num_comb[i - 1][j];
					}
					if (j - current_num >= 0) {
						num_comb[i][j - current_num] += num_comb[i - 1][j];
					}
				}
			}
		}
		// for (int i = 0; i < 101; i++) {
		// 	for (int j = 0; j < 21; j++) {
		// 		if (num_comb[i][j] != 0) {
		// 			cout << i << " " << j << " " << num_comb[i][j] << "\n";
		// 		}
		// 	}
		// }
		cout << num_comb[n - 2][input_arr[n - 1]] << "\n";
	}
    

    return 0;
}

