#include <bits/stdc++.h>


using namespace std;

unordered_map<string, bool> is_unheard;
int num_is_unheard, num_is_unseen;


int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_is_unheard >> num_is_unseen) {
		is_unheard.clear();
		vector<string> both;
		for (int i = 0; i < num_is_unheard; i++) {
			string unheard;
			cin >> unheard;
			is_unheard[unheard] = true;
		}
		for (int i = 0; i < num_is_unseen; i++) {
			string unseen;
			cin >> unseen;
			if (is_unheard.find(unseen) != is_unheard.end()) {
				both.push_back(unseen);
			}
		}
		sort(both.begin(), both.end());
		cout << both.size() << "\n";
		for (int i = 0; i < both.size(); i++) {
			cout << both[i] << "\n";
		}
		
	}
	
    

    return 0;
}

