#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node 
{
	int data;
	struct node *next;
	struct node *prev;
}node;

typedef struct stack
{
	int capacity;
	int count;
	struct node *top;
	struct node *down;
}stack;

void create_stack(stack **s,int cap)
{
	*s = (stack *)malloc(sizeof(stack));
	(*s)->count = 0;
	(*s)->capacity = cap;
	(*s)->top = NULL;
	(*s)->down = NULL;
}
void push(node ** head,node **tail,stack **s,int n)
{
	node *temp,*temp1,*temp2;
	if((*s)->count == 0) {
		temp = (node *)malloc(sizeof(node));
		temp->data = n;
		*head = temp;
		(*head)->next = NULL;
		(*head)->prev = NULL;
		(*s)->top = (*s)->down = (*head);
		(*s)->count = 1;
	}else {
		if((*s)->count == (*s)->capacity) {
			cout << "stack is already full\n";
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
			*tail = temp1;
			(*s)->top = temp1;
			((*s)->count)++;
		}
	}
}
void print(node *head) 
{
	while(head != NULL) {
		cout <<(head)->data << "-->";
		(head) = (head)->next;
	}
	cout << endl;
}
void pop(node **tail,stack **s)
{
	node *temp = (node *)malloc(sizeof(node));
	if((*s)->count == 0) {
		cout << "stack is already empty\n";
	}else {
		node *current = (*tail);
		temp = (*tail);
		(*pt) = (*tail);
		//cout << "popped element is  " << temp->data << endl;
		(*tail) = (*tail)->prev;
		(*tail)->next = NULL;
		(*s)->top = (*tail);
		((*s)->count)--;
		free(current);
	}
}
int main() 
{
	int cap;
	cout << "enter the capacity of stack\n";
	cin >> cap;
	stack *s;
	node *p;
	create_stack(&s,cap);
	node *head = NULL;
	node *tail = NULL;
	for(int i = 0;i < 5;i++) {
		int n;
		cin >> n; 
		push(&head,&tail,&s,n);
	}
	pop(&tail,&s);
	push(&head,&tail,&s,9);
	print(head);
	return 0;
}


