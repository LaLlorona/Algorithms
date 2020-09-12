#include <bits/stdc++.h>


using namespace std;


const int MAX = 100001;

const int INF = 987654321;
int result = -INF;
int num_input;
int consecutive_sum[MAX][2];
int input_arr[MAX];

void FillConsecutiveSum() {
	consecutive_sum[0][0] = - INF;
	consecutive_sum[0][1] = -INF;
	for (int i = 1; i <= num_input; i++) {
		consecutive_sum[i][0] = max(consecutive_sum[i - 1][0] + input_arr[i], input_arr[i]);
		consecutive_sum[i][1] = max(consecutive_sum[i - 1][0], consecutive_sum[i - 1][1] + input_arr[i]);
		result = max(result, consecutive_sum[i][0]);
		result = max(result, consecutive_sum[i][1]);
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
	
	while (cin >> num_input) {
		result = -INF;
		for (int i = 1; i <= num_input; i++) {
			cin >> input_arr[i];
		}
		FillConsecutiveSum();
		cout << result << "\n";
		
	}
    

    return 0;
}

