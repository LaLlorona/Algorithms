#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {

	priority_queue<int, vector<int>, greater<int>> food;
	int numTry = 0;

	for (int i = 0; i < scoville.size(); i++) {
		food.push(scoville[i]);
	}

	while ((food.size() > 1) && food.top() < K) {
		numTry +=1;
		int food1 = food.top();
		food.pop();
		int food2 = food.top();
		food.pop();
		food.push(food1 + food2 * 2);
	}
	if (food.top() >= K) {
		return numTry;
	}
	return -1;
	

}


int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(in.rdbuf()); 

	cout << solution({1, 2, 3, 9, 10, 12}, 7);

}


  