#include <bits/stdc++.h>

using namespace std;


const int MAX = 41;

int cache[MAX];

int n;


int CalcFiboNumber(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }

    int& ret = cache[n];

    if (ret != -1) {
        return ret;
    }

    return ret = CalcFiboNumber(n - 1) + CalcFiboNumber(n - 2);
}

int FastCalcFiboNumber(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }

    else {
        return n - 2;
    }
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

    cin >> n;

    cout << CalcFiboNumber(n) << " " << FastCalcFiboNumber(n);



    
   
}

