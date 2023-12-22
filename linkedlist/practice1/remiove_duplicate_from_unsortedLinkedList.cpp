
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<unordered_set>
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



void deleteDuplicatesFronUnSortedLinkedList(Node** head) {
	if (*head == NULL) return;
	Node* curr = *head;
	Node* prev = NULL;
	unordered_set<int>seen;
	while(curr!=NULL){
		if (seen.find(curr->data) != seen.end()) {
			prev->next = curr->next;
			delete(curr);
			curr = NULL;

		}
		else {
			seen.insert(curr->data);
			prev = curr;
		}
		curr = prev->next;

	}
}




void main() {
	Node* head = NULL;
	addLast(10, &head);
	addLast(10, &head);
	addLast(40, &head);
	addLast(10, &head);
	addLast(90, &head);
	addLast(20, &head);
	addLast(80, &head);
	addLast(10, &head);
	addLast(20, &head);
	printNodes(head);
	cout <<endl<< "unqiue sorted " << endl;
	deleteDuplicatesFronUnSortedLinkedList(&head);
	printNodes(head);

	




}


