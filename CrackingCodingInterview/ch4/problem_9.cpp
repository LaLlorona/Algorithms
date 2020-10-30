#include <bits/stdc++.h>


using namespace std;

class Node {
	public:
	Node* left;
	Node* right;
	int data;
	Node(int d) {
		left = NULL;
		right = NULL;
		data = d;
	}
};

vector<int> temp_array;
void Weave(vector<int>& arr1, vector<int>& arr2, vector<vector<int> >& result, int p1, int p2) {
	if (p1 == arr1.size() && p2 == arr2.size()) {
		result.push_back(temp_array);
	}
	if (p1 < arr1.size()) {
		temp_array.push_back(arr1[p1]);
		Weave(arr1, arr2, result, p1 + 1, p2);
		temp_array.pop_back();
	} 
	if (p2 < arr2.size()) {
		temp_array.push_back(arr2[p2]);
		Weave(arr1, arr2, result, p1, p2 + 1);
		temp_array.pop_back();
	}
}

vector<vector<int> > FindAllSeq(Node* here) {
	if (here == NULL) {
		vector<int> seq;
		vector<vector<int> > v;
		v.push_back(seq);
		return v;
	}
	else if (here -> left == NULL && here -> right == NULL) {
		vector<int> seq;
		seq.push_back(here -> data);
		vector<vector<int> > v;
		v.push_back(seq);
		return v;
	}
	else {
		vector<vector<int> > result_seq, left_seq, right_seq;
		left_seq = FindAllSeq(here -> left);
		right_seq = FindAllSeq(here -> right);
		for (int i = 0; i < left_seq.size(); i++) {
			for (int j = 0; j < right_seq.size(); j++) {
				Weave(left_seq[i], right_seq[j], result_seq, 0, 0);
			}
		}
		for (int i = 0; i < result_seq.size(); i++) {
			result_seq[i].insert(result_seq[i].begin(), here -> data);
		}
		return result_seq;
		
	}
}







int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	Node* node1 = new Node(20);
	
	Node* node2 = new Node(10);
	Node* node3 = new Node(25);
	node1->left = node2;
	node1->right = node3;
	
	Node* node4 = new Node(5);
	Node* node5 = new Node(15);
	node2->left = node4;
	node2->right = node5;
	
	Node* node6 = new Node(24);
	Node* node7 = new Node(26);
	node3->left = node6;
	node3->right = node7;
	
	vector<vector<int> > BST_sequence = FindAllSeq(node1);
	for (int i = 0; i < BST_sequence.size(); i++) {
		for (int j = 0; j < BST_sequence[i].size(); j++) {
			cout << BST_sequence[i][j] << " ";
		}
		cout << "\n";
	}
	
	
	
	
	

    return 0;
}

