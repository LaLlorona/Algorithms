#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
int n;
const ll MOD = 1000000007LL;
ll possible_building_comb[101][101][101];

ll BuildingComb(int buildings, int left, int right) {
	if (right == 0 || left == 0 || buildings == 0) {
		return 0;
	}
	if (buildings == 1 && left == 1 && right == 1) {
		return 1;
	}
	else {
		ll& ret = possible_building_comb[buildings][left][right];
		if (ret != -1) {
			return ret;
		}
		else {
			ret = (BuildingComb(buildings - 1, left - 1, right) + BuildingComb(buildings - 1, left, right - 1) + (buildings - 2) * BuildingComb(buildings - 1, left, right)) % MOD;
			return ret;
		}
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
	int total_building, seen_left, seen_right;
	while (cin >> total_building >> seen_left >> seen_right) {
		memset(possible_building_comb, -1, sizeof(possible_building_comb));
		cout << BuildingComb(total_building, seen_left, seen_right) << "\n";
	}
    

    return 0;
}

