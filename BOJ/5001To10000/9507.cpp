#include <bits/stdc++.h>


using namespace std;

int big_number1[100];
int bin_number2[100];
int super_finobacci[70][100];

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
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	memset(super_finobacci, 0, sizeof(super_finobacci));
	super_finobacci[0][0] = 1;
	super_finobacci[1][0] = 1;
	
	super_finobacci[2][0] = 2;
	super_finobacci[3][0] = 4;
	
	
	for (int i = 4; i < 70; i++) {
		SumOfBigNumber(super_finobacci[i], super_finobacci[i - 1]);
		SumOfBigNumber(super_finobacci[i], super_finobacci[i - 2]);
		SumOfBigNumber(super_finobacci[i], super_finobacci[i - 3]);
		SumOfBigNumber(super_finobacci[i], super_finobacci[i - 4]);
	}
	
	int num_testcase;
	cin >> num_testcase;
	for (int i = 0; i < num_testcase; i++) {
		int num_fibo;
		cin >> num_fibo;
		PrintBigNumber(super_finobacci[num_fibo]);
		
	}


    

    return 0;
}

