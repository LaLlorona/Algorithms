#include <bits/stdc++.h>


using namespace std;

int n;
const int NEG_INF = -2147483647; 
string expression;
int max_cand = NEG_INF;

int CalculateOneTerm(int a, int b, char oper) {
	if (oper == '+') {
		return a + b;
	}
	else if (oper == '-') {
		return a - b;
	}
	else {
		return a * b;
	}
} 

void CalculateExpression(int index, int middle_result) {
	if (index >= n - 1) {
		max_cand = max(max_cand, middle_result);
	}
	else {
		if (index < n - 2) {
			CalculateExpression(index + 2, CalculateOneTerm(middle_result, expression[index + 2] - '0', expression[index + 1]));
		}
		if (index < n - 4) {
			int value_in_bracket = CalculateOneTerm(expression[index + 2] - '0', expression[index + 4] - '0', expression[index + 3]);
			CalculateExpression(index + 4, CalculateOneTerm(middle_result, value_in_bracket, expression[index + 1]));
		}
	}
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
//     std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//     std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> n) {
		cin >> expression;
		max_cand = NEG_INF;
		CalculateExpression(0, expression[0] - '0');
		cout << max_cand << "\n";
	}
    

    return 0;
}

