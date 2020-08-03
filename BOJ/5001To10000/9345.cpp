#include <bits/stdc++.h>


using namespace std;


vector<int> input_arr;
vector<int> max_tree;
vector<int> min_tree;

const int INF = 1987654321;
int num_input;
int num_query;

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
		cin >> num_input >> num_query;
		input_arr.clear();
		max_tree.clear();
		min_tree.clear();
		
		input_arr.resize(num_input);
		max_tree.resize(num_input * 4);
		min_tree.resize(num_input * 4);
		
		for (int i = 0; i < num_input; i++) {
			input_arr[i] = i;
		}
		InitMax(input_arr, max_tree, 1, 0, num_input - 1);
		InitMin(input_arr, min_tree, 1, 0, num_input - 1);
		
		for (int i = 0; i < num_query; i++) {
			int question, from, to;
			cin >> question >> from >> to;
			if (question == 0){ // change from and to
				int initial_from = input_arr[from];
				int initial_to = input_arr[to];
				input_arr[from] = initial_to;
				input_arr[to] = initial_from;
				UpdateMin(min_tree, 1, 0 , num_input - 1, from, initial_to);
				UpdateMin(min_tree, 1, 0 , num_input - 1, to, initial_from);
				UpdateMax(max_tree, 1, 0 , num_input - 1, from, initial_to);
				UpdateMax(max_tree, 1, 0 , num_input - 1, to, initial_from);
				
			
			}
			else {
				int min_from_to = FindMin(min_tree, 1, 0, num_input - 1, from, to);
				int max_from_to = FindMax(max_tree, 1, 0, num_input - 1, from, to);
				//cout << from << " " << min_from_to << " " << to << " " << max_from_to << " ";
				if (from == min_from_to && to == max_from_to) {
					cout << "YES\n";
				}
				else {
					cout << "NO\n";
				}
				
			}
		}
		
	}
	
	
    

    return 0;
}