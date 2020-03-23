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
int arr[1000001];



int main()
{
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
    
	sort(arr, arr+ n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}

    return 0;
}

