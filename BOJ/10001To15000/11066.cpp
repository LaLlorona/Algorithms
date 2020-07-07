#include <bits/stdc++.h>


using namespace std;

const int INF = 987654321;
int len_arr;
int cache[501][501]; //minimum cost of sum from a to b
int sums[501]; // partial sums. first element is zero
int cost[501];

int MinimumCost(int from, int to) {
	if (from == to) {
		return 0;
	}
	else if (to == from + 1) {
		return cost[from] + cost[to];
	}
	else {
		int& ret = cache[from][to];
		if (ret != -1) {
			return ret;
		}
		else {
			ret = INF;
			for (int mid = from; mid < to; mid++) {
				ret = min(ret, MinimumCost(from, mid) + MinimumCost(mid + 1, to));
			}
			ret += sums[to] - sums[from - 1];
		}
		return ret;
	}
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
//     std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//     std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		memset(cache, -1, sizeof(cache));
		cin >> len_arr;
		for (int i = 1; i <= len_arr; i++) {
			cin >> cost[i];
			sums[i] = sums[i - 1] + cost[i];
		}
		cout << MinimumCost(1, len_arr) << "\n";
	}
    

    return 0;
}

