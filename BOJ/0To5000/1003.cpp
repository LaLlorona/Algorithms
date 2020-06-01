#include <bits/stdc++.h>


using namespace std;

int n;
long long fibonacci[100];
long long fibonacci_call_one[41];
long long fibonacci_call_zero[41];



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
	
	
	memset(fibonacci, 0, sizeof(fibonacci));
	memset(fibonacci_call_zero, 0, sizeof(fibonacci_call_zero));
	memset(fibonacci_call_one, 0, sizeof(fibonacci_call_one));
	
	fibonacci[1] = 1;
	fibonacci_call_one[1] = 1;
	fibonacci_call_zero[0] = 1;
	for (int i = 2; i < 41; i++) {
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
		fibonacci_call_zero[i] = fibonacci_call_zero[i - 1] + fibonacci_call_zero[i - 2];
		fibonacci_call_one[i] = fibonacci_call_one[i - 1] + fibonacci_call_one[i - 2];
	}
	while (num_testcase--) {
		cin >> n;
		cout << fibonacci_call_zero[n] << " " << fibonacci_call_one[n] << "\n";
	}
	
	
	
    

    return 0;
}

