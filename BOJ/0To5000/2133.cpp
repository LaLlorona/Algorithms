#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
int num_fill[31];


int CalcTiles(int n) {
	if (n % 2 == 1) {
		return 0;
	}
	else if (n == 0) {
		return 1;
	}
	else if (n == 2) {
		return 3;
	}
	else {
		int& ret = num_fill[n];
		if (ret != -1) {
			return ret;
		}
		else {
			ret = 0;
			for (int i = 0; i < n - 2; i += 2) {
				ret += CalcTiles(i) * 2;
			}
			ret += CalcTiles(n - 2) * 3;
			return ret;
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
	int num;
	while (cin >> num) {
		memset(num_fill, -1, sizeof(num_fill));
		cout << CalcTiles(num) << "\n";
	}
    

    return 0;
}

