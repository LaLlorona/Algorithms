
#include <bits/stdc++.h>


using namespace std;

int num_coin_type;
int target_value;
int coin_value[11];

int calcMinCoin() {
    int value_left = target_value;
    int num_used_coin = 0;
    for (int i = num_coin_type - 1; i >= 0; i--) {
        if (value_left / coin_value[i] != 0) {
            num_used_coin += value_left / coin_value[i];
            value_left = value_left % coin_value[i];
        }

        if (value_left % coin_value[i] == 0) {
            break;
        }
    }
    return num_used_coin;
}


int main()
{
    std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
    std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
    // std::ifstream in("in.txt");
    // std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    // std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    while (cin >> num_coin_type >> target_value) {
        for (int i = 0; i < num_coin_type; i++) {
            cin >> coin_value[i];
        }
        cout << calcMinCoin() << "\n";
    }
    return 0;
}


