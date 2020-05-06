#include <bits/stdc++.h>


using namespace std;
int arr[100];
int n;

bool FindNumber(int to_find) { // left cut : always exclude one element. if there is no center, exclude an element closest to the physical center from left division.
	// minimum length : 1
	int lo = 0;
	int hi = 99;
	while (lo <= hi) {
		int mid = (lo + hi ) / 2;
		if (arr[mid] == to_find) {
			return true;
		}
		else if (arr[mid] > to_find) {
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	return false;
}

bool FindNumber2(int to_find) { // left+ division : if there is center, include it on the left division.
	//minimum length : 2
	int lo = 0;
	int hi = 99;
	while (lo < hi) {
		int mid = (lo + hi ) / 2;
		
		if (arr[mid] == to_find) {
			return true;
		}
		else if (arr[mid] > to_find) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	if (arr[lo] == to_find) { // because left+division can have two element in a segment, we need to check whether second element can be found 
		return true;
	}
	return false;
}



int main()
{
	
	
	for (int i = 0; i < 100; i++) {
		arr[i] = i;
	}
	
	for (int i = -3; i < 103; i++) {
		cout << "try to find " << i << " and the result is " << FindNumber2(i) << "\n";
	}
	//FindNumber2(99);

    return 0;
}

