
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<unordered_set>
using namespace std;

// cgheck if the following linked list is formatting a palindrom number or not 

// algo
// first of all split the whole linked list into two sub parts 
// then reverse one sub list and check both list are same or not if same then it is a palnidrom other wise not palindrom




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

Node* getMiddle(Node* head) {
	if (head == NULL) return NULL;
	Node* slow = head;
	Node* fast = head->next;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next;
		if (fast != NULL) fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
Node* reverseList(Node* head) {
	if (head == NULL) return head;
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
bool isPalindrom(Node* head) {
	if (head->next == NULL) return true;
	Node* middle = getMiddle(head);
	middle->next = reverseList(head);
	Node* head1 = head;
	Node* head2 = middle->next;
	while (head1 != NULL && head2 != NULL) {
		if (head1->data != head2->data) return false;
		head1 = head1->next;
		head2 = head2->next;
	}
	return true;
}




void main()
{
	Node* head = NULL;
	
	addLast(1, &head);
	addLast(2, &head);
	addLast(2, &head);
	addLast(3, &head);
	addLast(2, &head);
	addLast(2, &head);
	addLast(1, &head);
	cout << "Node list is : " << endl;
	printNodes(head);
	if (isPalindrom(head)) {
		cout << "It is Palindrom " << endl;
	}
	else {
		cout << "It is not Palindrom " << endl;
	}
}




