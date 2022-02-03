
#include <bits/stdc++.h>


using namespace std;
const int MAX = 55;
int cache[MAX][MAX][MAX];
int a, b, c;

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    else if (a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20);
    }

    int& ret = cache[a][b][c];

    if (ret != -1) {
        return ret;
    }

    if (a < b && b < c) {
        ret = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
        return ret;
        
    }
    else {
        ret =  w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
        return ret;
    }
}





int main()
{
    std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
    std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
    // std::ifstream in("in.txt");
    // std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    // std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

   

    memset(cache, -1, sizeof(cache));
    int x, y, z;

    while (cin >> x >> y >> z) {
        if (x == -1 && y == -1 && z == -1) {
           
            break;
        }
        cout << "w(" << x << ", " << y << ", " <<z<<") = " << w(x, y, z) << "\n"; 
    }

    
    return 0;
}


