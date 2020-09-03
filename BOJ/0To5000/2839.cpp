#include <bits/stdc++.h>


using namespace std;

int n;
const int INF = 987654321;
int min_bag[5001];

int CalcMinBags(int kg) {
	if (kg < 3) {
		return INF;
	}
	else if (kg == 3){
		return 1;
	}
	else if (kg == 5) {
		return 1;
	}
	else {
		int& ret = min_bag[kg];
		if (ret != -1) {
			return ret;
		}
		ret = min(CalcMinBags(kg - 3), CalcMinBags(kg - 5)) + 1;
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
	memset(min_bag, -1, sizeof(min_bag));
	int current_weight;
	while (cin >> current_weight) {
		int result = CalcMinBags(current_weight);
		if (result >= INF) {
			cout << -1 << "\n";
		}
		else {
			cout << result << "\n";
		}
		
	}
    

    return 0;
}

