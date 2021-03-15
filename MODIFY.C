#include<stdio.h>
int add(int,int);
void main()
{
int a,b,sum;
printf("enter the number");
scanf("%d%d",&a,&b);
sum=add(a,b);
printf("sum=%d",sum);
getch();
}
int add(int x,int y)
{
return(x+y);
}