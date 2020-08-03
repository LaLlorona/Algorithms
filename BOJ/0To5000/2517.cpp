#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

int num_players;
vector<ll> input_arr;
vector<ll> tree;
vector<int> player_power;
vector<int> initial_player_power;
const int MAX = 5000010;
map<int, int> power_to_rank;

ll init (vector<ll> &input_arr, vector<ll> &tree, ll node, ll start, ll end) { // when the node deals with sum from start to end
	if (start == end) {
		return tree[node] = input_arr[start];
	}
	else {
		ll mid = (start + end) / 2;
		return tree[node] = init(input_arr, tree, 2 * node, start, mid) + init(input_arr, tree, 2 * node + 1, mid + 1, end);
	}
}

ll sum(vector<ll> &tree, ll node, ll start, ll end, ll left, ll right) {//when node covers start to end, and we want to calculate sum from left to right 
	if (end < left || right < start) {
		return 0;
	}
	else if (left <= start && end <= right) {
		return tree[node];
	}
	else {
		ll mid = (start + end) / 2;
		return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
	}
}

ll update(vector<ll> &tree, ll node, ll start, ll end, ll index, ll diff) {//when node covers start to end, we want to change indexth item 
	if (index < start || end < index) {
		return tree[node];
	}
	
	else if (start == end) { // when the node is leaf node
		return tree[node] += diff;
	}
	else { // when this node is not leaf node 
		ll mid = (start + end) / 2;
		return tree[node] = update(tree, node * 2, start, mid, index, diff) + update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
	
}





int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> num_players) {
		input_arr.clear();
		tree.clear();
		power_to_rank.clear();
		player_power.clear();
		initial_player_power.clear();
		for (int i = 0; i < num_players; i++) {
			int rank;
			cin >> rank;
			player_power.push_back(rank);
			initial_player_power.push_back(rank);
		}
		sort(player_power.begin(), player_power.end());
		for (int i = 0; i < num_players; i++) {
			power_to_rank[player_power[i]] = num_players - 1 - i; //weakest power player will be numplayer - 1
		}
		input_arr.resize(num_players);
		tree.resize(num_players * 4);
		for (int i = 0; i < num_players; i++) {
			int current_rank = power_to_rank[initial_player_power[i]];
			cout << sum(tree, 1, 0, num_players - 1, 0, current_rank) + 1 << "\n";
			update(tree, 1, 0, num_players - 1, current_rank, 1);
		}
		
		
	
		
	}
	
	
    

    return 0;
}