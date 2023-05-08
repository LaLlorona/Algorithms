#include <bits/stdc++.h>

using namespace std;


string MakeRotateString(string str, int beginIndex) {
	int length = str.length();
	return str.substr(beginIndex, length - beginIndex) + str.substr(0, beginIndex);
}

bool CheckValidity(string str) {
	stack<char> bracketStack1;
	
	for (int i = 0 ; i < str.length(); i++) {
		if (str[i] == '[' || str[i] == '(' || str[i] == '{') {
			bracketStack1.push(str[i]);
		}
		
		else  {
			if (bracketStack1.empty()) {
				return false;
			}
			else if (bracketStack1.top() == '[') {
				if (str[i] != ']') {
					return false;
				}
			}
			else if (bracketStack1.top() == '(') {
				if (str[i] != ')') {
					return false;
				}
			}
			else if (bracketStack1.top() == '{') {
				if (str[i] != '}') {
					return false;
				}
			}
			else {
				return false;
			}
			bracketStack1.pop();
		}
		
	}

	return bracketStack1.empty();
}



int solution(string s) {
    int count = 0;
	for (int i = 0; i < s.length(); i++) {
		if (CheckValidity(MakeRotateString(s, i))) {
			count += 1;
		}
	}
	return count;
}

int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(in.rdbuf()); 

	cout << solution ("([{)}]") << "\n";

	cout << solution ("[](){}") << "\n";

	cout << solution ("{{") << "\n";

}


  