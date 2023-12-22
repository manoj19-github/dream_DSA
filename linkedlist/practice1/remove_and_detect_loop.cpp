
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
	cout << endl << endl;
}



bool isCircular(Node* head) {
	if (head == NULL) return false;
	Node* temp = head->next;
	while (temp != NULL && temp != head) temp = temp->next;
	return temp == head;
}

Node* floyedDetectLoop(Node* head) {
	if (head == NULL) return head;
	Node* fast = head;
	Node* slow = head;
	cout << endl<<"yes" << endl;
	while (fast != NULL && slow != NULL) {
		fast = fast->next;
		if (fast!= NULL) fast = fast->next;
		cout << endl << "yes33" << endl;
		slow = slow->next;
		if (fast == slow) {
			cout << endl << "Loop is presented : " << slow->data << endl;
			return slow;
		}
		
	}
	return NULL;
}
Node* getStrtingPointLoop(Node* head) {
	cout << endl << "YUES" << endl;
	if (head == NULL) return NULL;
	Node* intersection = floyedDetectLoop(head);
	
	if (intersection == NULL) return NULL;
	cout << "yes" << endl << intersection->data << endl;
	Node* slow = head;
	while (slow != intersection) {
		slow = slow->next;
		intersection = intersection->next;
	}
	cout << "yes" << endl;

	return slow;
}

void removeLoop(Node* head) {
	if (head == NULL) return;
	Node* startOfLoop = getStrtingPointLoop(head);
	if (startOfLoop == NULL) return;
	cout << "yes" << endl << startOfLoop->data << endl;
	Node* temp = startOfLoop;
	while (temp->next != startOfLoop) temp = temp->next;
	temp->next =NULL ;

}


void main() {
	Node* head = NULL;
	addLast(50, &head);
	addLast(10, &head);
	addLast(20, &head);
	addLast(30, &head);
	addLast(40, &head);
	addLast(60, &head);
	addLast(80, &head);
	addLast(90, &head);
	addLast(510, &head);
	head->next->next->next->next->next->next->next->next->next = head;

	if (isCircular(head)) {
		cout << endl << "Circle is presented"<<endl;
	}
	else {
		cout << endl << "Circle is not presented" << endl;
	}


	
	 removeLoop(head);
	if (isCircular(head)) {
		cout << endl << "Circle is presented" << endl;
	}
	else {
		cout << endl << "Circle is not presented" << endl;
	}
	printNodes(head);

	




}


