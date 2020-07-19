#include <bits/stdc++.h>


using namespace std;

int n;



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int n;
	
	while (cin >> n) {
		
		int num;
	
		vector<int> divisors;
		for (int i = 0; i < n; i++) {
			cin >> num;
			divisors.push_back(num);
		}
		
		sort(divisors.begin(), divisors.end());
		cout << divisors[0] * divisors[divisors.size() - 1] << "\n";
		
		
	}
    

    return 0;
}

