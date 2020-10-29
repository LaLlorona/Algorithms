#include <bits/stdc++.h>


using namespace std;

class Node {
public:
	Node* next = 0;
	int data;
	
	Node(int d) {
		data = d;
	}
	
	void AppendToTail(int d) {
		Node* to_add = new Node(d);
		
		Node* n = this;
		while (n->next != 0) {
			n = n->next;
		}
		n->next = to_add;
	}
	void PrintFrom() {
		Node* n = this;
		while (n != NULL) {
			cout << n->data << " ";
			cout << n << " ";
			n = n->next;
		}
		cout << "\n";
	}
	void DeleteNode(Node** head, int d) {
		Node* here = *head;
		if (here->data == d) {
			(*head) = here->next;
		}
		while (here->next != NULL) {
			if (here->next->data == d) {
				here->next = here->next->next;
			}
			here = here->next;
		}
		
	}
};



int main()
{
	Node* a = new Node(3);
	a->AppendToTail(4);
	a->AppendToTail(5);
	a->AppendToTail(6);
	a->AppendToTail(7);

	
	a->PrintFrom();
	cout << a << "\n";
	a->DeleteNode(&a, 5);
	cout << a << "\n";
	a->DeleteNode(&a, 3);
	cout << a << "\n";
	
	
	
	//a.AppendToTail(5);
	// cout << a.next->data;
	// cout << a.next->next->data;
	
	
	

    return 0;
}

