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
			create(&head,n);
		}
	}
	print(head);
	return(head);
}
void split(node *current,node **a,node **b)
{
	node *fast,*slow;
	if(current == NULL || current->next == NULL) {
		*a = current;
		*b = NULL;
	}else {
		slow = current;
		fast = current->next;
		while(fast != NULL) {
			fast = fast->next;
			if(fast != NULL) {
				slow = slow->next;
				fast = fast->next;
			}
		}
		*a = current;
		*b = slow->next;
		slow->next = NULL;
	}
}
node* merge(node **a,node **b)
{
	node *result = NULL;
	if(*a == NULL) {
		return(*b);
	}else if(*b == NULL) {
		return(*a);
	}
	if((*a)->data < (*b)->data) {
		result = *a;
		result->next = merge((&(*a)->next),b);
	}else {
		result = *b;
		result->next = merge(a,(&(*b)->next));
	}
	return result;
}
void merge_sort(node **head)
{
	node *current = *head;
	node *a;
	node *b;

	if(current == NULL || current->next == NULL) {
		return;
	}else {
		split(current,&a,&b);
		merge_sort(&a);
		merge_sort(&b);
		*head = merge(&a,&b);
	}
}
int main()
{
	node *head;
	node *current;
	cout << "enter the Unsorted list\n";
	head = call();
	merge_sort(&head);
	print(head);
	return 0;
}

