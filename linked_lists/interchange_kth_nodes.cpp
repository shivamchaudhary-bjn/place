#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int val;
	struct node *next;
	struct node *prev;
}node;
node *insert(node **head,int n)
{
	node *temp,*temp1,temp2;
	if(*head == NULL) {
		temp = (node *)malloc(sizeof(node));
		temp->val = n;
		*head = temp;
		(*head)->next = NULL;
		(*head)->prev = NULL;
		//printf("inserting %d\n",n);
		return *head;
	}
	else {
		temp = *head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp1 = (node*)malloc(sizeof(node));
		temp1->val = n;
		temp->next = temp1;
		temp1->prev = temp;
		temp1->next = NULL;
		return temp1;
	}
}
void print(node *head)
{
	while(head != NULL) {
		printf("%d-->",(head)->val);
		(head) = (head)->next;
	}
	printf("\n");
}
void interchange(node **head,node **tail,int k,int n)
{
	node *yt,*yt1,*end,*start;
	end = *tail;
	start = *head;
	int count,count1;
	count = 1;
	while(count != k) {
		(end) = (end)->prev;
		count++;
	}
	count1 = 1;
	while(count1 != k) {
		start = start->next;
		count1++;
	}
	//printf("%d--%d\n",start->val,end->val);
	if(start->prev) {
		start->prev->next = end;
	}
	if(end->prev) {
		end->prev->next = start;
	}
	yt = start->next;
	start->next = end->next;
	end->next = yt;
	
	if(k == 1) {
		*head = end;
	}
	if(k == n) {
		*head = start;
	}
	yt1 = end;
	end = start;
	start = yt1;

	//printf("%d--%d\n",start->val,end->val);
	//print(head);
}
int main()
{
	int cnt = 0;
	int n,k,d,num;
	node *head = NULL;
	node *tail = NULL;
	node *temp2,*temp3,*temp4;
	while(1){
		scanf("%d",&n);
		cnt++;
		if(n == 999)
			break;
		tail = insert(&head,n);
	}
	print(head);
	printf("enter value of k that needs to interchange the kth node from front and end of linked list\n");
	scanf("%d",&k);
	interchange(&head,&tail,k,cnt);
	print(head);
	return 0;
}

