#include <bits/stdc++.h>


using namespace std;

int n;
bool visited[10];
char operators[9];

int num_operator;
string max_cand;
string min_cand;

void Dfs(int index, string current_num) {
	if (index == num_operator + 1) {
		max_cand = max(max_cand, current_num);
		min_cand = min(min_cand, current_num);
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (!visited[i]) {
				if (index == 0) {
					visited[i] = true;
					Dfs(index + 1, current_num + to_string(i));
					visited[i] = false;
				}
				else {
					if (operators[index - 1] == '<') {//i should be bigger than current_num[index - 1]
						if (current_num[index - 1] - '0' < i) {
							visited[i] = true;
							Dfs(index + 1, current_num + to_string(i));
							visited[i] = false;
						}
					}
					else {// i should be smaller than current_num[index - 1]
						if (current_num[index - 1] - '0' > i) {
							visited[i] = true;
							Dfs(index + 1, current_num + to_string(i));
							visited[i] = false;
						}
					}
				}
			}
		}
	}
	
}

int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_operator) {
		for (int i = 0; i < num_operator; i++) {
			cin >> operators[i];
		}
		
		max_cand = string(num_operator + 1, '0');
		min_cand = string(num_operator + 1, '9');
		Dfs(0, "");
		cout << max_cand << "\n" << min_cand << "\n";
	}
    

    return 0;
}

