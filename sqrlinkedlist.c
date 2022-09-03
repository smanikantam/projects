#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
	struct node *lf,*ld,*lb;
}*head=NULL,*current=NULL,*headf=NULL;
int count=0,rem;
void insert(int a);
void display();
int main(){
	int ch,x;
	printf("choose\n");
	while(1){
		printf("1.insert\t2.display3.delete\t4.exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:printf("enter the element\n");
			       scanf("%d",&x);
			       insert(x);break;
			case 2:display();break;
			case 4:exit(1);break;
			default :printf("invalid\n");
		}
	}
	return 1;
}
void insert(int a){
	struct node *newnode;
	rem=count%3;
	newnode=(struct node *) malloc(sizeof(struct node));
	newnode->value=a;
	if(head==NULL){
		headf=newnode;
		head=newnode;
		current=newnode;
	}
	else{
		if(count<3){
			current->lf=newnode;
			current=newnode;
		}
		else if(rem==0){
			if((count/3)>=2){
				head=head->lb;
			}
			current->lf=newnode;
			head->lb=newnode;
			current=newnode;
		}
		else if(rem==1){
			current->lf=newnode;
			head->ld=newnode;
			head->lf->lb=newnode;
			current=newnode;
		}
		else if(rem==2){
			current->lf=newnode;
			head->lf->ld=newnode;
			current=newnode;
		}
	}
	count+=1;
}
void display(){
	int ch;
	printf("1.display\t2.diagonal_display\n");
	struct node *temp;
	temp=headf;
	scanf("%d",&ch);
	switch(ch){
		case 1: while(temp->lf!=NULL){
					printf("%d",temp->value);
					temp=temp->lf;
				}
				printf("%d\n",temp->value);
				break;
		case 2: while(temp->ld!=NULL){
					printf("%d",temp->value);
					temp=temp->ld;
				}
				printf("%d\n",temp->value);
				break;
	}
}

































