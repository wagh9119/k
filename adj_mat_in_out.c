#include<stdio.h>
#include<stdlib.h>
void display(int m[10][10], int n);
void print_in_out_degree(int m[10][10], int n);
void create(int m[10][10], int n);

void display(int m[10][10], int n)
{
         int i,j;
         printf("\n The adjacency matrix is:\t");
         for(i=0;i<n;i++)
               {
                         for(j=0;j<n;j++)
                                    { 
                                            printf("%5d", m[i][j]);
                                    }
                                    printf("\n");
               }
}

void print_in_out_degree(int m[10][10], int n)
{
int i, j, ind, outd, total;
      printf("\nIndegree, Outdegree & Total degree:");
    for(i=0;i<n;i++)
    {
           for(j=0,ind=0, outd=0; j<n; j++)
           {
                if(m[i][j]==1)
                outd++;
                if(m[j][i]==1)
                ind++;
                total=ind+outd;
           }
           printf("\nv%d %5d %5d %5d\n", i+1, ind,outd,total);
    }
}

void create(int m[10][10], int n)
{
             int i,j;
             char ans;
             for(i=0;i<n;i++)
             for(j=0;j<n;j++)
                          {
                                       m[i][j]=0;
                                       if(1!=j)
                                                   {
                                                            printf("\n Is there an angle between %d and %d (1/0): \t", i+1, j+1);
                                                            scanf("%d", &m[i][j]);
                                                   }
                          }
}

void main()
{
             int m[10][10], i,j, total, ind, outd, n;
             printf("\n Enter the number of vertices :\t");
             scanf("%d", &n);
             create(m,n);
             display(m,n);
             print_in_out_degree(m,n);
}          







                                                                 
                                                                          
                                                              
