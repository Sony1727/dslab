#include<stdio.h>
int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
void bfs(int v)
{
for(i=1;i<=n;i++)
if(a[v][i]&&!visited[i])
q[++r]=i;
if(f<=r)
{
visited[q[f]]=1;
bfs(q[f++]);
}
}
void main()
{
int v;
clrscr();
printf("enter the number of vertices");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
q[i]=0;
visited[i]=0;
}
printf("\n enter graph data in matrix form:\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&a[i][j]);
}
}
printf("/n enter the starting vertex:/n");
scanf("%d",&v);
bfs(v);
printf("\n enter the node which are reachable are:\n");
for(i=1;i<=n;i++)
{
if(visited[i])
{
printf("%d\t",i);
}
else
{
printf("\n bfs is not possible not.All node are reachable");
break;
}
}
getch();
}