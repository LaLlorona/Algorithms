#include <bits/stdc++.h>

using namespace std;


const int MAX = 101;
int numMalfunction;
int numVertice;
vector<int> graph[MAX];
vector<int> malfunctions;
bool visited[MAX];


//1. 1부터 numVertice 까지의 노드들 중 랜덤하게 k 개를 선택하는 알고리즘을 만든다. 
//2. k 개의 선택한 node 들을 shutdown 할 때 모든 malfunction node 를 없앨 수 있는 경우, 그 때 종료된 프로세스 - numMalfunction 값과 min 값의 min을 취한다.
//모든 선택의 경우에 대해 1,2를 반복한다. 

vector<vector<int> > permutations;
vector<int> permutationMidResult;
bool selected[MAX];

void PrintVVI() {
	for (int i = 0; i < permutations.size(); i++) {
		for (int j = 0; j < permutations[i].size(); j++) {
			cout << permutations[i][j] << " ";
		}
		cout << "\n";
	}
}

void DFS(int n) {
	if (visited[n]) {
		return; 
	}

	visited[n] = true;
	for (int i = 0; i < graph[n].size(); i++) {
		int next = graph[n][i];
		DFS(next);
	}

}

void FillPermutation(int currentSelect, int lowerBound, int k) {
	if (currentSelect == k) {
		permutations.push_back(permutationMidResult);
		return;
	}

	for (int i = lowerBound; i <= numVertice; i++) {
		if (!selected[i]) {
			selected[i] = true;
			permutationMidResult.push_back(i);
			FillPermutation(currentSelect + 1, i + 1, k);

			permutationMidResult.pop_back();
			selected[i] = false;
		}
	}
}

int NumTerminatedNormalProcess() {
	int counter = 0;
	for (int i = 0; i < malfunctions.size(); i++) {
		if (!visited[malfunctions[i]]) {
			return -1;
		}
	}

	for (int i = 1; i <= numVertice; i++) {
		if (visited[i]) {
			counter += 1;
		}
	}
	return counter - malfunctions.size();
}
void PrintVector(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i]<< " ";
	}
	cout << "\n";
}

vector<int> solutions() {
	FillPermutation(0, 1, 3);
	for (int i = 0; i < permutations.size(); i++) {
		memset(visited, 0, sizeof(visited));
		vector<int> currentCombination = permutations[i];
		for (int j = 0; j < currentCombination.size(); j++) {
			DFS(currentCombination[j]);
		}
		PrintVector(currentCombination);
		cout << "num terminated process is " << NumTerminatedNormalProcess() << "\n";
	}
}



int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(in.rdbuf()); 


	cin >> numVertice;
	int a, b;
	for (int i = 0; i < numVertice - 1; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
	}
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int d;
		cin >> d;
		malfunctions.push_back(d);
	}

	PrintVector(malfunctions);

	
	solutions();



}


  