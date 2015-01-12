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
void loop(node *head)
{
	int flag = 0;
	node *slow = head;
	node *fast = head;

	while(slow && fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) {
			flag = 1;
			break;
		}
	}
	if(flag == 1) {
		cout << "loop exists\n";
	}else {
		cout << "no loop exists\n";
	}
}
int main()
{
	int count  = 0;
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
	node *temp = head;
	while(count != 4) {
		temp = temp->next;
		count++;
	}
	temp = head;
	//head->next->next->next->next = head;	 
	loop(head);
	return 0;
}


