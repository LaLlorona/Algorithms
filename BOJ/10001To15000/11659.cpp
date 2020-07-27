#include <bits/stdc++.h>


using namespace std;

int num_element, num_query;
int part_sum[100001];



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_element >> num_query) {
		memset(part_sum, 0, sizeof(part_sum));
		for (int i = 1; i <= num_element; i++) {
			int num;
			cin >> num;
			part_sum[i] = part_sum[i - 1] + num;
		}
		for (int i = 0; i < num_query; i++) {
			int from, to;
			cin >> from >> to;
			cout << part_sum[to] - part_sum[from - 1] << "\n";
		}
		
	}
	
    

    return 0;
}

