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

int MAX_NUM = 1001;
int price[1001];
int max_price[1001];
int N;

int MaxPrice() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) { //when buying a card pack with j cards
			max_price[i] = max(max_price[i], price[j] + max_price[i - j]);
		}
	}
	return max_price[N];
}

int main()
{
	
	cin >> N;
	price[0] = 0;
	memset(max_price, 0, sizeof(max_price));
	for (int i = 1; i <= N; i++) {
		cin >> price[i];
	}
	cout << MaxPrice() << "\n";
    return 0;
}


