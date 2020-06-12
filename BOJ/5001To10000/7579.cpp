#include <bits/stdc++.h>


using namespace std;

int num_apps, target_memory;
int memory[100];
int cost[100];
int cache[100][10001];


int MaxMemory(int index, int left_cost) {
	if (index >= num_apps) {
		return 0;
	}
	int& ret = cache[index][left_cost];
	if (ret != -1) {
		return ret;
	}
	ret = MaxMemory(index + 1, left_cost);
	if (left_cost >= cost[index]) {
		ret = max(ret, memory[index] + MaxMemory(index + 1, left_cost - cost[index]));
	}
	return ret;
	
}


int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
// 	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
// 	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_apps >> target_memory) {
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < num_apps; i++) {
			cin >> memory[i];
		}
		for (int i = 0; i < num_apps; i++) {
			cin >> cost[i];
		}
		int possible_cost = 0;
		while (true) {
			if (MaxMemory(0, possible_cost) >= target_memory) {
				cout << possible_cost << "\n";
				break;
			}
			possible_cost++;
		}
		
		
	}
    

    return 0;
}

