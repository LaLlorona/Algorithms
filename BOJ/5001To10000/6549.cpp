#include <bits/stdc++.h>


using namespace std;


const int INF = 2000000000;
long long n;
long long histogram[100000];

long long MaxArea(long long left, long long right) {
	long long max_cand = 0;
	if (right - left + 1 <= 3) {
		for (long long i = left; i <= right; i++) {
			long long min_height = INF;
			for (long long j = i; j <= right; j++) {
				min_height = min(min_height, histogram[j]);
				max_cand = max(max_cand, min_height * (j - i + 1));
			}
		}
		return max_cand;
	}
	else {
		long long mid = (left + right) / 2;
		max_cand = max(MaxArea(left, mid - 1), MaxArea(mid, right));
		long long lo = mid - 1;
		long long hi = mid;
		long long current_height = min(histogram[lo], histogram[hi]);
		long long mid_area = current_height * 2;
		while (lo > left || hi < right) {
			if (lo == left) {
				hi++;
				current_height = min(current_height, histogram[hi]);
			}
			else if (hi == right) {
				lo--;
				current_height = min(current_height, histogram[lo]);
			}
			else if (histogram[hi + 1] >= histogram[lo - 1]) {
				hi++;
				current_height = min(current_height, histogram[hi]);
			}
			else {
				lo--;
				current_height = min(current_height, histogram[lo]);
			}
			mid_area = max(mid_area, current_height * (hi - lo + 1));
		}
		return max(mid_area, max_cand);
	}
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
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			cin >> histogram[i];
		}
		cout << MaxArea(0, n - 1) << "\n";
	}
    

    return 0;
}

