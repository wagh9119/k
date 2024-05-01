#include<stdio.h>
#define n 4
void primtamatrix(int matrix[n][n])
{
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if(matrix[i][j]==999)
printf("%4s","INF");
else
printf("%4d",matrix[i][j]);
}
printf("\n");
}
}
void floydarshall(int matrix[][n])
{
int i,j,k;
for(k=0;k<n;k++)
{
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(matrix[i][k]+matrix[k][j]<matrix[i][j])
matrix[i][j]=matrix[i][k]+matrix[k][j];
}
}
}
primtamatrix(matrix);
}
int main()
{
int matrix[4][4]={{0,8,999,1},
		 {999,0,1,999},
		 {4,999,0,999},
		 {999,2,9,0}};
		 
floydarshall(matrix);
}		 





