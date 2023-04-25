#include <bits/stdc++.h>

using namespace std;



int solution(vector<int> order) {
    int itemOnMainContainer = 1;
    stack<int> additionalContainer;

    for (int i = 0; i < order.size(); i++) {

        // cout << "ith item "<< i << "\n";
        if (order[i] > itemOnMainContainer) {
            // cout << "order " << order[i]  << " is bigger than item on main container " << itemOnMainContainer << "\n";
            for (int j = itemOnMainContainer; j < order[i]; j++) {
                additionalContainer.push(j);
            }
            itemOnMainContainer = order[i] + 1;
        }
        else if (order[i] == itemOnMainContainer) {
            // cout << "item on main container is same with " << itemOnMainContainer << "\n";
            itemOnMainContainer += 1;
        }
        else {
            int itemOnAdditionalContainer = additionalContainer.top();
            additionalContainer.pop();
            // cout << "trying to check top item in the container " << itemOnAdditionalContainer << "\n";
        
            if (order[i] != itemOnAdditionalContainer) {
                
                return i;
            }
        }
    }
    return order.size();
}

int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(in.rdbuf());


    vector<int> test3 = {2, 1, 6, 7, 5, 8, 4, 9, 3, 10};

    cout << solution(test3) << "\n";



}


  