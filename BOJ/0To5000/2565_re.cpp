#include <bits/stdc++.h>


using namespace std;
;
const int MAX = 101;
typedef pair<int, int> pii;


vector<pii> input;
vector<int> sorted;
int len_input;
int cache[MAX];

int LIS(int from) {
    if (from == len_input - 1) {
        return 1;
    }
    int& ret = cache[from];

    if (ret != -1) {
        return ret;
    }

    int max_cand = 1;

    for (int i = from + 1; i < len_input; i++) {
        if (sorted[i] > sorted[from]) {
            max_cand = max(max_cand, LIS(i) + 1);
        }
    }
    ret = max_cand;
    return ret;
}



int main()
{
    std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
    std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
    // std::ifstream in("in.txt");
    // std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    // std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    while (cin >> len_input) {
        memset(cache, -1, sizeof(cache));
        input.clear();
        sorted.clear();
        for (int i = 0; i <len_input; i++) {
            int a, b;
            cin >> a >> b;
            input.push_back(make_pair(a, b));
        }
        sort(input.begin(), input.end());
        for (int i = 0; i < len_input; i++) {
            sorted.push_back(input[i].second);
        }
        int max_cand = 1;
        for (int i = 0; i < len_input; i++) {
            max_cand = max(max_cand, LIS(i));
        }
        cout << len_input - max_cand << "\n";

    }


    return 0;
}