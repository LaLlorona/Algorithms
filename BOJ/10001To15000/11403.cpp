#include <bits/stdc++.h>


using namespace std;

int num_vertice;
bool has_route[100][100]; // is it is possible to reach from one to another


void FloydWarshall() {
	for (int k = 0; k < num_vertice; k++) {
		for (int i = 0; i < num_vertice; i++) {
			for (int j = 0; j < num_vertice; j++) {
				has_route[i][j] |= (has_route[i][k] & has_route[k][j]);
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
	
	while (cin >> num_vertice) {
		memset(has_route, 0, sizeof(has_route));
		for (int y = 0; y < num_vertice; y++) {
			for (int x = 0; x < num_vertice; x++) {
				if (y == x) {
					has_route[y][x] = true;
				}
				cin >> has_route[y][x];
			}
		}
		FloydWarshall();
		for (int y = 0; y < num_vertice; y++) {
			for (int x = 0; x < num_vertice; x++) {
				cout << has_route[y][x];
				if (x != num_vertice - 1) {
					cout << " ";
				}
			}
			cout << "\n";
		}
		
	}
    

    return 0;
}

