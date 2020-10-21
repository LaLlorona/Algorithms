#include <bits/stdc++.h>


using namespace std;

const int MAX = 401;
int num_incident, num_relation;
bool connected[MAX][MAX];

void FillConnected() {
	for (int k = 1; k <= num_incident; k++) {
		for (int i = 1; i <= num_incident; i++) {
			for (int j = 1; j <= num_incident; j++) {
				connected[i][j] |= (connected[i][k] & connected[k][j]);
			}
		}
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
	
	while (cin >> num_incident >> num_relation) {
		for (int i = 0; i < num_relation; i++) {
			int incident1, incident2;
			cin >> incident1 >> incident2;
			connected[incident1][incident2] = true;
		}
		FillConnected();
		int num_verify;
		cin >> num_verify;
		for (int i = 0; i < num_verify; i++) {
			int incident1, incident2;
			cin >> incident1 >> incident2;
			if (connected[incident1][incident2]) {
				cout << "-1\n";
			}
			else if (connected[incident2][incident1]) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
	}
	
	
    

    return 0;
}

