#include<stdio.h>
#include<stdlib.h>
struct node
{
int value;
struct rep*repptr;//pointer to head node of the list
struct node* next;
};
//represent header node of linked representation
struct rep{
struct node*head;
struct node*tail;
};
//struct to store key and obj node pointer
struct nodaddr
{
int key;
struct node*obj_node_ptr;
struct nodaddr*next;
};
struct nodaddr* ndr=0;

//function to create a set
void makeset(int a)
{
struct nodaddr *t=(struct nodaddr*)malloc(sizeof(struct nodaddr));
 //new set
struct rep * newset=(struct rep*)malloc(sizeof(struct rep));
struct node * n=(struct node*)malloc(sizeof(struct node));
 //find values
n->value=a;
n->repptr=newset;
n->next=0;
 //intialise head and tail
newset->head=newset->tail=n;
 //to store object node pointer and key
t->obj_node_ptr=n;
t->key=a;
t->next=ndr;
ndr=t;
}
//function to return pointer of representative of the set
//containingx
struct re*find(int x)
{
struct nodaddr*t=ndr;
while(t!=0 && t->key!=x)
t=t->next;
return t->obj_node_ptr->repptr;
}
//union of set
void unionset(int key1,int key2)
{
struct rep*set1,*set2;
struct node*t1;
set1=find(key1);
set2=find(key2);
if(set1==set2)
printf("\n %d and %d belongs to same set \n",key1,key2);
else
{
//changing header points of objects of set2 to set1
t1=set2->head;
while(t1!=0)
{
t1->repptr=set1;
t1=t1->next;
}
set1->tail->next=set2->head;
set1->tail=set2->tail;
free(set2);
}
}
//function to display
void display_set(int a)
{
struct rep*r;
struct node*t;
r=find(a);
t=r->head;
printf("set numbers containg %d;",a);
while(t!=0)
{
printf("%d,",t->value);
t=t->next;
}
}
main()
{
 makeset(10);
 makeset(20);
 makeset(30);
 makeset(40);
 printf("find(10)=% X",find(10));
 printf("\n find(20)=% X",find(20));
 printf("\n find(30)=% X",find(30));
 printf("\n find(40)=% X",find(40));
 unionset(10,20);
 printf("\n after union of 10&20 find (20)=% X",find(20));
 unionset(30,40);
 printf("\n after union of 30&40 find (40)=% X",find(40));
 unionset(20,40);
 printf("\n after union of set containg 20 and set containg 40 find(40)=% X \n", find(40));
 display_set(40);
 }
 
 
 
 
 
 
 


