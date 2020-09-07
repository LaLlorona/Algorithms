#include <bits/stdc++.h>


using namespace std;

int n;
int occupation[3];

int possible_to_fill[301];

int IsItPossibleToFill(int n) {
	if (n == 0) {
		return 1;
	}
	else if (n < 0) {
		return 0;
	}
	else {
		int& ret = possible_to_fill[n];
		if (ret != -1) {
			return ret;
		}
		ret = 0;
		for (int i = 0; i < 3; i++) {
			ret = ret || IsItPossibleToFill(n - occupation[i]);
		}
		return ret;
		
	}
	
}



int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
//     std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//     std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	int a, b, c, target;
	
	while (cin >> a >> b >> c >> target) {
		memset(possible_to_fill, -1, sizeof(possible_to_fill));
		occupation[0] = a;
		occupation[1] = b;
		occupation[2] = c;
		
		cout << IsItPossibleToFill(target) << "\n";
		// for (int i = 0; i <= target; i++) {
		// 	cout << i << " " << IsItPossibleToFill(i) << "\n";
		// }
		
		
	}
	
  

    return 0;
}

