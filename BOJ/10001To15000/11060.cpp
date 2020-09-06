#include <bits/stdc++.h>


using namespace std;

int num_stair;
int jumps[1001];
int min_jump_to[1001];
const int INF = 987654321;



int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
//     std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//     std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	while (cin >> num_stair) {
		for (int i = 0; i < num_stair; i++) {
			cin >> jumps[i];
			min_jump_to[i] = INF;
			
		}
		min_jump_to[0] = 0;
		for (int i = 0; i < num_stair; i++) {
			for (int j = 1; j + i < num_stair && j <= jumps[i]; j++) {
				min_jump_to[i + j] = min(min_jump_to[i + j], 1 + min_jump_to[i]);
			}
		}
		// for (int i = 0; i < num_stair; i++) {
		// 	cout << min_jump_to[i] << " ";
		// }
		// cout << "\n";
		if (min_jump_to[num_stair - 1] == INF) {
			cout << "-1\n";
		}
		else {
			cout << min_jump_to[num_stair - 1] << "\n";
		}
	}
    

    return 0;
}

