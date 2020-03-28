#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>
// #include <math.h>  
#include <map>


using namespace std;

int n;

int BeforeCycle(long long seed, int power) {
	long long next_num = seed;
	long long temp;
	int count = 1;
	map<long long, int> numbers; // numbers[k] indicates the order in which the number k came out  
	numbers[next_num] = count;
	
	while (true) {
		temp = next_num;
		next_num = 0;
		while (temp > 0) {
			next_num += pow(temp % 10, power);
			temp /= 10;
		}
		count++;
		if (numbers.find(next_num) == numbers.end()) { // not found
			numbers[next_num] = count;
		}
		else {
			return numbers[next_num] - 1;
		}
	}
	
	
}

int main()
{
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	long long first;
	int power;
	while (cin >> first >> power) {
		cout << BeforeCycle(first, power) << "\n";
	}
	
    

    return 0;
}

