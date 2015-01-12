#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node 
{
	int data;
	struct node *next;
}node;
int count;
void create(node ** head,int n)
{
	node *temp;
	if(*head == NULL) {
		temp = (node *)malloc(sizeof(node));
		temp->data = n;
		*head = temp;
		(*head)->next  = NULL;
		//cout << "temp data is " << temp->data << endl;
	}else {
		create((&(*head)->next),n);
	}
}
void print(node *head) 
{
	while(head != NULL) {
		cout << (head)->data << "-->";
		(head) = (head)->next;
	}
	cout << endl;
}
node * call(void)
{
	node *head = NULL;
	while(1) {
		int n;
		cin >> n;
		if(n == 999) {
			break;
		}else {
			count++;
			create(&head,n);
		}
	}
	print(head);
	//cout << "starting node is " << head->data << endl;
	return(head);
}
node * merge(node **head,node **head1)
{
	node *temp = NULL;

	while((*head) != NULL && (*head1) != NULL) {
		if((*head)->data == (*head1)->data) {
			create(&temp,(*head)->data);
			(*head) = (*head)->next;
			(*head1) = (*head1)->next;
		}else {
			if((*head)->data < (*head1)->data) {
				//cout << "first-one\n";
				create(&temp,(*head)->data);
				(*head) = (*head)->next;
			}else if((*head)->data > (*head1)->data){
				//cout << "second-one\n";
				create(&temp,(*head1)->data);
				(*head1) = (*head1)->next;
			}
		}
	}
	if(*head != NULL) {
		while(*head != NULL) {
			create(&temp,(*head)->data);
			(*head) = (*head)->next;
		}
	}
	if(*head1 != NULL) {
		while(*head1 != NULL) {
			create(&temp,(*head1)->data);
			(*head1) = (*head1)->next;
		}
	}
	return(temp);
}
int main()
{
	node *head,*head1;
	node *current;
	
	//count  = 0;
	cout << "enter the first list\n";
	head = call();
	//cout << "no. of nodes are " << count  << endl;

	count  = 0;
	cout << "enter the second list\n";
	head1 = call();
	//cout << "no. of nodes are " << count << endl;

	current = merge(&head,&head1);
	print(current);
	return 0;
}

