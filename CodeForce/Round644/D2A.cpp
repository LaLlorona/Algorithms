#include <bits/stdc++.h>


using namespace std;

int n;



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
		int a, b;
		cin >> a >> b;
		int c = max(max(a,b), 2 * min(a, b));
		
		cout <<  c * c<< "\n";
	}
    

    return 0;
}

