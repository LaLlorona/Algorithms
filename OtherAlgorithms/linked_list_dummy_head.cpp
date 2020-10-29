#include <bits/stdc++.h>


using namespace std;

class Node {
public:
	Node* next = 0;
	int data;
	
	Node(int d) {
		data = d;
	}
};

class LinkedList {
public:
	Node* dummy_head;
	Node* dummy_tail;
	
	LinkedList() {
		dummy_head = new Node(0);
		dummy_tail = new Node(0);
		dummy_head->next = dummy_tail;
	}
	
	void InsertTail(int d) {
		Node* to_add = new Node(d);
		Node* here = dummy_head;
		while (here->next != dummy_tail) {
			here = here->next;
		}
		to_add->next = here->next;
		here->next = to_add;
		
	}
	void PrintAll() {
		Node* here = dummy_head->next;
		while (here!= dummy_tail) {
			cout << here->data << " ";
			here = here->next;
		}
		cout << "\n";
	}
	
	void Remove(int d) {
		Node* here = dummy_head;
		while (here->next != dummy_tail) {
			if (here->next->data == d) {
				here->next = here->next->next;
				break;
			}
			here = here->next;
		}
	}
};






int main()
{
	
	LinkedList* a = new LinkedList();
	LinkedList* b = new LinkedList();
	a->InsertTail(3);
	a->InsertTail(4);
	a->InsertTail(5);
	a->InsertTail(6);
	a->InsertTail(7);
	a->InsertTail(8);
	a->InsertTail(9);
	a->InsertTail(10);
	
	b->InsertTail(3);
	a->Remove(3);
	a->Remove(6);
	a->PrintAll();
	b->PrintAll();
	
	
	//a.AppendToTail(5);
	// cout << a.next->data;
	// cout << a.next->next->data;
	
	
	

    return 0;
}

