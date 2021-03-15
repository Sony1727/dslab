#include<stdio.h>
int set1[10],set2[10],set3[20],max,m,n;
void insert(int[],int,int);
void display(int[],int);
void intersection(int[],int[]);
void setunion(int[],int[]);
void difference(int[],int[]);
void main()
{
int i,element;
clrscr();
printf("\n no of element set1:");
scanf("%d",&n);
printf("\n no of element set2:");
scanf("%d",&m);
max=m+n;
printf("\n enter first set");
for(i=0;i<n;i++)
{
scanf("%d",&element);
insert(set1,i,element);
}
printf("\n enter second set");
for(i=0;i<m;i++)
{
scanf("%d",&element);
insert(set2,i,element);
}
clrscr();
printf("\n the set are:");
display(set1,n);
display(set2,m);
printf("\n the intersection of these set are");
intersection(set1,set2);
printf("\n the union of these set are:");
setunion(set1,set2);
printf("\n the set difference of these set are:\n set1-set2");
difference(set1,set2);
getch();
}
void insert(int data[],int count,int element)
{
data[++count]=element;
}
void display(int set[],int num)
{
int i;
printf("\n");
for(i=1;i<=num;i++)
printf("%d\t",set[i]);
}
void intersection(int s1[],int s2[])
{
int i,j,x=-1;
for(i=1;i<=n;i++)
{
for(j=1;j<=m;j++)
{
if(s1[i]==s2[j])
insert(set3,++x,s1[i]);
}
}
display(set3,++x);
}
void setunion(int s1[],int s2[])
{
int i,j,x=-1,flag=0;
for(i=1;i<=n;i++)
{
insert(set3,++x,s1[i]);
}
for(i=1;i<=m;i++)
{
for(j=1;j<=n;j++)
{
if(s2[i]==s1[j])
flag=1;
}
if(flag==0)
insert(set3,++x,s2[i]);
flag=0;
}
display(set3,++x);
}
void difference(int s1[],int s2[])
{
int x=-1,i,j,flag=0;
for(i=1;i<=n;i++)
{
for(j=1;j<=1;j++)
{
if(s1[i]==s2[j])
flag=1;
}
if(flag==0)
insert(set3,++x,s1[i]);
}
display(set3,++x);
}
