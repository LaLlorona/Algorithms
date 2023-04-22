#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int numChoices = 17;
const int totalStory = 100000001;
// int choices[numChoices] = {1, 10, 100, 1000, 10000, 100000, 1000000,10000000,100000000, -1, -10, -100,-1000,-10000, -100000, -1000000,-10000000};
int choices[numChoices] = {100000000,10000000,1000000, 100000, 10000, 1000,100,  10,1, -10000000,-1000000, -1, -10, -100,-1000,-10000, -100000, };
int numSteps[totalStory];
int targetStory;

bool isInBound(int step) {
    return (step >= 0 && step <= 100000000);
}
int BFS() {
    numSteps[0] = 0;
    memset(numSteps, -1, sizeof(numSteps));

    queue<pii> bfsQueue; // story, step
    bfsQueue.push(pii(0,0));

    while (!bfsQueue.empty()) {
        pii here = bfsQueue.front();
        bfsQueue.pop();
        int hereStory = here.first;
        int hereStep = here.second;

        for (int i = 0; i < numChoices; i++) {
            int nextStory = hereStory + choices[i];
            int nextStep = hereStep + 1;

            if (nextStory == targetStory) {
                return nextStep;
            }
            if (isInBound(nextStory) && numSteps[nextStory] == -1) {
                numSteps[nextStory] = nextStep;
                bfsQueue.push(pii(nextStory, nextStep));
            }
        }
    }
}



int solution(int storey) {
    targetStory = storey;

    int answer = BFS();


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

}


  