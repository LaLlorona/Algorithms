#include <bits/stdc++.h>


using namespace std;

int n;

int FindX(int num) {
	for (int i = 2; i < 32; i++) {
		if (num % ((int)pow(2, i) - 1) == 0) {
			return num / (pow(2, i) - 1);
		}
	}
	return num;
}

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		int num;
		cin >> num;
		cout << FindX(num) << "\n";
	}
    

    return 0;
}

