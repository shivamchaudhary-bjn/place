#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node 
{
	int data;
	struct node *next;
	struct node *prev;
}node;
node *create(node ** head,int n)
{
	node *temp,*temp1,*temp2,*tail;
	if(*head == NULL) {
		temp = (node *)malloc(sizeof(node));
		temp->data = n;
		*head = temp;
		(*head)->next = NULL;
		(*head)->prev = NULL;
	}else {
		temp1 = (node *) malloc(sizeof(node));
		temp1->data = n;

		temp2 = *head;
		while(temp2->next != NULL) {
			temp2 = temp2->next;
		}
		temp2->next = temp1;
		temp1->prev  = temp2;
		temp1->next = NULL;
		tail = temp1;
	}
	return(tail);
}
void print(node *head) 
{
	while(head != NULL) {
		cout <<(head)->data << "-->";
		(head) = (head)->next;
	}
	cout << endl;
}
void print_reverse(node *tail)
{
	while(tail != NULL) {
		cout << tail->data << "-->";
		tail = tail->prev;
	}
	cout << endl;
}
void delete_node(node **head,int k)
{
	int count  = 1;
	node *temp;
	node *current = *head;
	while(count < k) {
		//cout << "current data is " << current->data << endl;
		current = current->next;
		count++;
	}
	current->prev->next = current->next;
	current->next->prev = current->prev;
	free(current);
}
int main() 
{
	node *head = NULL;
	node *tail = NULL;
	while(1) {
		//create(&head,n);
		int n,count;
		count  = 0;
		cin >> n;
		if(n == 999) {
			break;
		}else {
			count++;
			tail = create(&head,n);
			//if(count == 1) {
			//	init = &head;
			//}
		}
	}
	print(head);
	print_reverse(tail);
	cout << "enter the node to be deleted\n";
	int k;
	cin >> k;
	delete_node(&head,k);
	print(head);
	return 0;
}


