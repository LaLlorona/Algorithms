#include <bits/stdc++.h>


using namespace std;


vector<int> graph[32001];
int num_pointed[32001];
int num_student, num_comparison;
vector<int> order;



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	while (cin >> num_student >> num_comparison) {
		
		memset(num_pointed, 0, sizeof(num_pointed));
		for (int i = 0; i < 32001; i++) {
			graph[i].clear();
		}
		for (int i = 0; i < num_comparison; i++) {
			int small, tall;
			cin >> small >> tall;
			small--;
			tall--;
			graph[tall].push_back(small);
			num_pointed[small]++;
		}
		queue<int> free_students; // students where tallest among comparison;
		for (int i = 0; i < num_student; i++) {
			if (num_pointed[i] == 0) {
				free_students.push(i);
			}
		}
		vector<int> tallest;
		while (!free_students.empty()) {
			int free_student = free_students.front();
			//cout << free_student << "\n";
			free_students.pop();
			tallest.push_back(free_student + 1);
			for (int i = 0; i < graph[free_student].size(); i++) {
				int there = graph[free_student][i];
				num_pointed[there]--;
				if (num_pointed[there] == 0) {
					free_students.push(there);
				}
			}
		}
		for (int i = tallest.size() - 1; i >= 0; i--) {
			cout << tallest[i] << " ";
		}
		
	} 
	
	
    

    return 0;
}

