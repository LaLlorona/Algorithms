#include <bits/stdc++.h>


using namespace std;


void PrintArray(int num) {
	if (num % 4 != 0) {
		cout << "NO\n";
		return;
	}
	else{
		cout << "YES\n";
		for (int i = 0; i < num / 2; i++) {
			cout << i * 2 + 2 << " ";
		}
		for (int i = 0; i < num / 2 - 1; i++) {
			cout << i * 2 + 1<< " ";
		}
		cout << (num / 2) * (num / 2 + 1) - (num / 2 - 1) * (num / 2 - 1);
		cout << "\n";
		
	}
}


int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		int num;
		cin >> num;
		PrintArray(num);
	}
    

    return 0;
}

