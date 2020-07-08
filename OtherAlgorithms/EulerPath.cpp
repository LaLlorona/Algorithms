#include <bits/stdc++.h>


using namespace std;

int num_tickets, num_city;
int num_adj[100][100];
int inbound[100];
int outbound[100];


map<string, int> place_to_num; // hash table to covert place name to integer
map<int, string> num_to_place; 

map<string, int>::iterator it;



void MakeEuler(int here, vector<int>& path) {
	for (int there = 0; there < num_city; there++) {
		while (num_adj[here][there] > 0) {
			num_adj[here][there]--;
			MakeEuler(there, path);
		}
	}
	path.push_back(here);
}

int CheckEuler() { // return -1 when it is impossible to make eulerpath or circuit. if it is possible, return one of the possible begin point
	int begin_candidate = 0;
	int end_candidate = 0;
	int num_begin_candidate = 0;
	int num_end_candidate = 0;
	
	for (int i = 0; i < num_city; i++) {
		if (abs(inbound[i] - outbound[i]) >= 2) {
			return -1;
		}
		else {
			if (outbound[i] - inbound[i] == 1) {
				num_begin_candidate++;
				begin_candidate = i;
			}
			else if (inbound[i] - outbound[i] == 1) {
				num_end_candidate++;
				end_candidate = i;
			}
		}
	}
	
	
	
	if ((num_begin_candidate == 0 && num_end_candidate == 0) ||(num_begin_candidate == 1 && num_end_candidate == 1)) {
		return begin_candidate;
	}
	else {
		return -1;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_tickets >> num_city) {
		place_to_num.clear();
		memset(num_adj, 0 ,sizeof(num_adj));
		memset(inbound, 0, sizeof(inbound));
		memset(outbound, 0, sizeof(outbound));
		
		string here, to;
		int index_city = 0;
		for (int i = 0; i < num_tickets; i++) {
			cin >> here >> to;
			if (place_to_num.find(here) == place_to_num.end()) {
				place_to_num[here] = index_city;
				num_to_place[index_city] = here;
				index_city++;
			}
			if (place_to_num.find(to) == place_to_num.end()) {
				place_to_num[to] = index_city;
				num_to_place[index_city] = to;
				index_city++;
			}
			int num_here = place_to_num[here];
			int num_there = place_to_num[to];
			num_adj[num_here][num_there]++;
			inbound[num_there]++;
			outbound[num_here]++;
			
		}
		vector<int> euler_path;
		// for (int i = 0; i < num_city; i++) {
		// 	cout << inbound[i] << "," << outbound[i] << "\n";
		// }
	
		int entry_point = CheckEuler();
		if (entry_point == -1) {
			cout << "Your intellectual destitution screwed the plan\n";
		}
		else {
			MakeEuler(entry_point, euler_path);
			reverse(euler_path.begin(), euler_path.end());
			for (int i = 0; i < euler_path.size(); i++) {
				cout << num_to_place[euler_path[i]] << " ";
			}
			cout << "\n";
		}
		
		
		
	} 
    

    return 0;
}

