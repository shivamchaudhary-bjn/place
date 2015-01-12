#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node 
{
	int data;
	struct node *next;
	struct node *prev;
}node;

typedef struct queue
{
	int capacity;
	int count;
	struct node *front;
	struct node *rear;
}queue;

void create_queue(queue **q,int cap)
{
	*q = (queue *)malloc(sizeof(queue));
	(*q)->count = 0;
	(*q)->capacity = cap;
	(*q)->front = NULL;
	(*q)->rear = NULL;
}
void enqueue(node ** head,node **tail,queue **q,int n)
{
	node *temp,*temp1,*temp2;
	if((*q)->count == 0) {
		temp = (node *)malloc(sizeof(node));
		temp->data = n;
		*head = temp;
		(*head)->next = NULL;
		(*head)->prev = NULL;
		(*q)->front = (*q)->rear = (*head);
		(*q)->count = 1;
	}else {
		if((*q)->count == (*q)->capacity) {
			cout << "queue is already full\n";
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
			(*q)->front = temp1;
			((*q)->count)++;
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
void dequeue(node **head,queue **q)
{
	node *temp;
	if((*q)->count == 0) {
		cout << "queue is already empty\n";
	}else {
		node *current = (*head);
		temp = (*head);
		(*head) = (*head)->next;
		(*head)->prev = NULL;
		(*q)->rear = (*head);
		((*q)->count)--;
		free(current);
	}
	//return temp;
}
int main() 
{
	int cap;
	cout << "enter the capacity of queue\n";
	cin >> cap;
	queue *q;
	create_queue(&q,cap);
	node *head = NULL;
	node *tail = NULL;
	for(int i = 0;i < 5;i++) {
		//create(&head,n);
		int n;
		cin >> n; 
		enqueue(&head,&tail,&q,n);
	}
	dequeue(&head,&q);
	//cout << "popped element is " << p->data << endl;
	enqueue(&head,&tail,&q,9);
	print(head);
	/*cout << "enter the node to be deleted\n";
	int k;
	cin >> k;
	delete_node(&head,k);
	print(head);*/
	return 0;
}


