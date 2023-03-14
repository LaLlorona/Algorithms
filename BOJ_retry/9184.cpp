#include <bits/stdc++.h>

using namespace std;

const int MAX = 51;
int cache[MAX][MAX][MAX];

int Calc(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }

    else if (a > 20 || b > 20 || c > 20) {
        return Calc(20, 20, 20);
    }

    int& ret = cache[a][b][c];

    if (ret != -1) {
        return cache[a][b][c];
    }

    if (a < b && b < c) {
        ret = Calc(a, b, c-1) + Calc(a, b-1, c-1) - Calc(a, b-1 ,c);
    }

    else {
        ret = Calc(a -1, b, c) + Calc(a - 1, b - 1, c) +  Calc(a-1, b, c-1) - Calc(a-1, b-1, c-1);
    }
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

    int a, b ,c;

    while (cin >> a >> b >> c) {
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        else {
            cout << "w(" << a << ", " << b << ", " << c << ") = " << Calc(a, b, c) << "\n";
            
        }
    }

    
   
}

