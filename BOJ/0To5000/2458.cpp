#include <bits/stdc++.h>


using namespace std;

const int MAX = 501;
bool connected[MAX][MAX]; // connected[a][b] is true when there is path from a to b
int bigger_than[MAX];
int smaller_than[MAX];
int num_students, num_relations;

void FloydWalshall() {
	for (int k = 1; k <= num_students; k++) {
		for (int i = 1; i <= num_students; i++) {
			for (int j = 0; j <= num_students; j++) {
				connected[i][j] = connected[i][j] | (connected[i][k] & connected[k][j]);
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
// 	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
// 	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    while (cin >> num_students >> num_relations) {
		for (int i = 0; i < num_relations; i++) {
			int from, to;
			cin >> from >> to;
			connected[from][to] = true;
		}
		
		FloydWalshall();
		
		// for (int i = 1; i <= num_students; i++) {
		// 	for (int j = 1; j <= num_students; j++) {
		// 		cout << connected[i][j] << " ";
		// 	}
		// 	cout << "\n";
		// }
		
		for (int i = 1; i <= num_students; i++) {
			for (int j = 1; j <= num_students; j++) {
				if (i != j) {
					if (connected[i][j]) {
						smaller_than[i]++;
						bigger_than[j]++;
					}
				}
			}
		}
		int result = 0;
		for (int i = 1; i <= num_students; i++) {
			//cout << i << " " << smaller_than[i] << " " << bigger_than[i] << "\n";
			if (smaller_than[i] + bigger_than[i] + 1 == num_students) {
				//cout << i << "\n";
				result++;
			}
		}
		cout << result << "\n";
		
	}

    return 0;
}

