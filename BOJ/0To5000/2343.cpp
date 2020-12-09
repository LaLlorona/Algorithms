#include <bits/stdc++.h>


using namespace std;
const int MAX = 100001;
int len_arr;
int num_blueray;
int lesson_size[MAX];

bool PossibleToStore(int blueray_size) {
	int current_size = 0;
	int need_blueray_num = 1;
	for (int i = 0; i < len_arr; i++) {
		if (lesson_size[i] > blueray_size) {
			return false;
		}
		if (current_size + lesson_size[i] > blueray_size) {
			current_size = lesson_size[i];
			need_blueray_num++;
		}
		else {
			current_size += lesson_size[i];
		}
	}
	if (need_blueray_num <= num_blueray) {
		return true;
	}
	else {
		return false;
	}
}

int FindMinSize() {
	int hi = 1000000000;
	int lo = 0;
	int ans = 0;
	while (lo <= hi) {
		int mid = (hi + lo) / 2;
		cout << mid << "\n";
		if (PossibleToStore(mid)) {
			ans = mid;
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	return ans;
	
}
int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> len_arr >> num_blueray) {
		for (int i = 0; i < len_arr; i++) {
			cin >> lesson_size[i];
		}
		cout << FindMinSize() << "\n";
	}
    

    return 0;
}

