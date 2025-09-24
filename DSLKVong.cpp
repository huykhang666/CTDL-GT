#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class circularLinkedList {
	private:
		Node* head;
	public:
		circularLinkedList();
		void insertFirst(int x);
		void insertLast(int x);
		void insertAt(int pos, int x);
		void deleteFirst();
		void deleteLast();
		void deleteAt(int pos);
		void printList();
};
//constructor
circularLinkedList::circularLinkedList() {
	head = NULL;	
}
//Them dau
void circularLinkedList::insertFirst(int x) {
	Node* newNode = new Node;
	newNode->data = x;
	newNode->next = NULL;
	if(!head) {
		head = newNode;
		head->next = head;
	} else {
		Node* tmp = head;
		while(tmp->next != head) {
			tmp = tmp->next;
		}
		newNode->next = head;
		tmp->next = newNode;
		head = newNode;
		
	}
}
//Them cuoi
void circularLinkedList::insertLast(int x){
	Node* newNode = new Node;
	newNode->data = x;
	newNode->next = NULL;
	if(!head) {
		head = newNode;
		head->next = head;
	} else {
		Node* tmp = head;
		while(tmp->next != head) {
			tmp = tmp->next;
		}
		tmp->next = newNode;
		newNode->next = head;
	}
}
//Them bat ki
void circularLinkedList::insertAt(int pos, int x) {
	if(pos == 0) {
		insertFirst(x);
		return;
	}
	
	Node* tmp = head;
	for(int i = 0; i< pos-1 && tmp->next != head;i++) {
		tmp = tmp->next;
	}
	Node* newNode = new Node;
	newNode->data = x;
	newNode->next = tmp->next;
	tmp->next = newNode;
}
//Xoa dau
void circularLinkedList::deleteFirst() {
	Node* tmp = head;
	if(!head) return;
	if(head->next == head) {
		delete head;
		head = NULL;
	}
	while(tmp->next != head) {
		tmp = tmp->next;
	}
	Node* a = head;
	head = head->next;
	tmp->next = head;
	delete a;
}
//Xoa cuoi
void circularLinkedList::deleteLast() {
	if(!head) return;
	if(head->next == head) {
		delete head;
		head = NULL;
	}
	
	Node* tmp = head;
	while(tmp->next->next != head) {
		tmp = tmp->next;
	}
	
	Node* a = tmp->next;
	tmp->next = head;
	delete a;
	
}
//Xoa bat ki
void circularLinkedList::deleteAt(int pos) {
	if(pos == 0) {
		deleteFirst();
		return;
	}
	
	Node* tmp = head;
	for(int i=0;i < pos-1 && tmp->next != head;i++) {
		tmp=tmp->next;
	}
	Node* a = tmp->next;
	if(a == head) return;
	tmp->next = tmp->next->next;
	delete a;
}
//In ra danh sach
void circularLinkedList::printList() {
	if (!head) {
		cout << "Danh sach rong\n"; return; 
	}
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}
int main() {
	circularLinkedList list;

    list.insertFirst(10);
    list.insertLast(20);
    list.insertLast(30);
    list.insertAt(15, 1);

    cout << "Danh sach sau khi them:\n";
    list.printList();   

    list.deleteFirst();
    list.deleteLast();
    list.deleteAt(1);

    cout << "\nDanh sach sau khi xoa:\n";
    list.printList();   

    return 0;
}