#include <bits/stdc++.h>


using namespace std;

class MyStackNode {
	public:
	int data;
	MyStackNode* next;
	MyStackNode(int d) {
		data = d;
	}
};

class MyStack {
	public:
	MyStackNode* top_element = NULL;
	void Pop() {
		if (top_element == NULL) {
			cout << "no element to pop\n";
		}
		else {
			top_element = top_element->next;
		}
	}
	void Push(int d) {
		MyStackNode* new_node = new MyStackNode(d);
		new_node->next = top_element;
		top_element = new_node;
	}
	int Top() {
		if (top_element == NULL) {
			cout << "no element to pop\n";
			return -987564321;
		}
		else {
			return top_element->data;
		}
	}
	bool IsEmpty() {
		return top_element == NULL;
	}
};





int main()
{
	
	MyStack new_stack;
	new_stack.Push(3);
	new_stack.Push(4);
	new_stack.Push(5);
	while (!new_stack.IsEmpty()) {
		cout << new_stack.Top() << "\n";
		new_stack.Pop();
	}
    

    return 0;
}


