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

int N, M;
vector<int> A, B;

void Merge(vector<int> &arr1, vector<int> &arr2) {
	int iter_A = 0;
	int iter_B = 0;
	while (iter_A < N || iter_B < M) {
		

		if (iter_B == M) { // A 의 값을 넣는 경우 
			cout << arr1[iter_A] << " ";
			iter_A++;
		}
		else if (iter_A == N) { // B 의 값을 넣는 경우
			cout << arr2[iter_B] << " ";
			iter_B++;
		}
		
		else if (A[iter_A] < B[iter_B]) {
			cout << arr1[iter_A] << " ";
			iter_A++;
		}
		
		else {
			cout << arr2[iter_B] << " ";
			iter_B++;
		}
	}
	
	
}




int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	int input_num;
	int input_num2;
	
	while (cin >> N >> M) {
		A.clear();
		B.clear();
		for (int i = 0 ; i < N; i++) {
			cin >> input_num;
			A.push_back(input_num);
		}
		for (int i = 0 ; i < M ; i++) {
			cin >> input_num2;
			B.push_back(input_num2);
		}
		Merge(A, B);
		cout << "\n";
	}
    

    return 0;
}

