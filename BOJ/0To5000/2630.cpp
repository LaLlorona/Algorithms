#include <bits/stdc++.h>


using namespace std;

int n;
int paper[128][128];
int num_papers[2] = {0, 0};

void CountPaper(int size, int y, int x) {
	bool same = true;
	for (int current_y = y; current_y < y + size; current_y++) {
		for (int current_x = x; current_x < x + size; current_x++) {
			if (paper[y][x] != paper[current_y][current_x]) {
				same = false;
			}
		}
	}
	if (same) {
		num_papers[paper[y][x]]++;
	}
	else {
		CountPaper(size / 2, y, x);
		CountPaper(size / 2, y + size / 2, x);
		CountPaper(size / 2, y, x + size / 2);
		CountPaper(size / 2, y + size / 2, x + size / 2);
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
		memset(num_papers, 0, sizeof(num_papers));
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cin >> paper[y][x];
			}
		}
		CountPaper(n, 0, 0);
		cout << num_papers[0] << "\n" << num_papers[1] << "\n";
	
	}
    

    return 0;
}

