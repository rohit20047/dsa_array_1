#include<iostream>
#include<stdlib.h>
using namespace std;
struct node {
	struct node *prev;
	int data;
	struct node *next;
};
struct node* add_to_empty(struct node *head , int data)
{
	head=(struct node*)malloc(sizeof(struct node));
	head->prev=NULL;
	head->data=data;
	head->next=NULL;
	return head;
}
void print_data(struct node *head)
{
	if(head==NULL)
	{
		cout<<"no node exit"<<endl;
		return;
	}
	while(head!=NULL)
	{
		cout<<head->data<<endl;
		head = head->next;
	}
}
struct node* add_at_beg(struct node *head ,int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=head;
	head->prev=temp;
	temp->prev=NULL;
	head=temp;
	
	return head;
}
void add_at_end(struct node *head,int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    while(head->next != NULL)
    {
    	head=head->next;
	}
	head->next=temp;
	temp->prev=head;
	
}
void add_at_pos(struct node **head , int pos , int data)
{

    struct node *temp = *head;
    struct node *temp2 = *head;
	struct node *newnode =(struct node*)malloc (sizeof(struct node));
	newnode->data=data;
	pos--;
	while(pos>1)
	{
		temp=temp->next;
		pos--;
	}  
    temp2=temp->next;
  
     //if we need to add at beg
     if(pos==0) 
     {
       *head = add_at_beg(temp,data);
     	return ;
	 }
     //if we need to add at end
     if(temp2 == NULL)
     {
       
     	temp->next=newnode;
     	newnode->prev=temp;
     	newnode->next=NULL;
        return;
	 }
     
     temp->next=newnode;
     temp2->prev=newnode;
     newnode->prev=temp;
     newnode->next=temp2; 
}
struct node* create_link(struct node *head)
{
	int n , data , i ;
	cout<<"enter the no.of nodes"<<endl;
	cin>>n;
	
	if(n==0)
	 return head;
	 
	 cout<<"enter the element for node 1"<<endl;
	 cin>>data;
	 head=add_to_empty(head,data);
	 
	 for(int i=1 ; i < n ;i++)
	 {
	 	cout<<"enter the element for node"<<i+1<<endl;
	 	cin>>data;
	 	add_at_end(head,data);
	 }
	 return head;
	 
}
struct node* del_at_beg(struct node *head)
{
    head=head->next;
    free(head->prev);
    head->prev=NULL; 
	return head;
}
void del_at_end(struct node *head)
{
	struct node *temp=head;
	while(temp->next!=NULL)
     temp=temp->next;
	 
	 temp->prev->next=NULL;
	 temp->prev=NULL;
	 free(temp);
	 temp=NULL;	

}
void del_at_pos(struct node **head, int pos)
{
	struct node *temp = *head;
	struct node *temp2 = *head;
	struct node *current = *head;
	
	if(pos==1)
	{
		*head=temp->next;
		(*head)->prev=NULL;
		free(temp);
		temp=NULL;
		return ;
	}
	
	while(pos>1)
	{
		current=current->next;
		pos--;
	}
	temp2=current->next;
	temp=current->prev;
	
	if(temp2==NULL)
	{
		temp->next=NULL;
		current->prev=NULL;
		free(current);
		current=NULL;
		return;
	}
	
	temp->next = temp2;
	temp2->prev=temp;
    
    current->next=NULL;
    current->prev=NULL;
	free(current);
	current=NULL;

}
void del_at_pos2(struct node *head,int pos)
{
	struct node *temp = head;
	struct node *temp2;
	
	while(pos>1)
	{
		temp = temp->next;
		pos--;
	}
	temp2=temp->prev;
	temp2->next=temp->next;
	temp->next->prev=temp2;
	free(temp);
	temp=NULL;
}
int main()
{
	// --------creating a node in main ----------------//
/*	struct node *head = (struct node *)malloc(sizeof(struct node));
	head->prev=NULL;
	head->data=10;
	head->next=NULL;*/
	
	struct node *head;
 head=create_link(head);
   del_at_pos2(head,2);
   print_data(head);
	
	
}
