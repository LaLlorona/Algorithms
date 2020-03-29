#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>



using namespace std;

long long num_woods;
long long len_needed;
vector<long long> woods;

bool decision(long long cut) {
	long long total_length = 0;
	for (long long i = 0; i < num_woods; i++) {
		if (woods[i] > cut) {
			total_length += woods[i] - cut;
		}
		
	}
	if (total_length >= len_needed) {
		return true;
	}
	return false;
}

long long optimize() {
	long long lo = 0;
	long long hi = 1000000000;
	long long mid;
	
	while (lo  <= hi) {
		//cout << "lo is " << lo << " and hi is " << hi << endl;
		mid = (lo + hi) / 2;
		if (decision(mid)) {
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	return hi;
}


int main()
{
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	long long each_len;
	while (cin >> num_woods >> len_needed) {
		woods.clear();
		for (long long i = 0; i < num_woods; i++) {
			cin >> each_len;
			woods.push_back(each_len);
		}
		cout << optimize() << "\n";
		
	}
    

    return 0;
}