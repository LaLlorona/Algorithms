#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

vector<ll> input_arr;
vector<ll> tree;
const int MAX = 1001;
vector<int> from_east_to_west[MAX];
int num_west, num_east, num_road;
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
	
	int num_testcase;
	int current_solving = 0;
	cin >> num_testcase;
	while (num_testcase--) {
		current_solving++;
		cin >> num_east >> num_west >> num_road;
		
		ll ans = 0;
		for (int i = 0; i < MAX; i++) {
			from_east_to_west[i].clear();
		}
		input_arr.clear();
		tree.clear();
		input_arr.resize(MAX);
		tree.resize(4 * MAX);
		
		for (int i = 0; i < num_road; i++) {
			int east, west;
			cin >> east >> west;
			from_east_to_west[east].push_back(west);
		}
		
	
	
		for (int i = 1; i < MAX; i++) {
			for (int j = 0; j < from_east_to_west[i].size(); j++) {
				int there = from_east_to_west[i][j];
				ans += sum(tree, 1, 0, MAX - 1, there + 1, MAX - 1);
			}
			for (int j = 0; j < from_east_to_west[i].size(); j++) {
				int there = from_east_to_west[i][j];
				input_arr[there]++;
				update(tree, 1, 0, MAX - 1, there, 1);
			}
			
		}
		cout << "Test case " << current_solving << ": " << ans << "\n";
		
		
	}
    

    return 0;
}