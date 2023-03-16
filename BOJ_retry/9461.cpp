#include <bits/stdc++.h>

using namespace std;


const long long MAX = 102;

long long cache[MAX];

long long N;

int numTestCase;

long long Padoban(long long n) {
    if (n == 1 || n == 2 || n == 3) {
        return 1;
    }

    else if (n == 4 || n == 5) {
        return 2;
    }

    long long& ret = cache[n];

    if (ret != -1) {
        return ret;
    }

    ret = Padoban(n - 1) + Padoban(n - 5);
    return ret;
}

int main()
{
    
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    // std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); 
	// std::cin.rdbuf(in.rdbuf()); 

    memset(cache, -1, sizeof(cache));

    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        cin >> N;
        cout << Padoban(N) << "\n";
    }

}


  