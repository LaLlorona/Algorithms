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

	while (IsInBound(block, lo) && IsInBound(block, hi)) {
		if (currentPos == lo) { // we need to increase hi		
			hi += 1;
			while (IsInBound(block, hi) && block[hi] != '<') {
				hi +=1;
			}
			currentPos = hi;
		}
		else { // we need to decrease lo
				lo -= 1;
				while (IsInBound(block, lo) && lo < 0) {
					lo -= 1;
				}
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


  