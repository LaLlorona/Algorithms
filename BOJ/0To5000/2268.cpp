#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

vector<ll> input_arr, tree;
ll num_input, num_query;

ll InitTree(vector<ll> &input_arr, vector<ll> &tree, ll node, ll start, ll end) {
	if (start == end) {
		return tree[node] = input_arr[start];
	}
	else {
		ll mid = (start + end) / 2;
		return tree[node] = InitTree(input_arr, tree, 2 * node, start, mid) + InitTree(input_arr, tree, 2 * node + 1, mid + 1, end);
	}
}

ll SumTree(vector<ll> &tree, ll node, ll start, ll end, ll from, ll to) {
	if (end < from || start > to) { // when node does not cover any range from from to to 
		return 0;
	}
	else if (from <= start && end <= to) { // when node is included in from from to 
		return tree[node];
	}
	else { //only some portion of node and range is overlapping
		ll mid = (start + end) / 2;
		return SumTree(tree, 2 * node, start, mid, from, to) + SumTree(tree, 2 * node + 1, mid + 1, end, from, to);
	}
}

ll ModifyTree(vector<ll> &tree, ll node, ll start, ll end, ll index, ll diff) {
	
	if (start == end && start == index) {
		return tree[node] += diff;
	}
	else if (start > index || end < index) { // when index is not included where node covers
		return tree[node];
	}
	else {
		ll mid = (start + end) / 2;
		return tree[node] = ModifyTree(tree, node * 2, start, mid, index, diff) + ModifyTree(tree, node * 2 + 1, mid + 1, end, index, diff);
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
	
	cin >> num_input >> num_query;
	input_arr.clear();
	tree.clear();
	input_arr.resize(num_input);
	tree.resize(num_input * 4);
		
	for (int i = 0; i < num_query; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		b--;
		if (a == 0) {//sum
			c--;
			if (b > c) {
				swap(b, c);
			}
			cout << SumTree(tree, 1, 0, num_input - 1, b, c) << "\n";
		}
		else {//modify
			ll before_change = input_arr[b];
			input_arr[b] = c;
			ModifyTree(tree, 1, 0, num_input - 1, b, c - before_change);
		}
			// for (int j = 1; j < num_input * 4; j++) {
			// 	cout << tree[j] << " ";
			// }
			// cout << "\n";
	}
	
    

    return 0;
}

