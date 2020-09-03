#include <bits/stdc++.h>


using namespace std;

int n;
long long fibonacci[21];


int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	fibonacci[0] = 0;
	fibonacci[1] = 1;
	for (int i = 2; i < 21; i++) {
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}
	int num;
	cin >> num;
	cout << fibonacci[num] << "\n";
    

    return 0;
}

