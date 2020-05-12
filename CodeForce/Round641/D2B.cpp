#include <bits/stdc++.h>


using namespace std;
int num_models;
int model_size[100001];
int max_buy_from[100001];


int UpdateMaxBuyFrom(int from) {
	if (from > num_models) {
		return 0;
	}
	int& ret = max_buy_from[from];
	
	if (ret != -1) {
		return ret;
	}
	ret = 1;
	
	int next = from * 2;
	while (next <= num_models) {
		if (model_size[next] > model_size[from]) {
			ret = max(ret, 1 + UpdateMaxBuyFrom(next));
		}
		next += from;
	}
	return ret;
}


int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	cin >> num_testcase;
	while (num_testcase--) {
		cin >> num_models;
		for (int i = 0; i < 100001; i++) {
			max_buy_from[i] = -1;
		}
		for (int i = 1 ; i <= num_models; i++) {
			cin >> model_size[i];
		}
		for (int i = 1; i <= num_models; i++) {
			UpdateMaxBuyFrom(i);
		}
		
		int max_cand = 0;
		for (int i = 1; i <= num_models; i++) {
			// cout << max_buy_from[i] << " ";
			max_cand = max(max_cand, max_buy_from[i]);
		}
		// cout << "\n";
		cout << max_cand << "\n";
		
		
	}
    

    return 0;
}

