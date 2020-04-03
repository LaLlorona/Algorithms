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

int n;

void Merge(int arr[], int lo, int mid, int hi) {
	int left = 0;
	int right = 0;
	int merged [hi - lo + 1];
	while ((lo + left <= mid || mid + 1 + right <= hi))
	if (mid + 1 + right > hi || arr[lo + left] < arr[mid + 1 + right]) {
		merged[left + right] = arr[lo + left];
		left++;
	}
	else{
		merged[left + right] = arr[mid + 1 + right];
		right++;
	}
	for (int i = 0; i < hi - lo + 1; i++) {
		arr[i + lo] = merged[i];
	}
	//arr = merged;
}

void MergeSort(int arr[], int lo, int hi) {
	int mid = lo + (hi - lo) / 2;
	
	if (hi > lo) {
		MergeSort(arr, lo, mid);
		MergeSort(arr, mid + 1, hi);
		Merge(arr, lo, mid, hi);
	}
	
}




int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	

	
	int test[9] = {8,7,6,5,4,3,2,1 ,3};
	int test2[4] = {8, 7, 6, 5};
	int test3[4] = {4, 3, 2, 1};
	
	MergeSort(test, 0, 8);
	MergeSort(test2, 0, 3);
	//Merge(test2, 0, 3, 4);
	MergeSort(test3, 0, 3);
	for (int i = 0; i < 9; i++) {
		cout << test[i] << " ";
	}
	cout << "\n";
	
	for (int i = 0; i < 4; i++) {
		cout << test2[i] << " ";
	}
	cout << endl;
	
	for (int i = 0 ; i< 4; i++) {
		cout << test3[i] << " ";
	}
    

    return 0;
}

