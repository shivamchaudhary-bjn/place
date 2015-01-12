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
	}
	while(head != NULL) {
		printf("%d-->",head->val);
		head = head->next;
	}*/
	if(head == NULL) {
		printf("NO more nodes\n");
		return;
	}else {
		printf("%d-->",head->val);
		if(head->next == NULL) {
			printf("linked lists ends here\n");
			return;
		}
		print(head->next);
	}
}
node *kth_node(node *head,int k)
{
	int count;
	count = 1;
	while(count != k) {
		head = head->next;
		count++;
	}
	return head;
}
node *find(node **head,int k)
{
	node *temp;
	int count;
	count = 1;
	while(count != k-1) {
		*head = (*head)->next;
		count++;
	}
	temp = *head;
	return temp;
}
void delete(node *head)
{
	node *temp;
	temp = head->next;
	head->val = temp->val;
	head->next = temp->next;
	free(temp);
}
void delete_whole(node **head)
{
	node **temp;
	while((*head)->next != NULL) {
		*temp = (*head)->next;	
		free(*head);
		*head = *temp;
	}
	free(*head);
}
int count(node *head,int num)
{
	int c = 0;
	while(head != NULL) {
		if(head->val == num)
			c++;
		head = head->next;
	}
	return c;
}

int main()
{
	int n,k,d,num;
	node *head = NULL;
	
	while(1){
		scanf("%d",&n);
		if(n == 999)
			break;
		insert(&head,n);
	}
	node *temp,*temp1;
	temp = (node *)malloc(sizeof(node));
	print(head);
	scanf("%d",&k);
	temp = kth_node(head,k);
	printf("%dth node is %d\n",k,temp->val);//kth_node(head,k));
	printf("Enter the node to be deleted\n");
	scanf("%d",&d);
	delete(kth_node(head,d));
	temp1 = kth_node(head,d);
	printf("%dth node is %d\n",d,temp1->val);
	printf("Enter the no. whose frequency we have to find\n");
	scanf("%d",&num);
	printf("frequency of given no. is %d\n",count(head,num));
	//delete_whole(&head);
	//print(head);
	//printf("first node is ",kth_node(head,k));
	return 0;
}

