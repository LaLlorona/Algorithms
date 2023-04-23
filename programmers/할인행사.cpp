#include <bits/stdc++.h>

using namespace std;

const int discountDay = 10;
map<string, int> targetProduct;
map<string, int> currentProduct;

bool CheckCanRegister() {
    for (auto iter = targetProduct.begin(); iter != targetProduct.end(); iter++) {
        string targetProductName = iter->first;
        int targetCount = iter->second;

        // cout << targetProductName << " " << targetCount << "\n";
        if (currentProduct[targetProductName] < targetCount) {
            // cout << "required product " << targetProductName << " is not enough\n";
            return false;
        }
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for (int i = 0 ; i < want.size(); i++) {
        targetProduct[want[i]] = number[i];
    }

    for (int i = 0; i < discountDay; i++) {   
        currentProduct[discount[i]] += 1;
    }
    // cout << "current day is " << 0 << " \n";
    for (auto iter = currentProduct.begin(); iter != currentProduct.end(); iter++) {
            string currentProductName = iter->first;
            int currentCount = iter->second;

            // cout << currentProductName << " " << currentCount << " " << "\n";
        }
    if (CheckCanRegister()) {
        
        answer++;
    }

    for (int i = 1; i <= discount.size() - discountDay; i++) {
        // cout << "current day is " << i << " \n";
        currentProduct[discount[i - 1]] -= 1;
        currentProduct[discount[i + discountDay - 1]] += 1;
        for (auto iter = currentProduct.begin(); iter != currentProduct.end(); iter++) {
            string currentProductName = iter->first;
            int currentCount = iter->second;

            // cout << currentProductName << " " << currentCount << " " << "\n";
        }
        if (CheckCanRegister()) {
            answer++;
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

    vector<string> want = {"banana", "apple", "rice", "pork", "pot"};
    vector<int> number = {3, 2, 2, 2, 1};
    vector<string> discount = {"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"};

    // map<int, int> testing;
    // testing[3] += 1;
    // cout << testing[3];

    cout << solution(want, number, discount) << "\n";

}


  