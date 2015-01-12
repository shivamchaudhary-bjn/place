#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node 
{
	int data;
	struct node *next;
}node;
int count;
node *create(node ** head,int n)
{
	node *temp,*temp1,*temp2,*tail;
	if(*head == NULL) {
		temp = (node *)malloc(sizeof(node));
		temp->data = n;
		*head = temp;
		(*head)->next = NULL;
		count++;
	}else {
		temp1 = (node *) malloc(sizeof(node));
		temp1->data = n;

		temp2 = *head;
		while(temp2->next != NULL) {
			temp2 = temp2->next;
		}
		temp2->next = temp1;
		temp1->next = NULL;
		tail = temp1;
		count++;
		/*temp1 = (node *)malloc(sizeof(node));
		temp1->data = n; 
		(*head)->next = temp1;
		((*head)->next)->prev = *head;
		((*head)->next)->next = NULL;
		(*head) = (*head)->next;
		//create((&(*head)->next),n);*/
	}
	return(tail);
}
void create1(node **head,int n)
{
	node *temp;
	if(*head == NULL) {
		temp = (node *)malloc(sizeof(node));
		temp->data = n;
		temp->next = NULL;
		*head = temp;
	}else {
		create1(&((*head)->next),n);
	}
}
void print(node *head,node *tail) 
{
	while(head != tail) {
		cout <<(head)->data << "-->";
		(head) = (head)->next;
	}
	cout << head->data;
	cout << endl;
}
void print1(node *link1,node *link2)
{
	cout << "first list:\n";
	while(link1 != NULL) {
		cout << link1->data << "-->";
		link1 = link1->next;
	}
	cout << endl;
	cout << "second list:\n";
	while(link2 != NULL) {
		cout << link2->data << "-->";
		link2 = link2->next;
	}
	cout << endl;
}
void split(node **head,node **link1,node **link2)
{
	int i = 1;
	int temp;
	while(i <= count/2) {
		temp = (*head)->data;
		create1(link1,temp);
		(*head) = (*head)->next;
		i++;
	}
	while(i <= count) {
		temp = (*head)->data;
		create1(link2,temp);
		(*head) = (*head)->next;
		i++;
	}
}
int main() 
{
	node *head = NULL;
	node *tail = NULL;
	node *link1 = NULL;
	node *link2 = NULL;
	count  = 0;
	while(1) {
		//create(&head,n);
		int n;
		cin >> n;
		if(n == 999) {
			break;
		}else {
			tail = create(&head,n);
			//if(count == 1) {
			//	init = &head;
			//}
		}
	}
	tail->next = head;
	print(head,tail);
	//cout << head->data << " " << count << endl;
	split(&head,&link1,&link2);
	print1(link1,link2);
	//print_reverse(tail);
	//print(head);
	return 0;
}


