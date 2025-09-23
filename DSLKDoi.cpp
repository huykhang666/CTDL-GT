#include<iostream>
using namespace std;

struct Node {
	int data;
	struct Node* pre;
	struct Node* next;
};

class doubleLinkedList {
	private:
		Node* head;
		Node* tail;
	public:
		doubleLinkedList();
		void insertFirst(int x);
		void insertLast(int x);
		void deleteFirst();
		void deleteLast();
		void insertAt(int pos,int x);
		void print();
};

//Constructor
doubleLinkedList::doubleLinkedList() {
	head = tail = NULL;
}

//Them dau
void doubleLinkedList::insertFirst(int x) {
	Node* newNode = new Node;
	newNode->data = x;
	newNode->next = newNode->pre = NULL;
	
	newNode->next = head;
	if(!head) {
		head = tail = newNode;
	}else {
		newNode->next = head;
		head->pre = newNode;
		head = newNode;
	}
}

//Them cuoi
void doubleLinkedList::insertLast(int x) {
	Node* newNode = new Node;
	newNode->data = x;
	newNode->next = newNode->pre = NULL;
	if(!head){
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->pre = tail;
		tail = newNode;
	}
}

//Them bat ki
void doubleLinkedList::insertAt(int pos,int x) {
	if(pos == 0) {
		insertFirst(x);
		return;
	}
	
	Node* tmp = head;
	for(int i=0; i<pos-1 && tmp;i++) {
		tmp = tmp->next;
	}
	if(!tmp) {
		cout<<"\nVi tri khong hop le";
		return;
	}
	
	if(tmp == tail) {
		insertLast(x);
		return;
	}
	Node* newNode = new Node;
	newNode->data = x;
	
	newNode->next = tmp->next;
	newNode->pre = tmp;
	
	tmp->next = newNode;
	tmp->next->pre = newNode;
	
}

//Xoa dau
void doubleLinkedList::deleteFirst() {
	if(!head) {
		cout<<"Danh sach rong\n";
		return;
	}
	
	Node* tmp = head;
	if(head == tail) {
		head = tail = NULL;
	} else {
		head = head->next;
		head->pre = NULL;
	}
	delete tmp;
	
}

//Xoa cuoi
void doubleLinkedList::deleteLast() {
	if(!tail) {
		cout<<"Danh sach rong\n";
		return;
	}
	
	Node*tmp = tail;
	if(head == tail) {
		head = tail = NULL;
	} else {
		tail = tail->pre;
		tail->next = NULL;
	}
	delete tmp;
}

//In ra danh sach
void doubleLinkedList::print() {
	Node* tmp = head;
	while(tmp!= NULL) {
		cout<<tmp->data<<" ";
		tmp = tmp->next;
	}
}


int main() {
	doubleLinkedList s;
	s.insertFirst(3);
	s.insertLast(4);
	s.insertAt(2,5);
	s.deleteFirst();
	s.deleteLast();
	s.print();
}