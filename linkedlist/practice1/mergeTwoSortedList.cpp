
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



// void deleteDuplicatesFromUnsortedList(Node** head) {
// 	if (*(head) == NULL) return;
// 	unordered_set<int> seen;
// 	Node* curr = *head;
// 	Node* prev = NULL;
// 	while (curr != NULL) {
// 		if (seen.find(curr->data) != seen.end())
// 		{
// 			prev->next = curr->next;
// 			delete(curr);
// 			curr = NULL;


// 		}
// 		else {
// 			seen.insert(curr->data);
// 			prev = curr;
// 		}
// 		curr = prev->next;
// 	}

// }

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

Node* solve(Node* first, Node* second) {
	Node* curr1 = first;
	Node* curr2 = second;
	Node* next1 = curr1->next;
	Node* next2 = curr2->next;
	while (next1 != NULL && curr2 != NULL) {
		if (curr2->data >= curr1->data && curr2->data<=next1->data) {
			curr1->next = curr2;
			next2 = curr2->next;
			curr2->next = next1;
			curr1 = curr2;
			curr2 = next2;

		}
		else {
			// move curr1 and next1 
			curr1 = next1;
			next1 = next1->next;
			if (next1 == NULL) {
				curr1->next = curr2;
				return first;
			}
		}
	}
	return first;
}


Node* sortTwoLists(Node* first, Node* second) { 
	if (first == NULL) return second;
	if (second == NULL) return first;


	if (first->data <= second->data) {
		first = solve(first, second);
	}
	else {
		first = solve(second, first);
	}
	return first;


}



void main()
{
	Node* head1 = NULL;
	Node* head2 = NULL;
	addLast(2, &head1);
	addLast(3, &head1);
	addLast(5, &head2);
	addLast(7, &head2);
	addLast(4, &head1);
	addLast(8, &head2);
	addLast(5, &head1);
	
	printNodes(head1);
	cout << endl << endl;
	printNodes(head2);
	head1 = sortTwoLists(head1, head2);
	cout << endl << endl;
	printNodes(head1);
}




