#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;
const int numColor = 3;
int numHouse;

int cost[MAX][numColor];
int cumulativeCost[MAX][numColor];

void FillCost() {
    for (int houseIndex = 0; houseIndex < numHouse; houseIndex++) {
        for (int colorIndex = 0; colorIndex < numColor; colorIndex++) {
            if (houseIndex == 0) {
                cumulativeCost[houseIndex][colorIndex] = cost[houseIndex][colorIndex];
            }

            else {
                if (colorIndex == 0) {
                    cumulativeCost[houseIndex][colorIndex] = cost[houseIndex][colorIndex] + min(cumulativeCost[houseIndex - 1][1], cumulativeCost[houseIndex -1][2]);
                }
                else if (colorIndex == 1) {
                    cumulativeCost[houseIndex][colorIndex] = cost[houseIndex][colorIndex] + min(cumulativeCost[houseIndex - 1][0], cumulativeCost[houseIndex -1][2]);
                }
                else if (colorIndex == 2) {
                    cumulativeCost[houseIndex][colorIndex] = cost[houseIndex][colorIndex] + min(cumulativeCost[houseIndex - 1][1], cumulativeCost[houseIndex -1][0]);
                }
            }
        }
    }
    cout << min(min(cumulativeCost[numHouse - 1][0], cumulativeCost[numHouse - 1][1]), cumulativeCost[numHouse -1][2]) <<"\n";
}

int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    // std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); 
	// std::cin.rdbuf(in.rdbuf()); 

    while (cin >> numHouse) {
        for (int i = 0; i < numHouse; i++) {
            for (int j = 0; j < numColor; j++) {
                cin >> cost[i][j];
            }
        }
        FillCost();
    }

}


  