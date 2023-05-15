#include <bits/stdc++.h>

using namespace std;

bool solution(int a, int b, int c, int d, int e, int f)
{
	int leftRed = a - d < 0? a - d : (a -d)/ 2;
	int leftBlue = b - e < 0? b - e : (b - e) / 2;
	int leftGreen = c - f < 0? c - f: (c - f) / 2;

	return (leftRed + leftBlue + leftGreen ) >= 0;
}

	

  

int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    cout << solution( 4, 4, 0, 2, 1, 2) << "\n";

	cout << solution( 3, 3, 3, 2, 2, 2) << "\n";

	cout << solution( 2, 2, 1, 1, 1, 2) << "\n";


}


  