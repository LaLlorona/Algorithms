#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

long long solution(vector<int> weights) {
    map<int, int> possibleWeights;
    long long answer = 0;

    for (int i = 0; i < weights.size(); i++) {
        int currentWeight = weights[i];

        answer += (possibleWeights[currentWeight] + possibleWeights[currentWeight * 2]);

        if (currentWeight % 2 == 0) {
            answer += (possibleWeights[currentWeight * 3 / 2] + possibleWeights[currentWeight / 2]);
        }

        if (currentWeight % 3 == 0) {
            answer += (possibleWeights[currentWeight * 2 / 3] + possibleWeights[currentWeight * 4 / 3]);
        }

        if (currentWeight % 4 == 0) {
            answer += possibleWeights[currentWeight * 3 / 4];
        }
        if (possibleWeights[currentWeight] == 0) {
            possibleWeights[currentWeight] = 1;
        }
        else {
            possibleWeights[currentWeight] += 1;
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

    vector<int> test = {100,180,360,100,270};
    vector<int> test2(100000, 100);
    cout << solution(test2) << "\n";

}


  