#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node 
{
	int data;
	struct node *next;
	struct node *prev;
}node;
typedef struct cache
{
	int capacity;
	node* *array;
}cache;
typedef struct page 
{
	int pagenumber;
	int value;
}page;
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
		}
	}
	print(head);
	print_reverse(tail);
	return 0;
}


