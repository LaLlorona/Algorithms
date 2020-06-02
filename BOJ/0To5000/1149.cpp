#include <bits/stdc++.h>
//#include <iostream>

using namespace std;

const int MAX = 1000;

int price[MAX][3];
int red[MAX];
int green[MAX];
int blue[MAX];

int n;

int main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	while (cin >> n) {
		for (int i = 0;i < n; i++) {
			int price_red, price_green, price_blue;
			cin >> price_red >> price_green >> price_blue;
			price[i][0] = price_red;
			price[i][1] = price_green;
			price[i][2] = price_blue;
		}
		red[n - 1] = price[n - 1][0];
		green[n - 1] = price[n - 1][1];
		blue[n - 1] = price[n - 1][2];
		for (int i = n - 2; i >= 0; i = i - 1) {
			red[i] = min(green[i + 1], blue[i + 1]) + price[i][0];
			green[i] = min(red[i + 1], blue[i + 1]) + price[i][1];
			blue[i] = min(green[i + 1], red[i + 1]) + price[i][2];
		}
		cout << min(red[0], min(blue[0], green[0]));
		
	}
	
	
	
	return 0;
}



