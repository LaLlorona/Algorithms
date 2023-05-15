#include <bits/stdc++.h>

using namespace std;

const int MAX = 100003;
int cache[MAX];
vector<int> graph[MAX];

int DFS(int here) {
	if (cache[here] != -1) {
		return cache[here];
	}
	if (graph[here].size() == 0) { // leaf node
		cache[here] = 1;
		return 1;
	}
	int& ret = cache[here];
	ret = 0;
	for (int i = 0; i < graph[here].size(); i++) {
		int child = graph[here][i];
		ret += DFS(child);
	}
	return ret;
}

vector<int> solution(int total_sp, vector<vector<int>> skills) {
	memset(cache, -1, sizeof(cache));

	int numSkills = skills.size() + 1;
	int spSum = 0;

	for (int i = 0; i < skills.size(); i++) {
		graph[skills[i][0] - 1].push_back(skills[i][1] - 1);	
	}
	for (int i = 0; i < numSkills; i++) {
		// cout << "node number is " << i <<" and sp value is " << skillSpValue[i] << "\n";
		spSum += DFS(i);
	}
	vector<int> answer;
	for (int i = 0; i < numSkills; i++) {
		answer.push_back(total_sp/spSum * DFS(i));
	}
	// cout << total_sp << " and sp sum is " << spSum << "\n"; 
    
    return answer;
}

void PrintVector(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i]<< " ";
	}
	cout << "\n";
}

int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(in.rdbuf());

	PrintVector(solution(121, {{2,1}, {2,3}, {3, 6}, {3,4}, {3,5}}));

}


  