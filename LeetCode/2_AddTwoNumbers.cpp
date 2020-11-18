#include <bits/stdc++.h>


using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int GetLength(ListNode* head) {
	int num_node = 0;
	while (head != nullptr) {
		num_node++;
		head = head->next;
	}
	return num_node;
}

void AppendZero(ListNode* node, int len) {
	ListNode* here = node;
	while (here->next != nullptr) {
		here = here->next;
	}
	for (int i = 0; i < len; i++) {
		ListNode* to_add = new ListNode(0);
		here->next = to_add;
		here = here->next;
	}
}

void PrintAll(ListNode* node) {
	while (node != nullptr) {
		cout << node->val;
		node = node->next;
	}
}

void AddTail(ListNode* node, int val) {
	while (node->next != nullptr) {
		node = node->next;
	}
	node -> next = new ListNode(val);
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	//assume that l1 is always same or longer than l2
	ListNode* result = new ListNode();
	ListNode* here = result;
	int len_l1 = GetLength(l1);
	int len_l2 = GetLength(l2);
	if (len_l2 > len_l1) {
		AppendZero(l1, len_l2 - len_l1);
	}
	else {
		AppendZero(l2, len_l1 - len_l2);
	}
	int carry = (l1->val + l2->val) / 10;
	result->val = (l1->val + l2->val) % 10;
	l1 = l1->next;
	l2 = l2->next;
	while (l1 != nullptr) {
		int sum_node = carry + l1->val + l2->val;
		ListNode* to_add = new ListNode((sum_node) % 10);
		here -> next = to_add;
		here = here -> next;
		carry = sum_node / 10;
		l1 = l1->next;
		l2 = l2->next;
	}
	if (carry == 1) {
		here -> next = new ListNode(carry);
	}
	return result;
}





int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	
	ListNode* first = new ListNode(9);
	ListNode* second = new ListNode(9);
	for (int i = 0; i < 3; i++) {
		AddTail(first, 9);
	}
	for (int i = 0; i < 6; i++) {
		AddTail(second, 9);
	}
	ListNode* result = addTwoNumbers(first, second);
	PrintAll(result);
    

    return 0;
}

