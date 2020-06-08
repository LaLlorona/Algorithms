#include <bits/stdc++.h>


using namespace std;

int num_houses;
int num_wifi;
int position[200001];

bool DistanceBetween(int k) {
	int built = 1;
	int here = position[0];
	
	for (int i = 1; i < num_houses; i++) {
		if (position[i] - here >= k) {
			built++;
			here = position[i];
		}
	}
	
	if (built >= num_wifi) {
		return true;
	}
	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	while (cin >> num_houses >> num_wifi) {
		for (int i = 0; i < num_houses; i++) {
			cin >> position[i];
		}
		sort(position, position + num_houses);
		// for (int i = 1; i < 10; i++) {
		// 	cout << i << " " << DistanceBetween(i) << "\n";
		// }
		int lo = 0;
		int hi = 1000000000;
		int ret = (hi + lo) / 2;
		int mid;
		while (lo <= hi) {
			//cout << hi << "\n";
			mid = (lo + hi) / 2;
			
			if (DistanceBetween(mid)) {
				
				ret = mid;
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}
		cout << ret << "\n";
	}
    

    return 0;
}

