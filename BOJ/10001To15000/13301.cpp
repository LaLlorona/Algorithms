#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

ll fibo[82];




int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	fibo[0] = 0;
	fibo[1] = 1;
	fibo[2] = 1;
	for (int i = 3; i < 82; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	ll num;
	while (cin >> num) {
		if (num == 1) {
			cout << 4 << "\n";
		}	
		else {
			cout << 2 * (fibo[num] + fibo[num + 1]) << "\n";
		}
	}

    return 0;
}

