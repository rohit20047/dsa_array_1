#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *link;
};
void count_of_nodes(struct node* head)
{
	int count=0;
	if(head==NULL)
	{
		cout<<"linked list is empty"<<endl;
	}
	struct node* ptr = NULL;
	ptr = head;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}
	cout<<count;
}
void print_data(struct node* head)
{
	struct node* ptr = head;
	if(ptr==NULL)
	{
		cout<<"no data"<<endl;
	}
	while(ptr!=NULL)
	{
		cout<<ptr->data<<endl;
		ptr=ptr->link;
	}
}
void add_at_end(struct node *head , int data)
{
	struct node *ptr,*temp;
	ptr=head;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}
	ptr->link=temp;
}
struct node* add_at_end2(struct node *ptr , int data)
{
	struct node *temp =(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	ptr->link=temp;
	 
	 return temp;
}
struct node* add_at_beg(struct node *ptr , int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=ptr;
	ptr=temp;
	
	return ptr ;
}
struct node* add_at_beg2(struct node **head , int data)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data=data;
	ptr->link=*head;
	*head=ptr;
}
void add_at_pos(struct node *head , int data , int pos)
{
	struct node *ptr2=(struct node *)malloc(sizeof(struct node));
	ptr2->data=data;
	ptr2->link=NULL;
	
	struct node *ptr = head;
	int i = 1;
	while(i<pos-1)
	{
		ptr=ptr->link;
		i++;
	}
	
	ptr2->link=ptr->link;
	ptr->link=ptr2;
	
}
void del_at_beg(struct node **head )
{   
     if(head==NULL)
	cout<<"linked list is already empty";
	struct node *del= *head;
	*head=(*head)->link;
	del->link=NULL;
	del=NULL;
	delete(del);
}
struct node* del_at_beg2(struct node *head)
{
	if(head==NULL)
	cout<<"linked list is already empty";
	struct node *del = head;
	head=(head)->link;
	del->link=NULL;
	del=NULL;
	free(del);//delete(del) also works
	return head;
}
void del_at_end(struct node *head)
{
	if(head==NULL)
	cout<<"list is empty"<<endl;
	
	else if(head->link == NULL)
	{
		head==NULL;
		free(head);
	}

	struct node *temp = head;
	struct node *temp2 = head;
    while(temp->link != NULL)
    {
    	temp2=temp;
    	temp=temp->link;
	}

	temp2->link=NULL;
	temp=NULL;
	delete(temp);
}
void del_at_end2(struct node *head)
{
		if(head==NULL)
	cout<<"list is empty"<<endl;
	
	else if(head->link == NULL)
	{
		head==NULL;
		free(head);
	}
	
	struct node *temp = head;
	while(temp->link->link != NULL)
	{
		temp=temp->link;
	}
	free(temp->link);
	temp->link=NULL;
}
struct node* del_at_beg(struct node *head)
{
	struct node *temp = head;
	head=head->link;
	temp->link=NULL;
	temp=NULL;
	free(temp);
	return head;
}
void del_at_pos(struct node **head , int pos )
{
	 struct node *current = *head ;
	 struct node *previous = *head;
	 
	 if(*head == NULL){
	  cout<<"list is already empty"<<endl;return;}
	  
	  else if(pos == 1)
	  {
	  	*head = current->link;
	  	free(current);
	  	current = NULL;
	  	return;
	  }
	
	  while(pos>1)
	  {
	  	previous= current;
	  	current = current->link;
	  	pos--;
	  }
	 previous->link=current->link;
	 free(current);
	 current=NULL;
}
void del_link(struct node **head )
{
	struct node *temp = *head;
	while((*head)!=NULL)
	{
		*head=temp->link;
		free(temp);
		temp=*head;
	}
}
struct node* rev_link(struct node *head)
{
	struct node *prev = NULL;
	struct node *next= NULL;
	
	while(head!=NULL)
	{
		next=head->link;
		head->link=prev;
		prev=head;
		head=next;
	}
	head=prev;
	return head;
}
int main()
{
	
	struct node *head = (struct node *)malloc(sizeof(struct node));
	head->link=NULL;
    head->data=45;
       
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data = 98;
    temp->link=NULL;
    head->link=temp;
    //cout<<head->link->data; */
    
   head->link->link=(struct node*)malloc(sizeof(struct node));
    head->link->link->data=3;
    head->link->link->link=NULL;
   // cout<<head->link->data;
   // cout<<head->link->link->data;
    
   temp=(struct node*)malloc(sizeof(struct node));
    temp->data=3;
    temp->link=NULL;
    head->link->link=temp; 
  //  cout<<head->link->data;
  //  cout<<head->link->link->data;
  //count_of_nodes(head);
  //print_data(head);
 // add_at_end(head,67);
 // print_data(head);
 //*******************************************for O(1) timecomplexity ***************************************************************************//
/* struct node *head = (struct node*)malloc(sizeof(struct node));
 head->data=45;
 head->link=NULL;
 
 struct node *ptr = head;
 ptr = add_at_end2(ptr,98);
 ptr = add_at_end2(ptr,3);
 ptr = add_at_end2(ptr,67);
 print_data(head);*/
 //***********************************************************************************************************************************************//
 //head = add_at_beg(head,3);
 //   add_at_beg2(&head,3);
  //  print_data(head);
 //head =  del_at_beg2(head);
    print_data(head);
   // head=del_at_beg(head);
 //   del_at_end2(head);
   // del_link(&head);
   head=rev_link(head);
   
    print_data(head);
    
}
 
