#include <bits/stdc++.h>


using namespace std;

int weight[100];
int pleasure[100];
int cache[100001][101];

int n, max_capacity;

int MaxHappy(int left_capacity, int item) {
	if (item == n) {
		return 0;
	}
	int& ret = cache[left_capacity][item];
	
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	if (left_capacity >= weight[item]) {
		ret = max(ret, pleasure[item] + MaxHappy(left_capacity - weight[item], item + 1));
	}
	ret = max(ret, MaxHappy(left_capacity, item + 1));
	return ret;
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
//     std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//     std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	while (cin >> n >> max_capacity) {
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			weight[i] = a;
			pleasure[i] = b;
		}
		cout << MaxHappy(max_capacity, 0) << "\n";
		
	}
	
    

    return 0;
}

