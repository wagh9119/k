#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
            int vertex;
            struct node *next;
}NODE;
NODE *list[10];

void create(int m[10][10], int n)
{
              int i,j;
              char ans;
              for(i=0;i<n;i++)
              for(j=0;j<n;j++)
                           {
                                         m[i][j]=0;
                                         if(i!=j)
                                         {
                        printf("\n Is there an edge between %d and %d (1/0): \t",i+1, j+1 );
                                scanf("%d", &m[i][j]);
                                         }
                            }
}

void display(int m[10][10], int n)
{
             int i,j;
             printf("\n The Adjacency Matrix is:\t");
             for(i=0;i<n;i++)
                        {
                                        for(j=0;j<n;j++)
                                                     {
                                                               printf("%5d", m[i][j]);
                                                               printf("\n");
                                                     }
                        }
}

void create_list(int m[10][10], int n)
{
            int i,j;
            struct node *temp, *newnode;
            for(i=0;i<n;i++)
                         {
                                     list[i]=NULL;
                                     for(j=0;j<n;j++)
                                     {
                                                 if(m[i][j]==1)
                                                 {
                                      newnode=(struct node*)malloc(sizeof(struct node));
                                                                    newnode->next=NULL;
                                                                    newnode->vertex=j+1;
                                                                    if(list[i]==NULL)
                                                                    list[i]=temp=newnode;
                                                                    else
                                                                    {
                                                                    temp->next=newnode;
                                                                    temp=newnode;
                                                                    }
                                                  }
                                      }
                         }
}

void display_list(int n)
{
             int i;
             struct node *temp;
             printf("\n The adjacency list is: \t");
             for(i=0;i<n;i++)
                          {
                                      printf("\n v%d->", i+1);
                                      temp=list[i];
                                      while(temp)
                                                     {
                                                      printf("v%d ->", temp->vertex);
                                                      temp=temp->next;
                                                      }
                                      printf("NULL");
                           }
}

void recdfs(int m[10][10], int n, int v)
{
          int i;
          
          static int visited[20]={0};
          visited[v]=1;
          printf("v%d", v+1);
          for(i=0;i<n;i++)
          {
               if((m[v][i]==1)&&(visited[i]==0))
                     recdfs(m,n,i);
          }
}
void main()
{
          int m[10][10], n;
          printf("\n Enter the number of vertices :\t");
          scanf("%d", &n);
          create(m,n);
          display(m,n);
          create_list(m,n);
          display_list(n);
          recdfs(m,n,0);
          
 }           
                                                                                                                                                                                                                                                               
