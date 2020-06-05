#include <bits/stdc++.h>


using namespace std;

long long input_a, input_b, input_c;

long long power(long long a, long long b, long long c) {
	if (b == 1) {
		return a % c;
	}
	else if (b % 2 == 0) {
		long long mid = power(a, b / 2, c);
		return (mid * mid) % c;
	}
	else {
		return (a * power(a, b - 1, c)) % c;
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

	while (cin >> input_a >> input_b >> input_c) {
		cout << power(input_a, input_b, input_c) << "\n";
	}
    

    return 0;
}

