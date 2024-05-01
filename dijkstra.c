#include<stdio.h>
int cost[6][6]={
{0,2,4,999,999,999},
{999,0,1,7,999,999},
{999,999,0,999,3,999},
{999,999,999,0,999,8},
{999,999,999,999,0,5},
{999,999,999,999,999,0}
};
void dijkstra(int v,int n)
{
    int i, j, u, w, count, min;
    int dist[10], visit[10]={0};
       visit[v]=1;
                for(i=0;i<n;i++)
                {
                              dist[i]=cost[v][i];
                              printf("\ndist[%d]=%d", i, dist[i]);
                             }
                        count=2;
                        while(count<n)
                        {
                               min=999;
                             for(i=0;i<n;i++)
                                       if(visit[i]==0 && dist[i]<min)
                                       {
                                                    min=dist[i];
                                                    u=i;
                                                       printf("\n min=%d, i=%d, u=%d", min,i,u);
                                       }
                                       //printf("\n selected -> u=%d", u);
                                     visit[u]=1;
                                     for(w=0;w<n;w++)
                                          if(dist[u]+cost[u][w]<dist[w])
                                              dist[w]=dist[u]+cost[u][w];
                                                        count++;
                      }
                      printf("\n shortest distance from vertex %d are:\n", v);
                      for(i=0;i<n;i++)
                      printf("%d\t", dist[i]);
 }
 
 void main()
 {
   dijkstra(3,6);
 }                                                                                   
 
 
