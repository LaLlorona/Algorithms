#include <bits/stdc++.h>


using namespace std;

int num_boxes;
int len_LIS[1001];
int input_sequence[1001];


int CalcLenLIS(int from) {
	int& ret = len_LIS[from];
	if (ret != -1) {
		return ret;
	}
	ret = 1;
	for (int i = from + 1; i < num_boxes; i++) {
		if (input_sequence[i] > input_sequence[from]) {
			ret = max(CalcLenLIS(i) + 1, ret);
		}
	}
	return ret;
}


int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	while (cin >> num_boxes) {
		memset(len_LIS, -1, sizeof(len_LIS));
		for (int i = 0; i < num_boxes; i++) {
			cin >> input_sequence[i];
		}
		int max_cand = 0;
		for (int i = 0; i < num_boxes; i++) {
			max_cand = max(max_cand, CalcLenLIS(i));
		}
		cout << max_cand << "\n";
		
	}
    

    return 0;
}

