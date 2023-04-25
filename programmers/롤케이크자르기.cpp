#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> topping) {
    vector<int> accumulateToppingFront(topping.size(), -1);
    vector<int> accumulateToppingBack(topping.size(), -1);
    map<int, int> frontToppingMap;
    map<int, int> backwardToppingMap;

    int numToppingDifferentFront = 0;
    int numToppingDifferentBack = 0;

    for (int i = 0; i < topping.size(); i++) {
        if (frontToppingMap[topping[i]] == 0) {
            frontToppingMap[topping[i]] = 1;
            numToppingDifferentFront += 1;
        }
        accumulateToppingFront[i] = numToppingDifferentFront;


        if (backwardToppingMap[topping[topping.size() - 1 - i]] == 0) {
            backwardToppingMap[topping[topping.size() - 1 - i]] = 1;
            numToppingDifferentBack +=1;
        }
        accumulateToppingBack[topping.size() - 1 - i] = numToppingDifferentBack;
    }

    // for (int i = 0; i < accumulateToppingBack.size(); i++) {
    //     cout << accumulateToppingFront[i] << " ";
    // }
    // cout << "\n";

    // for (int i = 0; i < accumulateToppingBack.size(); i++) {
    //     cout << accumulateToppingBack[i] << " ";
    // }


    int answer = 0;

    for (int i = 0; i < topping.size() - 1; i++) {
        if (accumulateToppingFront[i] == accumulateToppingBack[i + 1]) {
            answer += 1;
        }
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

    vector<int> test1 = {1, 2, 1, 3, 1, 4, 1, 2};
    vector<int> test2 = {1, 2, 3, 1, 4};

    cout << solution(test1);

    cout << "\n";

    cout << solution(test2);

}

