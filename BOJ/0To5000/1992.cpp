#include <bits/stdc++.h>


using namespace std;

int n;
char quad_tree[64][64];


string QuadTree(int size, int y, int x) {
	bool same = true;
	string result = "";
	for (int current_y = y; current_y < y + size; current_y++) {
		for (int current_x = x; current_x < x + size; current_x++) {
			if (quad_tree[y][x] != quad_tree[current_y][current_x]) {
				same = false;
			}
		}
	}
	if (same) {
		result += string(1, quad_tree[y][x]);
		return result;
	}
	else {
		result += "(";
		result += QuadTree(size / 2, y, x);
		result += QuadTree(size / 2, y, x + size / 2);
		result += QuadTree(size / 2, y + size / 2, x);
		result += QuadTree(size / 2, y + size / 2, x + size / 2);
		result += ")";
		return result;
	}
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	while (cin >> n) {
		memset(quad_tree, 0, sizeof(quad_tree));
		for (int y = 0; y < n; y++) {
			string one_line;
			cin >> one_line;
			for (int x = 0; x < n; x++) {
				quad_tree[y][x] = one_line[x];
			}
		}
		string ans = QuadTree(n, 0, 0);
		cout << ans << "\n";
		
	}
    

    return 0;
}

