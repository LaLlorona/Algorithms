#include <bits/stdc++.h>


using namespace std;
const int MAX = 1000000 + 1;
int n;
int input_arr[MAX];
int cache[MAX];
pair<int, int> ans[MAX];
stack<int> s;

int LIS() {
	int cnt = 0;
	cache[0] = input_arr[0];
	ans[0] = {0, input_arr[0]};
	
	for (int i = 1; i < n; i++) {
		if (cache[cnt] < input_arr[i]) {
			cnt++;
			cache[cnt] = input_arr[i];
			ans[i] = {cnt, input_arr[i]};
		}
		else {
			int pos = lower_bound(cache, cache + cnt, input_arr[i]) - cache;
			cache[pos] = input_arr[i];
			ans[i] = {pos, input_arr[i]};
		}
	}
	return cnt + 1;
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> input_arr[i];
		}
		int result =  LIS();
		cout << result << "\n";
		int num = result - 1;
		for (int i = n - 1; i >= 0; i--) {
			if (ans[i].first == num) {
				s.push(ans[i].second);
				num--;
			}
		}
		while (!s.empty()) {
			cout << s.top() << " ";
			s.pop();
		}
		cout << "\n";
	
	}
    

    return 0;
}

