#include <bits/stdc++.h>


using namespace std;

const int INF = 987654321;

int floyd[101][101];
bool connected[101][101];
int num_users, num_relations;

void FillFloyd() {
	for (int k = 1; k <= num_users; k++) {
		for (int i = 1; i <= num_users; i++) {
			for (int j = 1; j <= num_users; j++) {
				floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
//     std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//     std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_users >> num_relations) {
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				floyd[i][j] = INF;
			}
		}
		for (int i = 0; i < num_relations; i++) {
			int a, b;
			cin >> a >> b;
			connected[a][b] = true;
			connected[b][a] = true;
			floyd[a][b] = 1;
			floyd[b][a] = 1;
		}
		for (int i = 1; i <= num_users; i++) {
			floyd[i][i] = 0;	
		}
		
		FillFloyd();
		vector<pair<int, int> > kevin_bacon;
		for (int i = 1; i <= num_users; i++) {
			int current_relation = 0;
			for (int j = 1; j <= num_users; j++) {
				current_relation += floyd[i][j];
			}
			kevin_bacon.push_back({current_relation, i});
		}
		// for (int i = 0; i < num_users; i++) {
		// 	cout << kevin_bacon[i].second << " " << kevin_bacon[i].first << "\n";
		// }
		sort(kevin_bacon.begin(), kevin_bacon.end());
		cout << kevin_bacon[0].second << "\n";
		
	}
    

    return 0;
}

