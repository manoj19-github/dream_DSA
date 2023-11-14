
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int d = 0) {
		this->data = d;
		this->next = NULL;
	}
};


void addLast(int data, Node** head) {
	Node* newNode = new Node(data);
	Node* temp = *head;
	if (*head == NULL) {
		*head = newNode;
		return;
	}
	while (temp->next != NULL) temp = temp->next;
	temp->next = newNode;
}
Node* addFirst(int data, Node* head) {
	Node* newNode = new Node(data);

	newNode->next = head;
	head = newNode;
	return head;

}

void addAtPos(int data, int pos, Node** head) {
	if (*head == NULL || pos <= 1) {
		*head = addFirst(data, *head);
	}
	int count = 0;
	Node* temp = *head;
	Node* temp2 = *head;

	while (count < pos - 1 && temp != NULL) {

		temp2 = temp;
		temp = temp->next;
		count++;
	}
	Node* newNode = new Node(data);
	newNode->next = temp;
	temp2->next = newNode;


}

Node* deleteFirst(Node* head) {
	if (head == NULL) return head;
	Node* newHead = NULL;
	if (head->next != NULL) newHead = head->next;
	head = NULL;
	delete head;
	return newHead;
}
void deleteLast(Node* head) {
	if (head == NULL) return;
	if (head->next == NULL) {
		head = NULL;
		delete head;
		return;
	}
	Node* temp = head;
	Node* temp2 = head;
	while (temp->next != NULL) {
		temp2 = temp;
		temp = temp->next;
	}
	temp2->next = NULL;
	temp = NULL;
	delete temp;
}

void deletePos(int pos, Node* head) {
	Node* temp = head;
	Node* temp2 = head;
	int count = 0;
	while (count < pos - 1 && temp != NULL) {
		temp2 = temp;
		temp = temp->next;
		count++;
	}
	temp2->next = temp->next;
	temp = NULL;
	delete temp;

}


void printNodes(Node* head) {
	Node* temp = NULL;
	temp = head;
	cout << endl << "Nodes : " << endl << endl;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}


	temp = NULL;
	delete temp;
}

Node* deleteAllNode(Node* head) {
	Node* temp = head;
	while (temp != NULL) {

		temp = temp->next;
		head = NULL;
		delete head;
		head = temp;
	}
	temp = NULL;
	delete temp;
	return head;

}

void main() {
	Node* head = NULL;
	head = addFirst(10, head);
	head = addFirst(20, head);
	head = addFirst(30, head);
	head = addFirst(230, head);
	head = addFirst(130, head);
	head = addFirst(530, head);
	head = addFirst(40, head);

	addLast(50, &head);
	addAtPos(25, 3, &head);
	printNodes(head);
	head = deleteFirst(head);
	cout << endl;
	printNodes(head);

	deleteLast(head);
	deletePos(3, head);

	cout << endl;
	printNodes(head);
	head = deleteAllNode(head);
	cout << endl << "All Node delete" << endl;
	printNodes(head);



}


