#include <bits/stdc++.h>


using namespace std;

int nth_day, nth_day_rice_cake;
int fibo[31];

void FillFibo() {
	fibo[0] = 0;
	fibo[1] = 1;
	fibo[2] = 1;
	for (int i = 3; i < 31; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
}
void CalcFirstSecondDay(int day, int today_rice_cake) {
	int coefficient_first = fibo[day - 2];
	int coefficient_second = fibo[day - 1];
	for (int i = 1; i <= today_rice_cake; i++) {
		int left = today_rice_cake - coefficient_first * i;
		if (left % coefficient_second == 0 && left / coefficient_second > 0) {
			cout << i << "\n" << left / coefficient_second << "\n";
			break;
		}
	}
}


int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	FillFibo();
	while (cin >> nth_day >> nth_day_rice_cake) {
		CalcFirstSecondDay(nth_day, nth_day_rice_cake);
	}
    

    return 0;
}

