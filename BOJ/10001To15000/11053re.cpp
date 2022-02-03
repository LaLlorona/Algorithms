
#include <bits/stdc++.h>


using namespace std;
const int MAX = 1001;
const int INF = 987654321;
int len_array;
int input_array[MAX];
int cache[MAX];
int cache_LDS[MAX];

int LIS(int from) {
    if (from == len_array - 1) {
        return 1;
    }
    int& ret = cache[from];

    if (ret != -1) {
        return ret;
    }

    int max_cand = 1;

    for (int i = from + 1; i < len_array; i++) {
        if (input_array[i] > input_array[from]) {
            max_cand = max(max_cand, LIS(i) + 1);
        }
    }
    ret = max_cand;
    return ret;
}

int LDS(int from) {
    if (from == len_array - 1) {
        return 1;
    }
    int& ret = cache[from];

    if (ret != -1) {
        return ret;
    }

    int max_cand = 1;

    for (int i = from + 1; i < len_array; i++) {
        if (input_array[i] > input_array[from]) {
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

    while (cin >> len_array) {
        memset(cache, -1, sizeof(cache));
        for (int i = 0 ; i < len_array; i++) {
            cin >> input_array[i];
            
        }
        int max_cand = 1;

        for (int i = 0; i < len_array; i++) {
            max_cand = max(max_cand, LIS(i));
            
        }
        cout << max_cand << "\n";

    }
    return 0;
}


