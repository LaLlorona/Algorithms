#include <bits/stdc++.h>


using namespace std;

string string_a, string_b;
int len_a, len_b;
int cache[1001][1001];

int LCS(int index_a, int index_b) {
	if (index_a >= len_a) {
		return 0;
	}
	
	int& ret = cache[index_a][index_b];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	int matched = -1;
	for (int i = index_b; i < len_b; i++) {
		if (string_a[index_a] == string_b[i]) {
			matched = i;
			break;
		}
	}
	if (matched == -1) {
		ret = max(ret, LCS(index_a + 1, index_b) );
		return ret;
	}
	ret = max(LCS(index_a + 1, matched + 1) + 1, LCS(index_a + 1, index_b));
	return ret;
	
	
}

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> string_a >> string_b) {
		len_a = string_a.length();
		len_b = string_b.length();
		memset(cache, -1, sizeof(cache));
		cout << LCS(0, 0) << "\n";
		
	}
    

    return 0;
}

