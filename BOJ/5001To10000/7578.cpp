#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

vector<ll> input_arr;
vector<ll> tree;
int num_input;
int first_layer[1000010];
int second_layer[1000010];

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
	// std::ios_base::sync_with_stdio(false); 
	// std::cin.tie(NULL); 
	// std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	while (cin >> num_input) {
		ll ans = 0;
		for (int i = 0; i < num_input; i++) {
			int num;
			cin >> num;
			first_layer[num]  = i;
		}
		for (int i = 0; i < num_input; i++) {
			int num;
			cin >> num;
			second_layer[i] = first_layer[num]; // second layer saves index of the same machine on the first layer
		}
		
		input_arr.resize(num_input);
		tree.resize(4 * num_input);
		for (int i = 0; i < num_input; i++) {
			int machine_on_first_layer = second_layer[i];
			ans += sum(tree, 1, 0, num_input - 1, machine_on_first_layer, num_input - 1);
			input_arr[machine_on_first_layer] = 1;
			update(tree, 1, 0, num_input - 1, machine_on_first_layer, 1);
		}
		cout << ans << "\n";
		
		
	}
    

    return 0;
}

