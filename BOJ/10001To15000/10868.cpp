#include <bits/stdc++.h>


using namespace std;


vector<int> input_arr;
vector<int> max_tree;
vector<int> min_tree;

const int INF = 1987654321;
int num_input;
int num_change;
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






int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	while (cin >> num_input >> num_query) {
		input_arr.clear();
		for (int i = 0; i < num_input; i++) {
			int num;
			cin >> num;
			input_arr.push_back(num);
		}
		max_tree.resize(4 * num_input);
		min_tree.resize(4 * num_input);
		InitMin(input_arr, min_tree, 1, 0, num_input - 1);
		//InitMax(input_arr, max_tree, 1, 0, num_input - 1);
		
		for (int i = 0; i < num_query; i++) {
			int from, to;
			cin >> from >> to;
			from--;
			to--;
			cout << FindMin(min_tree, 1, 0, num_input - 1, from, to) << "\n";
		}
		
		
	}
    

    return 0;
}
