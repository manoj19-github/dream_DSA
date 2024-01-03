
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




Node* reverseList(Node* head) {
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



Node* addTwoList(Node* firstHead, Node* secondHead) {
	Node* ans = NULL;
	int carry = 0;
	while (firstHead != NULL || secondHead != NULL || carry != 0) {
		int val1 = 0;
		if (firstHead != NULL) val1 = firstHead->data;
		int val2 = 0;
		if (secondHead != NULL) val2 = secondHead->data;
		int sum = val1 + val2 + carry;
		cout << "sum : " << sum << endl;
		int digit = sum % 10;
		addLast(digit, &ans);
		carry = sum/10;
		if(firstHead!=NULL) firstHead = firstHead->next;
		if(secondHead!=NULL) secondHead = secondHead->next;

	}
	
	return ans;
}


Node* sumOfTwoLinkedList(Node* firstHead, Node* secondHead) {
	Node* rFirstHead = reverseList(firstHead);
	
	Node* rSecondHead = reverseList(secondHead);
	
	Node* ansHead = addTwoList(rFirstHead, rSecondHead);
	ansHead = reverseList(ansHead);
	return ansHead;
	
}




void main()
{
	Node* head1 = NULL;
	Node* head2 = NULL;

	
	addLast(3, &head1);
	addLast(4, &head1);
	addLast(7, &head1);
	addLast(1, &head1);
	addLast(2, &head1);
	addLast(3, &head1);
	addLast(6, &head2);
	addLast(4, &head2);
	addLast(6, &head2);
	
	cout << endl << endl;
	cout << "First : " << endl;
	printNodes(head1);
	cout << "Second : " << endl;
	cout << endl << endl;
	printNodes(head2);
	cout << endl << endl;
	Node* ans = sumOfTwoLinkedList(head1, head2);
	cout << endl << endl;
	cout << "Answer : " << endl;
	printNodes(ans);



}




