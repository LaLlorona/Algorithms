#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
stack<pii> numberStack; //number, index

vector<int> solution(vector<int> numbers) {
    
    vector<int> answer(numbers.size(), -1);
    
    for (int i = 0; i < numbers.size(); i++) {
        while (!numberStack.empty()) {
            pii currentNumber = numberStack.top();
            if (currentNumber.first >= numbers[i]) {
                break;
            }
            numberStack.pop();
            answer[currentNumber.second] = numbers[i];
        }
        numberStack.push(pii(numbers[i], i));
    }
    return answer;

    
}

void PrintVector(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << "\n";
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
    vector<int> test1 = {2, 3, 3, 5};
    vector<int> ans = solution(test1);
    PrintVector(ans);

}


  