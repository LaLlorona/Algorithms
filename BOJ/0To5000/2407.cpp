#include <bits/stdc++.h>


using namespace std;

int big_number1[100];
int bin_number2[100];
int binomial_coefficient[101][101][100];

void SumOfBigNumber(int num1[100], int num2[100]) {
	for (int i = 0; i < 99; i++) {
		num1[i] = num1[i] + num2[i];
		num1[i + 1] += num1[i] / 10;
		num1[i] %= 10;
	}
}

void PrintBigNumber(int num[100]) {
	int first_digit_not_zero = 99;
	for (int i = 99; i >= 0; i--) {
		if (num[i] != 0) {
			first_digit_not_zero = i;
			break;
		}
	}
	for (int i = first_digit_not_zero; i >= 0; i--) {
		cout << num[i];
	}
	cout << "\n";
}


int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	for (int i = 0; i <= 100; i++) {
		binomial_coefficient[i][0][0] = 1;
		binomial_coefficient[i][i][0] = 1;
	}
	
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j < i; j++) {
			SumOfBigNumber(binomial_coefficient[i][j], binomial_coefficient[i - 1][j - 1]);
			SumOfBigNumber(binomial_coefficient[i][j], binomial_coefficient[i - 1][j]);
		}
	}
	int N, K;
	while (cin >> N >> K) {
		PrintBigNumber(binomial_coefficient[N][K]);
	}
	
	
	
	


    

    return 0;
}

