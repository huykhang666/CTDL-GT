#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class linkedList {
	private:
		Node* head;
	public:
		linkedList();
		void insertFirst(int x);
		void deleteFirst();
		void insertLast(int x);
		void deleteLast();
		void insertAt(int x,int pos);
		void deleteAt(int pos);
		void printList();
};

linkedList::linkedList() {
	head = NULL;
}

//Chen dau
void linkedList::insertFirst(int x) {
	Node* newNode = new Node;
	newNode->data = x;
	newNode->next = head;
	head = newNode;
	
}

//Xoa dau
void linkedList::deleteFirst() {
	Node* a = head;
	head = head->next;
	delete(a);
}

//Chen cuoi
void linkedList::insertLast(int x) {
	Node* newNode = new Node;
	newNode->data = x;
	newNode->next = NULL;
	if(head == NULL) {
		head = newNode;
		return;
	}
	
	Node* tmp = head;
	while(tmp->next != NULL) {
		tmp = tmp->next;
	}
	
	tmp->next = newNode;
}

//Xoa cuoi
void linkedList::deleteLast() {
	if(head == NULL) {
		cout<<"Danh sach rong";
		return;
	}
	if(head->next == NULL) {
		delete head;
		head = NULL;
	} else {
		Node* tmp = head;
		while(tmp->next->next != NULL) {
			tmp = tmp->next;
		}
		Node* a = tmp->next;
		tmp->next = NULL;
		delete a;
	}
}

//Them bat ki
void linkedList::insertAt(int x,int pos){
	if(pos == 0) {
		insertFirst(x);
		return;
	}
	
	Node* tmp = head;
	for(int i=0;tmp && i < pos - 1;i++) {
		tmp = tmp->next;
	}
	if(!tmp) {
		cout<<"Vi tri khong hop le \n";
		return;
	}
	
	Node* newNode = new Node;
	newNode->data = x;
	newNode->next = tmp->next;
	tmp->next = newNode;
}

//Xoa bat ki
void linkedList::deleteAt(int pos){
	if(!head) {
		cout<<"Danh sach rong \n";
		return;
	}
	
	if(pos == 0) {
		deleteFirst();
		return;
	}
	
	Node* tmp = head;
	for(int i=0; tmp->next && i < pos -1;i++) {
		tmp = tmp->next;
	}
	
	if(!tmp->next) {
		cout<<"Vi tri khong hop le";
		return;
	}
	
	Node* a = tmp->next;
	tmp->next = a->next;
	delete a;
}

//In danh sach
void linkedList::printList(){
	Node* tmp = head;
	while(tmp != NULL) {
		cout<<tmp->data<<" ";
		tmp = tmp->next;
	}
}

int main() {
	linkedList s;
	s.insertFirst(5);
	s.insertFirst(5);
	s.insertFirst(8);
	s.insertLast(7);	
	s.insertLast(7);
	s.insertAt(3, 2);	
	s.deleteFirst();
	s.deleteLast();
	s.deleteAt(2);
	s.printList();
	return 0;
}