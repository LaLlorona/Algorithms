#include <bits/stdc++.h>

using namespace std;


bool IsInBound(string block, int pos) {
	return (pos >= 0 && pos < block.size());
}
long long solution(string block, int pos) {
    long long answer = 0;
	string currentBlock = block;
	int currentPos = pos - 1;
	int lo, hi;

	if (block[currentPos] == '>') {
		lo = currentPos;
		while (block[currentPos] != '<') {
			currentPos += 1;
		}
		hi = currentPos;
	}
	else {
		hi = currentPos;

		while (block[currentPos] != '>') {
			currentPos -= 1;
		}
		lo = currentPos;
	}
	answer += hi - lo;

	while (lo >= 0 && hi < block.size()) {
		if (currentPos == lo) { // we need to increase hi
			// cout << "current Pos is lo, and we will increase hi.\n" ;
			// cout << "current lo hi value is lo is " << lo << " hi value is " << hi << "\n";
			
			hi += 1;
			while (IsInBound(block, hi) && block[hi] != '<') {
				hi +=1;
			}
			// cout << "after update, hi value is " << hi << "\n";
			currentPos = hi;
		}
		else { // we need to decrease lo
			// cout << "current Pos is hi, and we will decrease lo.\n" ;
				// cout << "current lo hi value is lo is " << lo << " hi value is " << hi << "\n";
				lo -= 1;
				while (IsInBound(block, lo) && lo < 0) {
					lo -= 1;
				}
				// cout << "after update, lo value is " << lo << "\n";
				currentPos = lo;
				
				
		}
		answer += hi - lo;
	}
    return answer;
}

int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(in.rdbuf()); 

	cout << solution(">><", 1) << "\n";

	cout << solution(">><>>", 2) << "\n";

}


  