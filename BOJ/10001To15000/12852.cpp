#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <cstddef>
#include <algorithm>
#include <cstring>

using namespace std;

int cache[1000003];
const int INF = 987654321;
int MakeOne(int n) {
	int ret = INF;
	if (n == 1) {
		return 0;
	}
	
	else if (cache[n] != -1) {
		return cache[n];
	}
	else {
		int choice1 = INF;
		int choice2 = INF; 
		int choice3 = INF;
		if (n % 3 == 0) {
			choice1 = MakeOne(n / 3) + 1;
		}
		if (n % 2 == 0) {
			choice2 = MakeOne(n / 2) + 1;
		}
		choice3 = MakeOne(n - 1) + 1;
		ret = min(choice3, min(choice2, choice1));
		cache[n] = ret;
	}
	return ret;
}

void PrintPath(int n) {
	cout << n << " ";
	int choice1 = INF;
	int choice2 = INF; 
	int choice3 = INF;
	if (n == 1) {
		return;
	}
	if (n % 3 == 0) {
		choice1 = cache[n / 3];
	}
	if (n % 2 == 0) {
		choice2 = cache[n / 2];
	}
	choice3 = cache[n - 1];
	int ret = INF;
	ret = min(choice3, min(choice2, choice1));
	if (ret == choice1) {
		PrintPath(n / 3);
	}
	else if (ret == choice2) {
		PrintPath(n / 2);
	}
	else {
		PrintPath(n - 1);
	}
}

int main()
{
	memset(cache, -1, sizeof(cache));
	
	
	int n;
	cin >> n;
	cout << MakeOne(n) << "\n";
	
	PrintPath(n);
    return 0;
}

