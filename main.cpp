#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int solution(vector<int> queue1, vector<int> queue2) {
	queue<int> firstQueue;
	queue<int> secondQueue;

	ll sumFirstQueue = 0;
	ll sumSecondQueue = 0;

	int numTry = 0;

	for (int i = 0; i <queue1.size(); i++) {
		sumFirstQueue += queue1[i];
		firstQueue.push(queue1[i]);

		sumSecondQueue += queue2[i];
		secondQueue.push(queue2[i]);
	}

	while (numTry <= queue1.size() * 4) {
		
		if (sumFirstQueue == sumSecondQueue) {
			return numTry;
		}
		else if (sumFirstQueue > sumSecondQueue) {
			sumSecondQueue += firstQueue.front();
			sumFirstQueue -= firstQueue.front();

			secondQueue.push(firstQueue.front());
			firstQueue.pop();
		}
		
		else { // when sumSecondQueue > sumFirstQueue
			sumFirstQueue += secondQueue.front();
			sumSecondQueue -= secondQueue.front();
			
			firstQueue.push(secondQueue.front());
			secondQueue.pop();
		}
		numTry += 1;
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

	vector<int> test1 = {3,2,7,2};
	vector<int> test2 = {4,6,5,1};

	cout << solution(test1, test2) << "\n";

	cout << solution({1,2,1,2} , {1, 10, 1, 2}) << "\n";

	cout << solution({1,1}, {1,5}) << "\n";

}


  