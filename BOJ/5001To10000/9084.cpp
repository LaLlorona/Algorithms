#include <bits/stdc++.h>


using namespace std;

int num;
int num_coins;
int target_value;
int coins[21];
int num_combination[10001];




int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		memset(num_combination, 0, sizeof(num_combination));
		cin >> num_coins;
		for (int i = 0; i < num_coins; i++) {
			cin >> coins[i];
		}
		cin >> target_value;
		num_combination[0] = 1;
		for (int i = 0; i < num_coins; i++) {
			int current_coin = coins[i];
			num_combination[current_coin]++;
			for (int j = 1; j + current_coin < 10001; j++) {
				if (num_combination[j] > 0) {
					num_combination[j + current_coin] += num_combination[j];
				}
			}
		}
		cout << num_combination[target_value] << "\n";
	}
    

    return 0;
}

