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
int sum[11];

void FillSum() {
	sum[1] = 1;
	sum[2] = 2;
	sum[3] = 4;
	for (int i = 4; i <= 10; i++) {
		sum[i] = sum[i - 1] + sum[i - 2] + sum[i - 3];
	}
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	memset(sum, 0 ,sizeof(sum));
	FillSum();
	
	int num_testcase;
	cin >> num_testcase;
	for (int i = 0; i < num_testcase; i++) {
		cin >> n;
		cout << sum[n] << "\n";
	}
	
	
    

    return 0;
}

