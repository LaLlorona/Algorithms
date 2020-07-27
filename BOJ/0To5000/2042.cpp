#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

vector<ll> input_arr;
vector<ll> tree;

int num_input;
int num_change;
int num_query;

ll init (vector<ll> &input_arr, vector<ll> &tree, int node, int start, int end) { // when the node deals with sum from start to end
	if (start == end) {
		return tree[node] = input_arr[start];
	}
	else {
		int mid = (start + end) / 2;
		return tree[node] = init(input_arr, tree, 2 * node, start, mid) + init(input_arr, tree, 2 * node + 1, mid + 1, end);
	}
}

ll sum(vector<ll> &tree, int node, int start, int end, int left, int right) {//when node covers start to end, and we want to calculate sum from left to right 
	if (end < left || right < start) {
		return 0;
	}
	else if (left <= start && end <= right) {
		return tree[node];
	}
	else {
		int mid = (start + end) / 2;
		return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
	}
}

void update(vector<ll> &tree, int node, int start, int end, int index, int diff) {//when node covers start to end, we want to change indexth item 
	if (index < start || end < index) {
		return;
	}
	tree[node] += diff;
	if (start != end) { // when this node is not leaf node 
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
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
	while (cin >> num_input >> num_change >> num_query) {
		input_arr.clear();
		for (int i = 0; i < num_input; i++) {
			ll num;
			cin >> num;
			input_arr.push_back(num);
		}
		tree.resize(4 * num_input);
		init(input_arr, tree, 1, 0, num_input - 1);
		for (int i = 0; i < num_change + num_query; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			if (a == 1) {//update b to c
				b--;
				ll diff = c - input_arr[b];
				input_arr[b] = c;
				update(tree, 1, 0, num_input - 1, b, diff);
			}
			else {//return sum from b to c
				b--;
				c--;
				cout << sum(tree, 1, 0, num_input - 1, b, c) << "\n";
			}
		}
		
	}
    

    return 0;
}

