#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

const int INF = 987654321;


int TortoiseAndHare(int arr[]) {
	
	int tortoise = arr[arr[0]];
	int hare = arr[tortoise];
	int duplicate_index = -1;
	
	
	while (tortoise != hare) {
		
		tortoise = arr[tortoise];
		hare = arr[arr[hare]];
	}
	
	tortoise = arr[0];
	while (tortoise != hare) {
		tortoise = arr[tortoise];
		hare = arr[hare];
	}
	return tortoise;
}
int main()
{
	int input[] = {1,2,3,6,2,4,5};
	cout << TortoiseAndHare(input) << endl;
	
	
    

    return 0;
}

