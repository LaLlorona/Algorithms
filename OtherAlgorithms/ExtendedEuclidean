#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

void ExtendedEuclidianAlgorithm(int r1, int r2, int s1 = 1, int s2 = 0, int t1 = 0, int t2 = 1) {
    if (r2 == 0) {
        cout << "a and b is " << s1 << " , " << t1;
    }
    else {
        int r = r1 % r2;
        int q = r1 / r2;
        int s = s1 - s2 * q;
        int t = t1 - t2 * q;
        ExtendedEuclidianAlgorithm(r2, r, s2, s, t2, t);
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    ExtendedEuclidianAlgorithm(161 , 28);

    return 0;
}
