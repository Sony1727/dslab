#include<math.h>
#include<stdio.h>
#include<stdlib.h>
 struct NODE
{
int key;
int degree;
struct NODE*left_sibling;
struct NODE*right_sibling;
struct NODE*parent;
struct NODE*child;
int mark;
int visited;
}
NODE;
struct FIB_HEAP
{
int n;
struct NODE*min;
int phi;
int degree;
}
FIB_HEAP;
struct FIB_HEAP*make_fib_heap();
void insertion(struct FIB_HEAP*H,struct NODE*new,int val);
struct NODE*find_min_node(struct FIB_HEAP*H);
struct FIB_HEAP*make_fib_heap()
{
struct FIB_HEAP*H=(struct FIB_HEAP*)malloc(sizeof(struct FIB_HEAP));
H->n=0;
H->min=NULL;
H->phi=0;
H->degree=0;
//printf("node created n=%d min=%d phi=%d degree=%d",H->n,H->min,H->phi,H->degree);
return H;
}
void print_heap(struct NODE*n)
{
struct NODE*x;
for(x=n;;x=x->right_sibling)
{
if(x->child==NULL)
{
printf("node with no child(%d) \n",x->key);
}
else
{
printf("Node(%d)with child (%d)\n",x->key,x->child->key);
print_heap(x->child);
}
if(x->right_sibling==n)
{
break;
}
}
}
void insertion( struct FIB_HEAP*H,struct NODE*new,int val)
{
new=(struct NODE*)malloc(sizeof(struct NODE));
new->key=val;
new->degree=0;
new->mark=0;
new->parent=NULL;
new->child=NULL;
new->visited=0;
new->left_sibling=new;
new->right_sibling=new;
if(H->min==NULL)
{
H->min=new;
}
else
{
H->min->left_sibling->right_sibling=new;
new->right_sibling=H->min;
new->left_sibling=H->min->left_sibling;
H->min->left_sibling=new;
if(new->key<H->min->key)
{
H->min=new;
}
}
//printf("node created n=%d min=%d phi=%d degree=%d",H->n,H->min,H->phi,H->degree;
(H->n)++;
}
struct NODE*find_min_node(struct FIB_HEAP*H)
{
if(H==NULL)
{
printf("\n Fibonacci heap not yet created \n");
return NULL;
}
else
return H->min;
}
int main()
{
struct NODE*new_node,*min_node;
struct FIB_HEAP*heap,*h1,*h2;
int operation_no,new_key,dec_key,ele,i,no_of_nodes;
heap=(struct FIB_HEAP*)malloc(sizeof(struct FIB_HEAP));
heap=NULL;
while(1)
{
printf("\n operation \n 1.create fibanocci heap \n 2.insert node into fibanocci heap \n 3.find min \n 4.print \n <press any other key to exit>");
scanf("%d",&operation_no);
switch(operation_no)
{
case 1:
heap=make_fib_heap();
printf("an empty node is created");
break;
case 2:
if(heap==NULL)
{
heap=make_fib_heap();
}
printf("enter the no:of nodes to be insert=");
scanf("%d",&no_of_nodes);
for(i=1;i<=no_of_nodes;i++)
{
printf("\n nodes %d and its key value=",i);
scanf("%d",&ele);
insertion(heap,new_node,ele);
}
break;
case 3:
min_node=find_min_node(heap);
if(min_node==NULL)
printf("no minimum value");
else
printf("\n min value=%d",min_node->key);
break;
case 4:
print_heap(heap->min);
break;
default:
printf("invalid choice");
exit(0);
return;
}
}
}


