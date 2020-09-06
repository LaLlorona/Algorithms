#include <bits/stdc++.h>


using namespace std;

int num_song, initial_volume, max_volume;
bool volume_at_ith_song[101][1001]; // if is possible to use volume j in i th song, volume_at_ith_song[i][j] is 1. if not, 0. 
int possible_volume_change_at_ith_song[1001];




int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	while (cin >> num_song >> initial_volume >> max_volume) {
		memset(volume_at_ith_song, 0, sizeof(volume_at_ith_song));
		for (int i = 1; i <= num_song; i++) {
			cin >> possible_volume_change_at_ith_song[i];
		}
		volume_at_ith_song[0][initial_volume] = true;
		
		for (int i = 1; i <= num_song; i++) {
			for (int j = 0; j <= max_volume; j++) {
				if (volume_at_ith_song[i - 1][j] == 1) {
					if (j + possible_volume_change_at_ith_song[i] <= max_volume) {
						volume_at_ith_song[i][j + possible_volume_change_at_ith_song[i]] = true;
					}
					if (j - possible_volume_change_at_ith_song[i] >= 0) {
						volume_at_ith_song[i][j - possible_volume_change_at_ith_song[i]] = true;
					}
				}
			}
		}
		int result = -1;
		for (int i = 0; i <= max_volume; i++) {
			if (volume_at_ith_song[num_song][i]) {
				result = i;
			}
		}
		cout << result << "\n";
	}
    

    return 0;
}

