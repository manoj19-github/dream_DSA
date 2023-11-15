
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;
	Node(int d = 0) {
		this->data = d;
		this->next = NULL;
		this->prev = NULL;
	}
};

Node* addFirst(int data,Node* head) {
	Node* newNode = new Node(data);
	if (head == NULL) {
		head = newNode;
		return head;
	}
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
	return newNode;
}
void addLast(int data, Node** head) {
	Node* newNode = new Node(data);
	if (head == NULL) {
		*head = newNode;
		return;
	}
	Node* temp = *head;
	while (temp->next != NULL) temp = temp->next;
	temp->next = newNode;
	newNode->prev = temp;
}


void printNodes(Node* head) {
	Node* temp = NULL;
	temp = head;
	cout << endl << "Nodes : " << endl;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	temp = NULL;
	delete temp;
}
 Node *reverseLinkedList(Node* head) {
	Node* ptr1 = head;
	Node* ptr2 = ptr1->next;
	ptr1->next = NULL;
	ptr1->prev = ptr2;

	while (ptr2 != NULL) {
		ptr2->prev = ptr2->next;
		ptr2->next = ptr1;
		ptr1 = ptr2;
		ptr2 = ptr2->prev;
	}
	head = ptr1;
	return head;


}


void main() {
	Node* head = NULL;
	head = addFirst(10, head);
	addLast(30, &head);
	addLast(40, &head);
	addLast(70, &head);
	printNodes(head);
	head = reverseLinkedList(head);
	printNodes(head);
}


