#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int val;
	struct node *next;
}node;
void insert(node **head,int n)
{
	node *temp;
	if(*head == NULL) {
		temp = (node *)malloc(sizeof(node));
		temp->val = n;
		*head = temp;
		(*head)->next = NULL;
		//printf("inserting %d\n",n);

	}
	else {
		insert(&((*head)->next),n);
	}
}
void print(node *head)
{
	/*if(head == NULL) {
		return;
	}else {
		if(head->next == NULL) {
			printf("%d-->",head->val);
		}else {
			printf("%d-->",head->val);
			print(head->next);
		}
	}*/
	//while(head != NULL) {
	//	printf("%d-->",head->val);
	//	head = head->next;
	//}
	printf("%d-->",head->val);
	if(head->next == NULL)
		return;
	print(head->next);
}
int kth_node(node *head,int k)
{
	int count;
	count = 1;
	while(count != k) {
		head = head->next;
		count++;
	}
	return head->val;
}
node **find(node **head,int k)
{
	int count;
	count = 1;
	while(count != k-1) {
		*head = *head->next;
		count++;
	}
	return *head;
}
void delete(node **head,int k)
{

int main()
{
	int n,k;
	node *head = NULL;
	
	while( 999){
		scanf("%d",&n);
		if(n == 999)
			break;
		insert(&head,n);
	}
	print(head);
	scanf("%d",&k);
	printf("kth node is %d\n",kth_node(head,k));
	return 0;
}

