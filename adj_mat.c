#include<stdio.h>
int main()
{
int a[10][10],i,j,n;

printf("\nEnter total no. of vertices: ");
scanf("%d",&n);
printf("\n*PRESS 1 FOR YES(edge present) & 0 FOR NO(edge not present)*\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++){
a[i][j]=0;
if(i!=j)
{
printf("\nIs there edge between v%d & v%d: ",i+1,j+1);
scanf("%d",&a[i][j]);
}
}
}

printf("\n Matrix is \n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n");
}
}








