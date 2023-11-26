
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
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
void findMid(Node* head,Node **left,Node **right) {
	Node* fast = head->next;
	Node* slow = head;
	while(fast!=NULL){
		fast = fast->next;
		if (fast != NULL) {
			fast = fast->next;
			slow = slow->next;
		}
	}
	*left = head;
	*right = slow->next;
	slow->next = NULL;
	
}
Node* sortedMerge(Node* left, Node* right) {
	
	if (left == NULL) return right;
	if (right == NULL) return left;
	Node* result = NULL;
	if (left->data <= right->data) {
		result = left;
		result->next = sortedMerge(left->next, right);
	}
	else {
		result = right;
		result->next = sortedMerge(left, right->next);
	}
	return result;
}
void mergeSort(Node** head) {
	if (*head == NULL || (*head)->next == NULL) return;
	Node* left;
	Node* right;
	findMid(*head,&left,&right);
	
	mergeSort(&left);
	mergeSort(&right);
	*head = sortedMerge(left,right);

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





void main() {
	Node* head = NULL;
	addLast(4,&head);
	addLast(2, &head);
	addLast(3, &head);
	addLast(9, &head);
	addLast(5, &head);
	addLast(9, &head);
	addLast(3, &head);
	addLast(2, &head);
	addLast(12, &head);
	cout << "Unsorted list " << endl;
	printNodes(head);
	cout << endl << "Sorted list : " << endl;
	mergeSort(&head);
	printNodes(head);
	
}


