#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

vector<ll> input_arr;
vector<ll> tree;
vector<ll> current_position;


int num_input;
int num_query;

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
	cin >> num_testcase;
	while (num_testcase--) {
		input_arr.clear();
		tree.clear();
		current_position.clear();
		
		cin >> num_input >> num_query;
		
		current_position.resize(num_input);
		input_arr.resize(num_input + num_query);
		tree.resize(4 * (num_input + num_query));
		
		//cout << tree[1] << "\n";
		for (int i = 0; i < num_input; i++) {
			input_arr[i + num_query] = 1;
			current_position[i] = i + num_query;
		}
		init(input_arr, tree, 1, 0, num_input + num_query - 1);
		for (int i = 0; i < num_query; i++) {
			int movie_to_watch;
			cin >> movie_to_watch;
			movie_to_watch--;
			
			int here = current_position[movie_to_watch];
			cout << sum(tree, 1, 0, num_input + num_query - 1, 0, here - 1) << " ";
			
			input_arr[num_query - 1 - i] = 1;
			input_arr[here] = 0;
			
			update(tree, 1, 0, num_input + num_query - 1, num_query - 1 - i, 1);
			update(tree, 1, 0, num_input + num_query - 1, here, -1);
			
			current_position[movie_to_watch] = num_query - 1 - i;
			
		}
		cout << "\n";
		
		
		
	}
    

    return 0;
}

