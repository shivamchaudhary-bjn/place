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
void delete_alt(node **head,node **prev)
{
	while((*prev) != NULL && (*head) != NULL) {
		(*prev)->next = (*head)->next;
		free(*head);
		(*prev) = (*prev)->next;
		if(*prev != NULL) {
			*head = (*prev)->next;
		}
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
	cout << endl;
	node *prev = head;
	node *temp = head;
	head = head->next;
	delete_alt(&head,&prev);
	print(temp);
	return 0;
}


