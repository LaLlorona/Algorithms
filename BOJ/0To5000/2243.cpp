#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

const ll MAX_CANDY = 1000001;

vector<ll> input_arr;
vector<ll> initial_input_arr;
vector<ll> tree;
map<ll, ll> num_to_relative_size;

const ll INF = 1987654321;
ll num_input;
ll num_query;




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

ll query(vector<ll>& tree, ll node, ll start, ll end, ll k) { //return index of array with accumulate sum contains k
	if (start == end) {
		return start;
	}
	else {
		ll mid = (start + end) / 2;
		if (tree[node * 2] >= k) { // search left side of the tree
			return query(tree, node * 2, start, mid, k);
		}
		else {
			return query(tree, node * 2 + 1, mid + 1, end, k - tree[node * 2]);
		}
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
	while (cin >> num_query) {
		input_arr.clear();
		initial_input_arr.clear();
		tree.clear();
		
		input_arr.resize(MAX_CANDY);
		tree.resize(MAX_CANDY * 4);
		
		for (int i = 0; i < num_query; i++) {
			int a, b, c;
			cin >> a;
			if (a == 1) { //take a candy from the box
				cin >> b;
				ll current_candy_taste_rank = query(tree, 1, 0, MAX_CANDY - 1, b);
				cout << current_candy_taste_rank + 1 << "\n";
				update(tree, 1, 0, MAX_CANDY - 1, current_candy_taste_rank, -1);
				
			}
			else { // 
				cin >> b >> c;
				update(tree, 1, 0, MAX_CANDY - 1, b - 1, c);
			}
			// for (int i = 1; i <= 15; i++) {
			// 	cout << tree[i] << " ";
			// }
			// cout << "\n";
		}
		
		
		
		
	}
	
	
    

    return 0;
}