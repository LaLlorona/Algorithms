#include <bits/stdc++.h>


using namespace std;

int n;
int input_arr[100000];
bool FindNumber(int to_find) { // left cut : always exclude one element. if there is no center, exclude an element closest to the physical center from left division.
	// minimum length : 1
	int lo = 0;
	int hi = n - 1;
	while (lo <= hi) {
		int mid = (lo + hi ) / 2;
		if (input_arr[mid] == to_find) {
			return true;
		}
		else if (input_arr[mid] > to_find) {
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
//     std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//     std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	while (cin >> n) {
		for(int i = 0; i < n; i++) {
			cin >> input_arr[i];
		}
		sort(input_arr, input_arr + n);
		int num_to_find;
		int to_find;
		cin >> num_to_find;
		for (int i = 0; i < num_to_find; i++) {
			cin >> to_find;
			cout << FindNumber(to_find) << "\n";
		}
		
		
	}
    

    return 0;
}

