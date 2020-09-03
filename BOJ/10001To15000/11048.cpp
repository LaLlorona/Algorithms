#include <bits/stdc++.h>


using namespace std;

const int MAX = 1000;
const int INF = 987654321;
int maze[MAX][MAX];
int max_until[MAX][MAX];
int height, width;

bool IsInBound(int y,int x) {
	return (y >= 0 && y < height && x >= 0 && x < width);
}
int CalcMaxCandyUntil(int y, int x) {
	int& ret = max_until[y][x];
	if (ret != -1) {
		return ret;
	}
	else {
		ret = 0;
		if (IsInBound(y - 1, x)) {
			ret = max(ret, CalcMaxCandyUntil(y - 1, x));
		}
		if (IsInBound(y, x - 1)) {
			ret = max(ret, CalcMaxCandyUntil(y, x - 1));
		}
		ret += maze[y][x];
		return ret;
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
	while (cin >> height >> width) {
		memset(max_until, -1, sizeof(max_until));
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				cin >> maze[y][x];
			}
		}
		cout << CalcMaxCandyUntil(height - 1, width - 1) << "\n";
	}
    

    return 0;
}

