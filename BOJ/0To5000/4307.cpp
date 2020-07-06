#include <bits/stdc++.h>


using namespace std;

const int INF = 987654321;



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		int max_cand = 0;
		int min_cand = 0;
		int len_lod;
		int num_ant;
		int ant_position;
		cin >> len_lod >> num_ant;
		for (int i = 0; i < num_ant; i++) {
			cin >> ant_position;
			max_cand = max(max_cand, max(len_lod - ant_position, ant_position));
			min_cand = max(min_cand, min(len_lod - ant_position, ant_position));
		}
		cout << min_cand << " " << max_cand << "\n";
	}
    

    return 0;
}

