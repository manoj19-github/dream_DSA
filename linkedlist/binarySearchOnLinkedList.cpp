
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

Node* findMiddle(Node* left,Node *right) {
	if (left == NULL) return NULL;
	Node* fast = left->next;
	Node* slow = left;
	while (fast != right) {
		fast = fast->next;
		if (fast != right) {
			fast = fast->next;
			slow = slow->next;
		}
	}
	return slow;
}

Node* binarySearch(Node* head,int searchKey) {
	if (head == NULL) return NULL;
	Node* left = head;
	Node* right = NULL;
	do {
		Node* middle = findMiddle(left, right);
		if (middle->data == searchKey) return middle;
		else if (middle->data < searchKey) {
			left = middle->next;
		}
		else {
			right = middle;
		}
	} while (right != NULL && right != left);
	return NULL;

}

void main() {
	Node* head = NULL;
	addLast(4,&head);
	addLast(8, &head);
	addLast(13, &head);
	addLast(19, &head);
	addLast(25, &head);
	addLast(29, &head);
	addLast(33, &head);
	addLast(42, &head);
	addLast(112, &head);
	
	printNodes(head);
	
	Node* searched = binarySearch(head, 219);
	if (searched !=  NULL)
		cout << endl << endl << searched->data;
	else cout << endl << "Not found" << endl;
	
}


