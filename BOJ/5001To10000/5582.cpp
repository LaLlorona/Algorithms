#include <bits/stdc++.h>


using namespace std;


int max_common_string[4001][4001];
string a, b;
int len_a, len_b;

int CalcMaxCommonString(int index_a, int index_b) {
	if (index_a >= len_a || index_b >= len_b) {
		return 0;
	}
	else if (a[index_a] != b[index_b]) {
		return 0;
	}
	else { // when both is in the range, and same
		int& ret = max_common_string[index_a][index_b];
		if (ret != -1) {
			return ret;
		}
		else {
			ret = CalcMaxCommonString(index_a + 1, index_b + 1) + 1;
			return ret;
		}
	}
	
}



int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> a >> b) {
		memset(max_common_string, -1, sizeof(max_common_string));
		len_a = a.length();
		len_b = b.length();
		int max_cand = -1;
		for (int i = 0; i < len_a; i++) {
			for (int j = 0; j < len_b; j++) {
				max_cand = max(max_cand, CalcMaxCommonString(i, j));
			}
		}
		cout << max_cand << "\n";
	}
    

    return 0;
}

