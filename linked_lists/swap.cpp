#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node 
{
	int data;
	struct node *next;
}node;
void create(node ** head,int n)
{
	node *temp;
	if(*head == NULL) {
		temp = (node *)malloc(sizeof(node));
		temp->data = n;
		*head = temp;
		(*head)->next  = NULL;
	}else {
		create((&(*head)->next),n);
	}
}
void print(node *head) 
{
	while(head != NULL) {
		cout << head->data << "-->";
		head = head->next;
	}
}
void swap(node **head)
{
	node *temp,*current,*temp1;
	current = *head;
	while(current != NULL && current->next != NULL) {
		temp->data = current->next->data;
		//cout << "next is " << temp->data << endl;
		current->next->data = current->data;
		current->data = temp->data;
		//cout << "new values are " << current->data << " and " << temp->data << endl;
		current = current->next->next;
	}
}
int main()
{
	node *head = NULL;
	while(1) {
		//create(&head,n);
		int n;
		cin >> n;
		if(n == 999) {
			break;
		}else {
			create(&head,n);
		}
	}
	print(head);
	swap(&head);
	print(head);
	return 0;
}


