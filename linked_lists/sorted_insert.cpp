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
	cout << endl;
}
void sorted_insert(node **head,node **new_node)
{
	if((*head) == NULL) {
		(*head) = (*new_node);
		(*head)->next = NULL;
	}else if((*new_node)->data <= (*head)->data) {
		(*new_node)->next = (*head);
		(*head) = (*new_node);
	}else {
		node *temp = (*head);
		while((temp)->next != NULL && ((temp)->next)->data < (*new_node)->data) {
			temp = temp->next;
		}
		(*new_node)->next = temp->next;
		temp->next = (*new_node);
	}
}
int main()
{
	node *head = NULL;
	node *new_node;
	int n;
	while(1) {
		//create(&head,n);
		cin >> n;
		if(n == 999) {
			break;
		}else {
			create(&head,n);
		}
	}
	print(head);
	cout << "enter the new node value to be inserted\n";
	cin >> n;
	new_node = (node *)malloc(sizeof(node));
	new_node->data = n;
	sorted_insert(&head,&new_node);
	print(head);
	return 0;
}


