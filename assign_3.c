#include<stdio.h>
void rdfs(int m[10][10], int n, int v)
{
int w;
static int visit[20]={0};
visit[v]=1;
printf("\nv[%d]",v+1);
         for(w=0;w<n;w++)
          {
                    if((visit[w]==0))
                    {
                          printf("\t");
                          rdfs(m,n,w);
                    }
          }
}
struct queue
{
       int data[20];
       int front, rear;
}q;

void add(struct queue *pq, int n)
{
      pq->rear+++;
      pq->data[pq->rear]=n;
}

int del(struct queue *pq)
{
      pq->front++;
      return(pq->data[pq->front]);
}

void initq(struct queue *pq)
{
      pq->front=pq->rear=-1;
}

int isempty(struct queue *pq)
{
      return(pq->rear==pq->front);
}

void rbfs(int m[10][10], int n)
{
       int i,j,v=0,w=0;
       int visit[20]={0};
       
       initq(&q);
       printf("\nThe BFS of first traversal is:\n");
       v=0;
       visit[v]=1;
       add(&q,v);
       while(!isempty(&q))
       {
              v=del(&q);
              printf("\nv[%d]\t", v+1);
              for(w=0;w<n;w++)
              {
                    if((m[v][w]==1)&&(visit[w]==0))
                    {
                         add(&q,w);
                         visit[v]=1;
                    }
              }
        }
        printf("\n");
}

void main()
{
       int i,j,n,m[10][10], ind, outd, total,v=0;
       void rbfs(int m[10][10], int n);
       
       printf("\n Enter no. of vertex in graph:");
       scanf("%d", &n);
       printf("\n Enter adjacency matrix:");
       for(i=0;i<n;i++)
       for(j=0;j<n;j++)
             scanf("%d", &m[i][j]);
       for(i=0;i<n;i++)
       {
              for(j=0;j<n;j++)
              {
                    if(1!=j)
                    {
                         printf("\nIs the edge present between %d & %d(1,0)", i+1, j+1);
                         scanf("%d", &m[i][j]);
                    }
              }
       }
       printf("\nAdjacency matrix is:\n");
       for(i=0;i<n;i++)
       {
              for(j=0;j<n;j++)
              {
                      printf("%5d", m[i][j]);
              }
              printf("\n");
       }
       printf("\nIndegree, Outdegree & Total degree:");
       for(i=0;i<n;i++)
       {
           for(j=0,ind=0,outd=0;j<n;j++)
           {
                 if(m[i][j]==1)
                 outd++;
                 if(m[j][i]==1)
                 ind++;
                 total=ind+outd;
            }
            printf("\nv%d %5d %5d %5d\n", i+1, ind, outd, total);
           }
           
           printf("\nThe recursive DFS is:\n");
           rdfs(m,n,v);
           rdfs(m,n);
}                                                                                                                             
