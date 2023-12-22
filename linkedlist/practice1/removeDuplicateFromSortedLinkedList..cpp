
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

void deleteDuplicatesFromSortedLinkedList(Node** head) {
	if (head == NULL) return;
	Node* curr = *head;
	while (curr->next != NULL) {
		if (curr->data == curr->next->data) {
			Node* next_next = curr->next->next;
			Node* nodeToDelete = curr->next;
			delete nodeToDelete;
			nodeToDelete = NULL;
			curr->next = next_next;
			

		}
		else {
			curr = curr->next;
		}
	}

}




void main() {
	Node* head = NULL;
	addLast(10, &head);
	addLast(10, &head);
	addLast(30, &head);
	addLast(30, &head);
	addLast(50, &head);
	addLast(50, &head);
	addLast(80, &head);
	addLast(80, &head);
	addLast(510, &head);
	printNodes(head);
	cout <<endl<< "unqiue sorted " << endl;
	deleteDuplicatesFromSortedLinkedList(&head);
	printNodes(head);

	




}


