#include <bits/stdc++.h>


using namespace std;

const int MAX = 51;
int a, b, c;
int cache[MAX][MAX][MAX];

int usingCache(int a, int b, int c) {

	
	
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}

	int& result = cache[a][b][c];
	if (result != -1) {
		return result;
	}

	if (a > 20 || b > 20 || c > 20) {
		result = usingCache(20, 20, 20);
		return result;
	}

	else if ((a < b) && (b < c)) {
		result = usingCache(a, b, c - 1) + usingCache(a, b - 1, c - 1) - usingCache(a, b - 1, c);
		return result;
	}
	else {
		result = usingCache(a - 1, b, c) + usingCache(a - 1, b - 1, c) + usingCache(a - 1, b, c - 1) - usingCache(a - 1, b - 1, c - 1);
		return result;
	}

}



int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	 //std::ifstream in("input.txt");
	 //std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	 //std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	 memset(cache, -1, sizeof(cache));
	 while (cin >> a >> b >> c) {
		 
		 if (a == -1 && b == -1 && c == -1) {
			 break;
		 }
		 else {
			 cout << "w(" << a << ", " << b << ", " << c << ") = " << usingCache(a, b, c) << "\n";

		 }
	 }
	 


	return 0;
}

