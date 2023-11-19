
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
}


void mergeTwoSortedLinkedList(Node **first,Node **second) {
	if (*first == NULL || *second == NULL) return;
	Node* curr1 = *first;
	Node* curr2 = *second;
	Node* next1 = (*first)->next;
	Node* next2 = (*second)->next;
	while (next1 != NULL && curr2 != NULL) {
		if ((curr2->data >= curr1->data) && (curr2->data <= next1->data)) {
			curr1->next = curr2;
			next2 = curr2->next;
			curr2->next = next1;
			curr1 = curr2;
			curr2 = next2;

		}
		else {
			curr1 = next1;
			next1 = next1->next;
			if (next1 == NULL) {
				curr1->next = curr2;
				return;
			}
		}
	}

}



void main() {
	Node* first = NULL;
	Node* second = NULL;
	addLast(10, &first);
	addLast(20, &second);
	addLast(30, &first);
	addLast(40, &first);
	addLast(25, &second);
	addLast(45, &first);
	addLast(50, &first);
	addLast(30, &second);
	addLast(51, &first);
	cout <<endl<< "First List is : " << endl;
	printNodes(first);
	cout <<endl<< "second List is : " << endl;
	printNodes(second);
	mergeTwoSortedLinkedList(&first, &second);
	cout << endl << "Merge List is :" << endl;
	printNodes(first);
	
	
}


