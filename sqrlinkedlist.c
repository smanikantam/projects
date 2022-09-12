#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
	struct node *lf,*ld,*lb;
}*current_head=NULL,*current=NULL,*headf=NULL;
int count=0,rem,lim=2,matlim;
int insert(int a);
void display();
struct node *reshape();
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
void display(){
	int ch;
	printf("1.display\t2.diagonal_display\t3.down\n");
	struct node *temp;
	temp=headf;
	scanf("%d",&ch);
	switch(ch){
		case 1:	printf("%d",temp->value);
				while(temp->lf!=NULL){
					temp=temp->lf;
					printf(" %d",temp->value);
				}
				break;
		case 2:	printf("%d",temp->value);
				while(temp->ld!=NULL){
					temp=temp->ld;
					printf(" %d",temp->value);
				}
				break;
		case 3:	printf("%d",temp->value);
				while(temp->lb!=NULL){
					temp=temp->lb;
					printf(" %d",temp->value);
				}
				break;
	}
	printf("\n");
}
int insert(int a){
	struct node *newnode;
	newnode=(struct node *) malloc(sizeof(struct node));
	newnode->value=a;
	newnode->lf=NULL;
	newnode->ld=NULL;
	newnode->lb=NULL;
	matlim=lim*lim;
	if(count+1>matlim){
		printf("reshape str\n");
		reshape();
		printf("com\n");
	}
	printf("lim %d\n",lim);
	rem=count%lim;
	printf("count %d\n",count);
	printf("rem %d\n",rem);
	if(headf==NULL){
		printf("str headf\n");
		current_head=newnode;
		headf=newnode;
		current=newnode;
		count++;
		printf("com\n");
		return 1;
	}
	else{
		if(count<lim){
			printf("str count<lim\n");
			current->lf=newnode;
			current=newnode;
			printf("com\n");
		}
		else if(rem==0){
			if(count/lim>=2){
				printf("str count/lim>=2\n");
				printf("before head%d\n",current_head->value);
				current_head=current_head->lb;
				printf("after head %d\n",current_head->value);
				printf("com\n");
			}
			printf("str else count/lim>=2\n");
			current->lf=newnode;
			current_head->lb=newnode;
			current=newnode;
			printf("com\n");
			
		}
		else if(rem==1){
			printf("str rem==1\n");
			current->lf=newnode;
			current_head->ld=newnode;
			current_head->lf->lb=newnode;
			current=newnode;
			printf("com\n");
		}
		else if(rem==lim-2){
			printf("str rem==lim-2\n");
			struct node *temp;
			int i;
			temp=current_head;
			for(i=lim-3;i!=0;i--)
				temp=temp->lf;
			temp->lf->lf->ld=newnode;
			temp->lf->lb=newnode;
			temp->ld=newnode;
			current->lf=newnode;
			current=newnode;
			printf("com\n");
		}
		else if(rem==lim-1){
			printf("str rem==lim-1\n");
			struct node *temp;int i;
			temp=current_head;
			for(i=lim-2;i!=0;i--)
				temp=temp->lf;
			temp->ld=newnode;
			temp->lf->lb=newnode;
			current->lf=newnode;
			current=newnode;
			printf("com\n");
		}

		else{
			printf("str else\n");
			struct node *temp;int i;
			temp=current_head;
			for(i=rem-1;i!=0;i--)
				temp=temp->lf;
			temp->ld=newnode;
			temp->lf->lb=newnode;
			current->lf=newnode;
			current=newnode;
			printf("com\n");
		}
	}
	count++;
	return 1;
}
struct node *reshape(){
	struct node *temp;
	temp=headf;
	headf=NULL;
	count=0;
	lim++;
	while(temp->lf!=NULL){
		printf("value %d\n",temp->value);
		insert(temp->value);
		temp=temp->lf;
	}
	printf("value %d\n",temp->value);
	insert(temp->value);
	return 0;
}




