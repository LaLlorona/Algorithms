#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef pair<int, int> pll;
const int MAX = 500001;
const int INF = 987654321;

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

int InitMax (vector<int> &input_arr, vector<int> &tree, int node, int start, int end) { // when the node deals with sum from start to end
	if (start == end) {
		return tree[node] = input_arr[start];
	}
	else {
		int mid = (start + end) / 2;
		return tree[node] = max(InitMax(input_arr, tree, 2 * node, start, mid), InitMax(input_arr, tree, 2 * node + 1, mid + 1, end));
	}
}

int InitMin (vector<int> &input_arr, vector<int> &tree, int node, int start, int end) { // when the node deals with sum from start to end
	if (start == end) {
		return tree[node] = input_arr[start];
	}
	else {
		int mid = (start + end) / 2;
		return tree[node] = min(InitMin(input_arr, tree, 2 * node, start, mid), InitMin(input_arr, tree, 2 * node + 1, mid + 1, end));
	}
}

int FindMax(vector<int> &tree, int node, int start, int end, int left, int right) {//when node covers start to end, and we want to calculate mult from left to right 
	if (end < left || right < start) {
		return -INF;
	}
	else if (left <= start && end <= right) {
		return tree[node];
	}
	else {
		int mid = (start + end) / 2;
		return max(FindMax(tree, node * 2, start, mid, left, right), FindMax(tree, node * 2 + 1, mid + 1, end, left, right));
	}
}


int FindMin(vector<int> &tree, int node, int start, int end, int left, int right) {//when node covers start to end, and we want to calculate mult from left to right 
	if (end < left || right < start) {
		return INF;
	}
	else if (left <= start && end <= right) {
		return tree[node];
	}
	else {
		int mid = (start + end) / 2;
		return min(FindMin(tree, node * 2, start, mid, left, right), FindMin(tree, node * 2 + 1, mid + 1, end, left, right));
	}
}

int UpdateMin(vector<int> &tree, int node, int start, int end, int index, int new_val) { // change indexth item to new val
	if (index < start || end < index) {
		return tree[node];
	}
	else if (start == end) {
		return tree[node] = new_val;
	}
	else {
		int mid = (start + end) / 2;
		return tree[node] = min(UpdateMin(tree, 2 * node, start, mid, index, new_val), UpdateMin(tree, 2 * node + 1, mid + 1, end, index, new_val));
	}
} 

int UpdateMax(vector<int> &tree, int node, int start, int end, int index, int new_val) { // change indexth item to new val
	if (index < start || end < index) {
		return tree[node];
	}
	else if (start == end) {
		return tree[node] = new_val;
	}
	else {
		int mid = (start + end) / 2;
		return tree[node] = max(UpdateMax(tree, 2 * node, start, mid, index, new_val), UpdateMax(tree, 2 * node + 1, mid + 1, end, index, new_val));
	}
} 

struct Rank {
	int first;
	int second;
	int third;
};
vector<Rank> ranks;
vector<int> input_arr;
vector<int> min_tree;
int num_input;


bool comp(Rank a, Rank b) {
	return a.first < b.first;
}


int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
		
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	while (cin >> num_input) {
		input_arr.clear();
		min_tree.clear();
		ranks.clear();
		
		input_arr.resize(MAX, INF);
		min_tree.resize(MAX * 4, INF);
		ranks.resize(MAX);
		for (int i = 0; i < num_input; i++) {
			int num;
			cin >> num;
			num--;
			ranks[num].first = i;
		}
		for (int i = 0; i < num_input; i++) {
			int num;
			cin >> num;
			num--;
			ranks[num].second = i;
		}
		for (int i = 0; i < num_input; i++) {
			int num;
			cin >> num;
			num--;
			ranks[num].third = i;
		}
		
		sort(ranks.begin(), ranks.begin() + num_input, comp);
		
		int num_great_students = 0;
		// for (int i = 0; i < num_input; i++) {
		// 	cout << ranks[i].first << " " << ranks[i].second << " " << ranks[i].third << "\n";
		// }
		for (int i = 0; i < num_input; i++) {
			int previous_rank_minimum = FindMin(min_tree, 1, 0, num_input - 1, 0, ranks[i].second);
			if (previous_rank_minimum > ranks[i].third) {
				num_great_students++;
				//cout << i << " ";
			}
			input_arr[ranks[i].second] = ranks[i].third;
			UpdateMin(min_tree, 1, 0, num_input - 1, ranks[i].second, ranks[i].third);
		}
		cout << num_great_students << "\n";
	}
    

    return 0;
}
