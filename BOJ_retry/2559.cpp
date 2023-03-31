#include <bits/stdc++.h>

using namespace std;

int numVertice;
int numEdge;

const int MAX = 20001;

vector<int> graph[MAX];


int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    // std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); 
	// std::cin.rdbuf(in.rdbuf()); 

	while (cin >> numDays >> consecutiveDays) {
		for (int i = 0; i < numDays; i++) {
			cin >> temperatureRecord[i];
		}
		FillPartialSum();
		PrintMaxSum();
	}

}


  