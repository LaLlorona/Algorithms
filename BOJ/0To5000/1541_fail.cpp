#include <bits/stdc++.h>


using namespace std;

string expression;
vector<int> operator_index;



int DealingOperater(int a, int b, char oper) {
	if (oper == '+') {
		return a + b;
	}
	else if (oper == '-') {
		return a-b;
	}
	else {
		cout << "error!\n";
		return a - b;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	
	while (cin >> expression) {
		operator_index.clear();
		for (int i = 0; i < expression.length(); i++) {
			if (expression[i] == '+' || expression[i] == '-') {
				operator_index.push_back(i);
			}
		}
		if (operator_index.size() == 0) {
			cout << stoi(expression) << "\n";
			continue;
		}
		
		int result = stoi(expression.substr(0, operator_index[0]));
		//cout << result << "\n";
		int i = 0;
		while (i < operator_index.size()) {
			if (i < operator_index.size() - 1) {
				int pos1 = operator_index[i];
				int pos2 = operator_index[i + 1];
				
				if (expression[pos1] == '-' && expression[pos2] == '+') {
					//cout << "optimization possible\n";
					
					int a = stoi(expression.substr(pos1 + 1, pos2 - pos1 - 1));
					int b = stoi(expression.substr(pos2 + 1, (i + 2 == operator_index.size() ? expression.length() - pos2 - 1 : operator_index[i + 2] - pos2 - 1)));
					//cout << a << "\n";
					//cout << b << "\n";
					result -= a;
					result -= b;
					i = i + 2;
				}
				else {
					//cout << "optimization impossible\n";
					result = DealingOperater(result, stoi(expression.substr(pos1 + 1, pos2 - pos1 - 1)), expression[pos1]);
					i = i + 1;
				}
			}
			else {
				//cout << "reached last\n";
				int pos1 = operator_index[i];
				//cout << "next num is " << stoi(expression.substr(pos1 + 1, expression.length() - pos1)) << "\n";
				result = DealingOperater(result, stoi(expression.substr(pos1 + 1, expression.length() - pos1 - 1)), expression[pos1]);
				i = i + 1;
			}
		}
		cout << result << "\n";
	}
    

    return 0;
}

