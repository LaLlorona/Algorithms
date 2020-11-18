#include <bits/stdc++.h>


using namespace std;

int is_palindrome[1001][1001];
string input;
int len_input;

int IsPalindrome(int from, int to) {
	if (from == to) {
		return 1;
	}
	else if (to == from + 1) {
		if (input[from] == input[to]) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int& ret = is_palindrome[from][to];
	if (ret != -1) {
		return ret;
	}
	if (input[from] == input[to] && IsPalindrome(from + 1, to - 1)) {
		return ret = 1;
	}
	else {
		return ret = 0;
	}	
}

string FindLongestPalindrome(string s) {
	input = s;
	len_input = s.length();
	memset(is_palindrome, -1, sizeof(is_palindrome));
	int max_length = -1;
	int from_max, to_max;
	for (int i = 0; i < len_input; i++) {
		for (int j = i; j < len_input; j++) {
			if (IsPalindrome(i, j) && (j - i + 1 > max_length)) {
				max_length = j - i + 1;
				from_max = i;
				to_max = j;
			} 
		}
	}
	return s.substr(from_max, max_length);
	
}


int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> input) {
		cout << FindLongestPalindrome(input) << "\n";
	}
	
	
    

    return 0;
}

