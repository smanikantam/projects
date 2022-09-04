#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
	struct node *lf,*ld,*lb;
}*head=NULL,*current=NULL,*headf=NULL;
int count=0,rem,lim=2,matlim,sum_bit;
void insert(int a);
void display();
struct node *reshape(struct node*);
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
	newnode=(struct node *) malloc(sizeof(struct node));
	newnode->value=a;
	if(head==NULL){
		headf=newnode;
		head=newnode;
		current=newnode;
	}
	else if(count<2){
		current->lf=newnode;
		current=newnode;
	}
	else{
		sum_bit=count&(count-1);
		matlim=lim*lim;
		if(count>=matlim && sum_bit==0){
			lim+=1;
			matlim=lim*lim;
			// rem=count%lim;
			current=reshape(newnode);
		}
		else{
			int temp_rem;
			struct node *temp_head;
			temp_head=head;
			rem=count%lim;
			if((count/lim)>=2 && rem==0){
				head=head->lb;
				temp_head=head;
			}
			else if(rem>0){
				for(temp_rem=rem-1;temp_rem!=0;temp_rem--){
					temp_head=temp_head->lf;
				}
				if(rem==1 && count>lim){
					current->lf=newnode;
					head->ld=newnode;
					head->lf->lb=newnode;
					current=newnode;
				}
				else{
					current->lf=newnode;
					temp_head->ld=newnode;
					temp_head->lf->lb=newnode;
					current=newnode;
				}
			}
		}
	}
	count++;
}
struct node *reshape(struct node *newnode){
	struct node *temp_head=headf,*temp_headf=headf,*temp_current=headf,*pointer=headf;
	int temp_count=1,temp_rem;
	while(temp_current->lf!=NULL){
		temp_rem=temp_count%lim;
		if(temp_count<lim){
			temp_current=pointer;
		}
		else if(temp_rem==0){
			if((temp_count/lim)>=2){
				temp_head=temp_head->lb;
			}
			temp_head->lb=pointer;
			temp_current->lf=pointer;
		}
		else{
			for(temp_rem=rem-1;temp_rem!=0;temp_rem--){
				temp_head=temp_head->lf;
			}
			if(temp_rem==1 && temp_count>lim){
				temp_current->lf=pointer;
				temp_head->ld=pointer;
				temp_head->lf->lb=pointer;
			}
			else if(rem==lim-1){
				temp_current->lf=pointer;
				temp_head->lf->ld=pointer;
			}
			else{
				temp_current->lf=pointer;
				temp_head->ld=pointer;
				temp_head->lf->lb=pointer;
			}
		}
		pointer=pointer->lf;
		temp_current=pointer;
		temp_count++;
	}
	temp_current->lf=newnode;
	temp_current=newnode;
	return temp_current;
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
































