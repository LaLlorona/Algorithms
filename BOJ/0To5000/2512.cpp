#include <bits/stdc++.h>


using namespace std;

int require[10001];
int num_require;
int budget; 
int max_budget = 0;

bool IsPossibleWithinBound(int bound) {
	int money_need = 0;
	for (int i = 0; i < num_require; i++) {
		money_need += min(require[i], bound);
	}
	return (money_need <= budget);
}

int BinarySearch() {
	int hi = max_budget;
	int lo = 0;
	int max_bound = 0;
	while (lo <= hi) {
		int mid = (hi + lo) / 2;
		//cout << lo << " " << hi << "\n";
		if (IsPossibleWithinBound(mid)) {
			max_bound = max(max_bound, mid);
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	return max_bound;
}


int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_require) {
		for (int i = 0; i < num_require; i++) {
			cin >> require[i];
			max_budget = max(max_budget, require[i]);
		}
		cin >> budget;
		cout << BinarySearch() << "\n";
	}
	
    

    return 0;
}