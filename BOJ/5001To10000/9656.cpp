#include <bits/stdc++.h>


using namespace std;

int n;



int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> n) {
		if (n % 4 == 2 || n % 4 == 0) {
			cout << "SK\n";
		}
		else {
			cout << "CY\n";
		}
	}
    

    return 0;
}

