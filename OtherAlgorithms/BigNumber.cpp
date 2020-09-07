#include <bits/stdc++.h>


using namespace std;

const int DIGIT = 2100;



void SumOfBigNumber(int num1[DIGIT], int num2[DIGIT]) {
	for (int i = 0; i < DIGIT - 1; i++) {
		num1[i] = num1[i] + num2[i];
		num1[i + 1] += num1[i] / 10;
		num1[i] %= 10;
	}
}

void PrintBigNumber(int num[DIGIT]) {
	int first_digit_not_zero = DIGIT - 1;
	for (int i = DIGIT - 1; i >= 0; i--) {
		if (num[i] != 0) {
			first_digit_not_zero = i;
			break;
		}
		if (i == 0 && num[i] == 0) {
			cout << 0 << "\n";
			return;
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
	
    

    return 0;
}

