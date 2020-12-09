#include <bits/stdc++.h>


using namespace std;

unordered_map<int, bool> is_seen;


int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		is_seen.clear();
		int num_diary1;
		int num_diary2;
		cin >> num_diary1;
		for (int i = 0; i < num_diary1; i++) {
			int num;
			cin >> num;
			is_seen[num] = true;
		}
		cin >> num_diary2;
		for (int i = 0; i < num_diary2; i++) {
			int num;
			cin >> num;
			if (is_seen.find(num) != is_seen.end()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		
	}
    

    return 0;
}

