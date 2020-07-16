#include <bits/stdc++.h>
//#include <iostream>

using namespace std;
int n;
int inorder[100001];
int postorder[100001];

int inorder_num_to_index[100001];

void PreOrder(int inorder_begin, int inorder_end, int postorder_begin, int postorder_end) {
	if (inorder_end < inorder_begin || postorder_end < postorder_begin) {
		return;
	}
	
	int root = postorder[postorder_end];
	int root_idx = inorder_num_to_index[root];
	cout << root << " ";
	PreOrder(inorder_begin, root_idx - 1, postorder_begin, postorder_begin + (root_idx - inorder_begin - 1));
	PreOrder(root_idx + 1, inorder_end, postorder_begin + root_idx - inorder_begin, postorder_end - 1);
	
}
int main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
	}
	
	for (int i = 0; i < n; i++) {
		cin >> postorder[i];
	}
	
	for (int i = 0; i < n; i++) {
		inorder_num_to_index[inorder[i]] = i;
	}
	PreOrder(0, n - 1, 0, n - 1);
	
	
	
	
	
	
	return 0;
}
