#include <bits/stdc++.h>


using namespace std;

const int MAX = 100001;

int len_arr;
int port_from_to[MAX];

int LIS() {
	vector<int> lis;
	for (int i = 0; i < len_arr; i++) {
		if (i == 0 || port_from_to[i] > lis[lis.size() - 1]) {
			lis.push_back(port_from_to[i]);
		}
		else {
			vector<int>::iterator iter = lower_bound(lis.begin(), lis.end(), port_from_to[i]);
			*iter = port_from_to[i];
		}
	}
	return lis.size();
}
int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> len_arr) {
		for (int i = 0; i < len_arr; i++) {
			cin >> port_from_to[i];
		}
		cout << len_arr - LIS() << "\n";
	}
	
    

    return 0;
}