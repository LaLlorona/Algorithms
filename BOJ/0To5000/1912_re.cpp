
#include <bits/stdc++.h>


using namespace std;

const int MAX = 100001;
int input_array[MAX];
int max_sum[MAX];
int len_arr;

void FillMaxSum() {
    max_sum[len_arr - 1] = input_array[len_arr - 1];
    for (int i = len_arr - 2; i >= 0; i--) {
        max_sum[i] = input_array[i] + max(0, max_sum[i + 1]);
    }
    int max_cand = -987654321;

    for (int i = 0 ; i < len_arr; i++) {
        max_cand = max(max_cand, max_sum[i]);
    }
    cout << max_cand << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
    std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
    // std::ifstream in("in.txt");
    // std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    // std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    while (cin >> len_arr) {
        for (int i = 0; i < len_arr; i ++) {
            cin >> input_array[i];
        }
        FillMaxSum();
    }
    return 0;
}


