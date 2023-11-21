
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

// Detect  loop using floyed alogrithm

Node* floyedDetectLoop(Node* head) {
	Node* slow = head;
	Node* fast = head;
	while (fast != NULL && slow != NULL) {
		fast = fast->next;
		if (fast->next != NULL) {
			fast = fast->next;
		}
		slow = slow->next;
		if (slow == fast) return slow;

	}
	return NULL;
}


// get starting node where loop is starting 
Node* getStartingLoop(Node* head) {
	if (head == NULL) return NULL;
	Node* intersection = floyedDetectLoop(head);
	if (intersection == NULL) return NULL;
	Node* slow = head;
	while (slow != intersection) {
		slow = slow->next;
		intersection = intersection->next;

	}
	cout << endl << "loop is removed" << endl;
	return slow;
}


// remove loop from linked list 
Node* removeLoop(Node* head) {
	if (head == NULL) return head;
	Node* startingOfLoop = getStartingLoop(head);
	if (startingOfLoop == NULL) return head;
	Node* temp = startingOfLoop;
	while (temp->next != startingOfLoop) {
		temp = temp->next;
	}
	temp->next = NULL;
	return head;
}

Node* getTailNode(Node* head) {
	if (head == NULL) return head;
	Node* temp = head;
	while (temp->next != NULL) temp = temp->next;
	return temp;
}



void main() {
	Node* head = NULL;
	addLast(1,&head);
	addLast(5,&head);
	addLast(8, &head);
    addLast(9, &head);
	addLast(24, &head);
	addLast(12, &head);
	Node* tail = getTailNode(head);
	tail->next = head->next->next->next;

	if (floyedDetectLoop(head)!= NULL) {
		cout << endl << "Yes Loop is Present" << endl;
	}
	else {
		cout << endl << "No Loop is  Present" << endl;
	}
	cout << endl << getStartingLoop(head)->data << " is starting point of loop" << endl;
	head = removeLoop(head);
	printNodes(head);
}


