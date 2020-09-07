#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
int n;
ll word[46][2];

void FillWord() {
	word[0][0] = 1;
	word[1][0] = 0;
	for (int i = 1; i < 46; i++) {
		word[i][0] = word[i - 1][1];
		word[i][1] = word[i - 1][0] + word[i - 1][1];
	}
}



int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	FillWord();
	while (cin >> n) {
		cout << word[n][0] << " " << word[n][1] << "\n";
	}
    

    return 0;
}

