#include <bits/stdc++.h>


using namespace std;

int n;
long long fibonacci[100];


int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	memset(fibonacci, 0, sizeof(fibonacci));
	fibonacci[1] = 1;
	for (int i = 2; i < 100; i++) {
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}
	cin >> n;
	cout << fibonacci[n] << "\n";
	
	
    

    return 0;
}

