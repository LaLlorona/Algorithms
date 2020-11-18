#include <bits/stdc++.h>


using namespace std;

int global_count = 0;

class Node {
	public:
	int data;
	Node* left;
	Node* right;
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

unordered_map<int, int> frequency;
int CountPathWithTargetSum(Node* here, int target_sum, int accumulate_sum) {
	if (here == NULL) {
		return 0;
	}
	int current_sum = accumulate_sum + here->data;
	int total_count = 0;
	if (current_sum == target_sum) {
		total_count++;
	}
	
	if (frequency.find(current_sum - target_sum) != frequency.end()) {
		total_count += frequency[current_sum - target_sum];
	}
	
	
	if (frequency.find(current_sum) == frequency.end()) {// when running sum is not in the hash map
		frequency[current_sum] = 1;
	}
	else {
		frequency[current_sum]++;
	}
	
	total_count += CountPathWithTargetSum(here->left, target_sum, current_sum);
	total_count += CountPathWithTargetSum(here->right, target_sum, current_sum);
	frequency[current_sum]--;
	return total_count;
	
}

void Traversal(Node* here, int accumulate_sum, int target_sum) {
	if (here == NULL) {
		return;
	}
	int current_sum = accumulate_sum + here -> data;
	if (current_sum == target_sum) {
		global_count++;
	}
	Traversal(here -> left, current_sum, target_sum);
	Traversal(here -> right, current_sum, target_sum);
}
void AllTraversal(Node* here, int target_sum) {
	if (here != NULL) {
		Traversal(here, 0, target_sum);
		AllTraversal(here->right, target_sum);
		AllTraversal(here->left, target_sum);
	}
	
}




int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	
	Node* node1 = new Node(5);
	Node* node2 = new Node(1);
	Node* node3 = new Node(2);
	node1->left = node2;
	node1->right = node3;
	
	Node* node4 = new Node(-6);
	Node* node5 = new Node(3);
	node2 -> left = node4;
	node2->right = node5;
	
	Node* node6 = new Node(7);
	node3->right = node6;
	
	Node* node7 = new Node(0);
	node4->left = node7;
	
	Node* node8 = new Node(-4);
	Node* node9 = new Node(1);
	node5->left = node8;
	node5->right = node9;
	
	
	Node* node10 = new Node(-5);
	Node* node11 = new Node(5);
	node8->left = node10;
	node8->right = node11;
	
	Node* node12 = new Node(14);
	Node* node13 = new Node(-7);
	
	node6->left = node12;
	node6->right = node13;
	
	Node* node14 = new Node(-7);
	node13 -> left = node14;
	
	// Node* node1 = new Node(5);
	// Node* node2 = new Node(-5);
	// Node* node3 = new Node(0);
	// Node* node4 = new Node(0);
	
	// node1->right = node2;
	// node2->right = node3;
	// node3->right = node4;
	
	
	cout << CountPathWithTargetSum(node1, 0, 0) << "\n";
	AllTraversal(node1, 0);
	cout << global_count << "\n";
	
	
	
	
	
    

    return 0;
}

