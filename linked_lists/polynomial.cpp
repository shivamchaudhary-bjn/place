#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
typedef struct polynode 
{
	float coeff;
	int exp;
	struct polynode *next;
}polynode;
void create(polynode **head,float coeff,int exp)
{
	if(*head == NULL) {
		(*head) = (polynode *)malloc(sizeof(polynode));
		(*head)->coeff = coeff;
		(*head)->exp = exp;
		(*head)->next = NULL;
	}else {
		create(&((*head)->next),coeff,exp);
	}
}
void print(polynode *head)
{
	while(head != NULL) {
		cout << head->coeff << "*x^" << head->exp << " + ";
		head = head->next;
	}
	cout << endl;
}
void call(polynode **head)
{
	while(1)
	{
		float c;
		int ex;
		cin >> c >> ex;
		if(c == 0) {
			break;
		}else {
			create(head,c,ex);
		}
	}
}
void add(polynode *head,polynode *head1)
{
	polynode *head2 = NULL;
	polynode *temp = NULL;
	head2 = temp;
	while(head != NULL && head1 != NULL)
	{
		if(head->exp > head1->exp) {		
			create(&temp,head->coeff,head->exp);
			cout << temp->coeff << "*x^" << temp->exp << " + ";
			head = head->next;
		}else if(head1->exp > head->exp) {
			create(&temp,head1->coeff,head1->exp);
			cout << temp->coeff << "*x^" << temp->exp << " + ";
			head1 = head1->next;
		}else if(head->exp == head1->exp) {
			create(&temp,head->coeff+head1->coeff,head->exp);
			cout << temp->coeff << "*x^" << temp->exp << " + ";
			head = head->next;
			head1 = head1->next;
		}
		temp = temp->next;
	}
	if(head != NULL) {
		while(head != NULL) {
			create(&temp,head->coeff,head->exp);
			head = head->next;
			temp = temp->next;
		}
	}
	if(head1 != NULL) {
		while(head1 != NULL) {
			create(&temp,head1->coeff,head1->exp);
			head1 = head1->next;
			temp = temp->next;
		}
	}
	//print(head2);
}
int main()
{
	polynode *head = NULL;
	polynode *head1 = NULL;
	cout << "make first polynomial function\n";
	call(&head);
	cout << "make second polynomial function\n";
	call(&head1);
	cout << "add the two polynomials\n";
	add(head,head1);
	return 0;
}
