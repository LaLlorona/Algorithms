#include <bits/stdc++.h>


using namespace std;

int n, m;


int gcd(int a, int b) {
	if (b > a) {
		gcd(b, a);
	}
	return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
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
		vector<int> input_sequence;
		vector<int> difference;
		vector<int> v;
		int num;
		for (int i = 0; i < n; i++) {
			cin >> num;
			input_sequence.push_back(num);
		}
		sort(input_sequence.begin(), input_sequence.end());
		for (int i = input_sequence.size() - 2; i >= 0; i--) {
			difference.push_back(input_sequence[i + 1] - input_sequence[i]);
		}
		int gcd_all = gcd(difference[0], difference[1]);
		for (int i = 1; i < difference.size(); i++) {
			gcd_all = gcd(gcd_all, difference[i]);
		}
		for (int i = 2; i * i <= gcd_all; i++) {
			if (gcd_all % i == 0) {
				v.push_back(i);
				v.push_back(gcd_all / i);
			}
		}
		v.push_back(gcd_all);
		sort(v.begin(), v.end());
    	v.erase(unique(v.begin(), v.end()), v.end());
		
		
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
	} 
	
	
	
    

    return 0;
}

