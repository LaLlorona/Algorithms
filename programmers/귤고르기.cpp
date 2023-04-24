#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int INF = 1987654321;

int solution(int k, vector<int> tangerine) {
    map<int, int> sizeAndNumber;
    vector<pii> numberAndSizeVector;
    int cumulativeTangerineNum = 0;

    for (int i = 0 ; i < tangerine.size(); i++) {
        sizeAndNumber[tangerine[i]] += 1;
    }

    for (auto iter = sizeAndNumber.begin(); iter != sizeAndNumber.end(); iter++) {
        int size = iter->first;
        int number = iter->second;
        numberAndSizeVector.push_back(pii(number, size));
    }
    sort(numberAndSizeVector.begin(), numberAndSizeVector.end(), greater<pii>());

    // for (int i = 0 ; i < numberAndSizeVector.size(); i++) {
    //     cout << numberAndSizeVector[i].first << " " << numberAndSizeVector[i].second << "\n";
    // }

    for (int i = 0; i < numberAndSizeVector.size(); i++) {
        cumulativeTangerineNum += numberAndSizeVector[i].first;
        if (cumulativeTangerineNum >= k) {
            return i+1;
        }
    }


    return -INF;
}

int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(in.rdbuf());

    vector<int> test1 = {1, 3, 2, 5, 4, 5, 2, 3};

    cout << solution(6, test1) << "\n";

}


  