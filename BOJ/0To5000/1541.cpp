#include <bits/stdc++.h>


using namespace std;





int result = 0;
bool is_minus_appeared = false;
string temp = "";
string expression;

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
//     std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//     std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	while (cin >> expression) {
		result = 0;
		is_minus_appeared = false;
		temp = "";
		for (int i = 0; i <= expression.length(); i++) {
			if (expression[i] == '-' || expression[i] == '+' || expression[i] == '\0') {
				if (is_minus_appeared) {
					result -= stoi(temp);
				}
				else {
					result += stoi(temp);
				}
				temp = "";
				if (expression[i] == '-') {
					//cout << "asdfasdfas\n";
					is_minus_appeared = true;
				}
				
				continue;
			}
			temp += expression[i];
		}
		cout << result << "\n";
	}
    

    return 0;
}

