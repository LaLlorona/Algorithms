#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int n;
int price[2][100002];
int cache[2][100002] = {0, };


int MaxPrice() {
	
	
	cache[0][0] = price[0][0];
	cache[1][0] = price[1][0];
	cache[0][1] = price[0][1] + price[1][0];
	cache[1][1] = price[1][1] + price[0][0];
	for (int j = 2; j < n; j++) {
		for (int i = 0 ; i < 2; i++) {
		
			if (i == 0) {
				cache[i][j] = max(cache[1][j-1], cache[1][j-2]) + price[i][j];
			}
			else{
				cache[i][j] = max(cache[0][j-1], cache[0][j-2]) + price[i][j];
			}
		}
	}
	
	
	return max(cache[0][n - 1], cache[1][n - 1]);
	
}

int main()
{
	
	
	
	int num_testcase;
	cin >> num_testcase;
	
	for (int i = 0; i < num_testcase; i++) {
		cin >> n;
		memset(cache, 0, sizeof(cache));
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < n; k++) {
				cin >> price[j][k];
			}
			
			
		}
		cout << MaxPrice() << endl;
		
	}
    

    return 0;
}

