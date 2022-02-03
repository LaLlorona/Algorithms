#include <bits/stdc++.h>


using namespace std;
const int MAX = 1001;
const int INF = 987654321;
int len_array;
int input_array[MAX];
int cache[MAX][MAX];
int cache_LDS[MAX][MAX];

int LIS(int from, int to) {
    if (from == to) {
        return 1;
    }
    int& ret = cache[from][to];

    if (ret != -1) {
        return ret;
    }

    int max_cand = 1;

    for (int i = from + 1; i <= to; i++) {
        if (input_array[i] > input_array[from]) {
            max_cand = max(max_cand, LIS(i, to) + 1);
        }
    }
    ret = max_cand;
    return ret;
}

int LDS(int from, int to) {
    if (from == to) {
        return 1;
    }
    int& ret = cache_LDS[from][to];

    if (ret != -1) {
        return ret;
    }

    int max_cand = 1;

    for (int i = from + 1; i <= to; i++) {
        if (input_array[i] < input_array[from]) {
            max_cand = max(max_cand, LDS(i, to) + 1);
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
        memset(cache_LDS, -1, sizeof(cache_LDS));
        for (int i = 0 ; i < len_array; i++) {
            cin >> input_array[i];
            
        }
        int max_cand = 1;

        

        for (int i = 0; i < len_array; i++) {
            for (int j = i; j < len_array; j++) {
                max_cand = max(max_cand, LIS(i, j) + LDS(j, len_array - 1) - 1);
            }
            
            
            
        }
        cout << max_cand << "\n";

    }
    return 0;
}