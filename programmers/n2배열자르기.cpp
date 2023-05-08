#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int CalculateNumAtPosition(int y, int x, int n) {
	if (x <= y) {
		return y + 1;
	}
	else {
		return x + 1;
	}
}

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer(right - left + 1, -1);
	for (ll i = left; i <= right; i++) {
		int y = i / n;
		int x = i % n;
		answer[i - left] = CalculateNumAtPosition(y, x ,n);
	}
    return answer;
}

void PrintVector(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
}
int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(in.rdbuf());

	vector<int> ans1 = solution(4,7, 14);

	PrintVector(ans1);

	vector<int> test1 = vector<int>(10, -3);

	PrintVector(test1);


	


}


  