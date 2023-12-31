
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



void insertAtTail(Node** tail, Node* curr) {
	(*tail)->next = curr;
	*tail = curr;
}

Node* sortZeroOneTwo(Node* head) {
	Node* zeroHead = new Node(-1);
	Node* oneHead = new Node(-1);
	Node* twoHead = new Node(-1);
	Node* zeroTail = zeroHead;
	Node* oneTail = oneHead;
	Node* twoTail = twoHead;
	Node* curr = head;
	while (curr != NULL) {
		int value = curr->data;
		if (value == 0)
			insertAtTail(&zeroTail, curr);
		else if (value == 1)
			insertAtTail(&oneTail, curr);
		else if (value == 2)
			insertAtTail(&twoTail, curr);
		curr = curr->next;
	}
	// merge 3 sub list 
	// 1st list is not empty
	if (oneHead->next != NULL) {
		zeroTail->next = oneHead->next;
	}
	else {
		zeroTail->next = twoHead->next;
	}
	oneTail->next = twoHead->next;
	twoTail->next = NULL; 

	//set up head 
	head = zeroHead->next;
	//delete dummy head
	delete zeroHead;
	delete twoHead;
	delete oneHead;
	return head;

}



void main()
{
	Node* head = NULL;
	addLast(0, &head);
	addLast(2, &head);
	addLast(0, &head);
	addLast(1, &head);
	addLast(0, &head);
	addLast(2, &head);
	addLast(1, &head);
	addLast(2, &head);
	addLast(0, &head);
	printNodes(head);
	head = sortZeroOneTwo(head);
	printNodes(head);
}




