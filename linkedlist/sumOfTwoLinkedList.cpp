
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


Node* reverse(Node* head) {
	Node* curr = head;
	Node* prev = NULL;
	Node* next = NULL;
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

Node* addTwoList(Node* head1, Node* head2) {
	int carry = 0;
	Node* ansHead = NULL;
	while (head1 != NULL || head2 != NULL || carry != 0) {
		int val1 = 0, val2 = 0;
		if (head1 != NULL) {
			val1 = head1->data;
		}
		if (head2 != NULL) {
			val2 = head2->data;
		}
		int sum = carry + val1 + val2;
		int digit = sum % 10;
		addLast(digit, &ansHead);
		carry = sum / 10;
		if (head1 != NULL)
			head1 = head1->next;
		if (head2 != NULL)
			head2 = head2->next;
	}
	return ansHead;

}

// 4239 + 594 = 4833
void main() {
	Node* head1 = NULL;
	Node* head2 = NULL;
	addLast(4,&head1);
	addLast(2, &head1);
	addLast(3, &head1);
	addLast(9, &head1);
	addLast(5, &head2);
	addLast(9, &head2);
	addLast(4, &head2);
	head1 = reverse(head1);
	head2 = reverse(head2);
	Node* result = addTwoList(head1, head2);
	result = reverse(result);
	printNodes(result);
}


