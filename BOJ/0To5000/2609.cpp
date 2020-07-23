#include <bits/stdc++.h>


using namespace std;

int n, m;


int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}
int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	while (cin >> n >> m) {
		if (m > n) {
			swap(m, n);
		}
		cout << gcd(n, m) << "\n" << lcm(n, m) << "\n";
	}
	
	
    

    return 0;
}

