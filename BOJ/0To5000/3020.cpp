#include <bits/stdc++.h>


using namespace std;
const int MAX = 100001;
int height_total, len_total;
int len_arr;
vector<int> bottom, top;






int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> len_total >> height_total) {
		bottom.clear();
		top.clear();
		len_arr = len_total / 2;
		for (int i = 0; i < len_total; i = i + 2) {
			int a, b;
			cin >> a >> b;
			bottom.push_back(a);
			top.push_back(b);
		}
		sort(bottom.begin(), bottom.end());
		sort(top.begin(), top.end());
		
		int min_cand = 987654321;
		int num_path = 0;
		for (int height = 1; height <= height_total; height++) {
			
			vector<int>::iterator bottom_iter, top_iter;
			bottom_iter = upper_bound(bottom.begin(), bottom.end(), height - 1);
			top_iter = upper_bound(top.begin(), top.end(), height_total - height);
			int num_low = len_arr - (bottom_iter - bottom.begin());
			int num_top = len_arr - (top_iter - top.begin());
			if (min_cand > num_low + num_top) {
				min_cand = num_low + num_top;
				num_path = 0;
			}
			if (min_cand == num_low + num_top) {
				num_path++;
			}
			
		}
		cout << min_cand << " " << num_path << "\n";
	}
	
    

    return 0;
}

