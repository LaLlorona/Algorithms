#include <bits/stdc++.h>


using namespace std;

const int MAX = 2500 + 2;
const int INF = 987654321;
int is_palindrome[MAX][MAX];
int max_palindrome_division[MAX];
string input_str;

int CalcIsPalindrome(int from, int to) {
	
	if (from >= to) {
		return 1;
	}
	int& ret = is_palindrome[from][to];
	if (ret != -1) {
		return ret;
	}
	if (input_str[from] == input_str[to]) {
		return ret = CalcIsPalindrome(from + 1, to - 1);
	}
	else {
		return ret = 0;
	}
}

void FillMaxPalindromeDivision() {
	max_palindrome_division[0] = 0;
	for (int to = 1; to <= input_str.length(); to++) {
		max_palindrome_division[to] = INF;
		for (int from = to; from >= 1; from--) {
			if (CalcIsPalindrome(from, to) == 1) {
				max_palindrome_division[to] = min(max_palindrome_division[to], max_palindrome_division[from - 1] + 1);
			}
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
	
	while (cin >> input_str) {
		input_str.insert(0, " ");
		memset(is_palindrome, -1, sizeof(is_palindrome));
		FillMaxPalindromeDivision();
		cout << max_palindrome_division[input_str.length() - 1] << "\n";
		//for (int i = 1; i )
	}
    

    return 0;
}

