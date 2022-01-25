
#include <bits/stdc++.h>


using namespace std;
const int MAX = 50;
int cache[MAX];

int fibo(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 1;
    }
    
    if (cache[n] != -1) {
        return cache[n];
    }
    else {
        int& ret = cache[n];
        ret = fibo(n - 1) + fibo(n - 2);
        


        return ret;
    }
}

void PrintAnswer(int n) {
    if (n == 0) {
        cout << 1 << " " << 0 << "\n";
    }
    else if (n == 1) {
        cout << 0 << " " << 1 << "\n";
    }
    else {
        cout << fibo(n -1) << " " << fibo(n) << "\n";
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

    int num_testcase;
    cin >> num_testcase;
    memset(cache, -1, sizeof(cache));
    while (num_testcase--) {
        int num;
        cin >> num;
        PrintAnswer(num);
        
    }
    return 0;
}


