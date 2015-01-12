#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node {
	int data;
	struct node *next;
}node;
void create(node **head,int n)
{
	if(*head == NULL) {
		*head = (node *)malloc(sizeof(node));
		(*head)->data = n;
		(*head)->next = NULL;
	}else {
		create(&((*head)->next),n);
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
void sorting(node **head)
{
	node *com = *head;
	node *temp = *head;
	node *p = *head;
	node *q;
	node *temp1;
	node *sw,*ut;

	while(temp->next != NULL) {
		temp1 = temp->next;
		q = temp->next;
		while(temp1 != NULL) {
			if(temp->data > temp1->data) {
				if(temp->next == temp1) {
					if(temp == com) {
						temp->next = temp1->next;
						temp1->next = temp;
				
						sw = temp;
						temp = temp1;
						temp1 = sw;
				
						com = temp;
						p = temp;
						q = temp1;
					}else {
						temp->next = temp1->next;
						temp1->next = temp;
						p->next = temp1;
	
						sw = temp;
						temp = temp1;
						temp1 = sw;

						q = temp1;
					}
				}else {
					if(temp == com) {
						ut = temp1->next;
						temp1->next = temp->next;
						temp->next = ut;
						q->next = temp;

						sw = temp;
						temp = temp1;
						temp1 = sw;
			
						q = temp1;
						com = temp;
					}else {
						ut = temp1->next;
						temp1->next = temp->next;
						temp->next = ut;
						p->next = temp1;
						q->next = temp;
			
						sw = temp;
						temp = temp1;
						temp1 = sw;
				
						q = temp1;
					}
				}
				temp1 = temp1->next;
			}else {
				q = temp1;
				temp1 = temp1->next;
			}
		}
		p = temp;
		temp = temp->next;
	}
}

int main()
{
	node *head = NULL;
	cout << "create a unsorted link list\n";
	while(1) 
	{
		int n;
		cin >> n;
		if(n == 999) {
			break;
		}else {
			create(&head,n);
		}
	}
	print(head);
	sorting(&head);
	cout << "link list after sorting\n";
	print(head);
	return 0;
}

