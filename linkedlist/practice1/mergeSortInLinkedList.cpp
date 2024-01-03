
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




Node* getMid(Node* head) {
	Node* slow = head;
	Node* fast = head->next;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next;
		if (fast != NULL) fast = fast->next;
	}
	return slow;

}

Node* mergeList(Node* left, Node* right) {
	if (left == NULL) return right;
	if (right == NULL) return left;
	Node* ans = new Node(-1);
	Node* temp = ans;
	while (left != NULL && right != NULL) {
		if (left->data < right->data) {
			temp->next = left;
			temp = left;
			left = left->next;
		}
		else {
			temp->next = right;
			temp = right;
			right = right->next;
		}
	}
	while (right != NULL) {
		temp->next = right;
		temp = right;
		right = right->next;

	}
	while (left != NULL) {
		temp->next = left;
		temp = left;
		left = left->next;

	}
	ans = ans->next;
	return ans;


}

Node* mergeSort(Node* head) {
	if (head == NULL || head->next == NULL) return head;
	// break linked list into two halves
	Node* middle = getMid(head);
	Node* left = head;
	Node* right = middle->next;
	middle->next = NULL;
	// recursive calls to sort both halves
	left = mergeSort(left);
	right = mergeSort(right);

	// merge both halves
	Node* result = mergeList(left, right);
	return result;




}




void main()
{
	Node* head1 = NULL;


	
	addLast(3, &head1);
	addLast(4, &head1);
	addLast(7, &head1);
	addLast(1, &head1);
	addLast(2, &head1);
	addLast(3, &head1);
	addLast(6, &head1);
	addLast(4, &head1);
	addLast(6, &head1);
	printNodes(head1);
	head1 = mergeSort(head1);
	cout << endl << endl;
	printNodes(head1);




}




