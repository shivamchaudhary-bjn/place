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
void reverse(node **head)
{
	int count  = -1;
	node *next;
	node *temp = *head;
	node *prev = NULL;
	count++;
	while(temp->next != NULL) {
		next = (temp)->next;
		//cout << "next is "  << next->data << endl;
		(temp)->next = prev;
		prev = (temp);
		//cout << "prev is " << prev->data <<endl;
		temp = next;
		//cout << "new temp is " << temp->data << endl;
	}
	temp->next = prev;
	*head = temp;
	//cout << "head value is " << (*head)->data << endl;
}
void compare(node *head,node *head1)
{
	node *t = head;
	node *t1 = head1;
	int flag = 0;
	int count  = 0;
	while(t && t1) {
		//cout << t->data << " " << t1->data << endl;
		if(t->data == t1->data) {
			t = t->next;
			t1 = t1->next;
		}else {
			flag = 1;
			break;
			cout << "flag is " << flag << endl;
		}
		count++;
	}
	cout << "count is " << count << endl;
	if(flag == 0) {
		cout << "given list is a palindrome\n";
	}else {
		cout << "given list is not a palindrome\n";
	}
}
int main()
{
	node *head = NULL;
	node *head1;
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
	cout << endl;
	head1 = head;
	reverse(&head);
	print(head);
	cout << endl;
	compare(head,head1);
	return 0;
}


