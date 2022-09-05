#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
	struct node *lf,*ld,*lb;
}*head=NULL,*current=NULL,*headf=NULL;
int count=0,rem,lim=2,matlim;
void insert(int a);
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
void insert(int a){
	struct node *newnode;
	newnode=(struct node *) malloc(sizeof(struct node));
	newnode->value=a;
	matlim=lim*lim;
	if(count+1>matlim){
		lim++;
		current=reshape();
		// printf("%d%d%d\n",head->lf->value,head->ld->value,head->lb->value);
	}
	rem=count%lim;
	if(head==NULL){
		headf=newnode;
		head=newnode;
		current=newnode;
	}
	else{
		if(count<lim){
			current->lf=newnode;
			current=newnode;
		}
		else if(rem==0){
			if((count/lim)>=2){
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
		// else if(rem==lim-1){
		// 	current->lf=newnode;
		// 	head->lf->ld=newnode;
 	// 		current=newnode;
		// }
		else{
			struct node *t_head;
			int t_rem;
			t_head=head;
			for(t_rem=rem-1;t_rem!=0;t_rem--){
				t_head=t_head->lf;
			}
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
struct node *reshape(){
	struct node *t_head=headf,*t_current=headf,*pointer=headf->lf;
	int t_count=0,t_rem,i;
	t_rem=t_count%lim;
	for(i=count;i!=0;i--){
		if(t_count<lim){
			t_current->lf=pointer;
			t_current=pointer;
		}
		else if(t_rem==0){
			if((t_count/lim)>=2){
				t_head=t_head->lb;
			}
			t_current->lf=pointer;
			t_head->lb=pointer;
			t_current=pointer;
		}
		else if(t_rem==1){
			t_current->lf=pointer;
			t_head->ld=pointer;
			t_head->lf->lb=pointer;
			t_current=pointer;
		}
		// else if(t_rem==lim-1){
		// 	t_current->lf=pointer;
		// 	t_head->lf->ld=pointer;
 	// 		t_current=pointer;
		// }
		else{
			struct node *temp_head;
			int temp_rem;
			temp_head=head;
			for(temp_rem=rem-1;temp_rem!=0;temp_rem--){
				temp_head=temp_head->lf;
			}
			t_current->lf=pointer;
			t_head->lf->ld=pointer;
			t_current=pointer;
		}
		if(pointer->lf!=NULL){
		pointer=pointer->lf;
		}	
		t_count++;
	}
	head=t_head;
	return t_current;
}

































