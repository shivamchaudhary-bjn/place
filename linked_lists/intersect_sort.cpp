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
			//count++;
			create(&head,n);
		}
	}
	print(head);
	return(head);
}
node * intersect(node **head,node **head1)
{
	node *temp = NULL;

	while((*head) != NULL && (*head1) != NULL) {
		if((*head)->data == (*head1)->data) {
			//cout << "values are equal\n";
			create(&temp,(*head)->data);
			(*head) = (*head)->next;
			(*head1) = (*head1)->next;
		}
		else {
			if((*head)->data < (*head1)->data) {
				//cout << "first-one\n";
				(*head) = (*head)->next;
			}else {
				//cout << "second-one\n";
				(*head1) = (*head1)->next;
			}
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

	//count  = 0;
	cout << "enter the second list\n";
	head1 = call();
	//cout << "no. of nodes are " << count << endl;

	current = intersect(&head,&head1);
	print(current);
	return 0;
}

