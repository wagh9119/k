#include<stdio.h>
#include<stdlib.h>
void heapsort(int a[], int n);
void Heapify(int a[], int i, int last);
void BuildHeap(int a[], int n);
void display(int a[], int n);

void heapsort(int a[10], int n)
{
                     int i, temp;
                     BuildHeap(a,n);
                     printf("\n initial heap:\n");
                     display(a,n);
         
     for(i=n-1;i>=1;i--)
     {
                     temp=a[0];
                     a[0]=a[i];
                     a[i]=temp;
                     
                     printf("\n After Iteration %d:", n-i);
                     display(a,n);
                     Heapify(a,0,i-1);
     }
}

void BuildHeap(int a[], int n)
{
                      int i;
                      for(i=(n/2)-1; i>=0; i--)
                        Heapify(a,i,n-1);
}

void Heapify(int a[], int i, int last)
{
                      int j, temp, key;
                      
                      key=a[i];
                      j=2*i+1;
                      
                      if((j<last)&&(a[j]<a[j+1]))
                      j=j+1;
                      
                      if((j<=last)&&(key<a[j]))
                      
                      {
                                        temp=a[i];
                                        a[i]=a[j];
                                        a[j]=temp;
                                        Heapify(a,j,last);
                      }
}                                  
                        
void display(int a[], int n)
{
         for(int i=0;i<=n;i++)
            printf("\n %d", a[i]);
}



int main()
{
     int a[10], n,i;
     
                printf("\n How many elements in an array?");
                scanf("%d", &n);
                
                printf("\n Enter %d element in an array", n);
                
                for(i=0;i<n;i++)
                scanf("%d", &a[i]);
                heapsort(a,n);
                printf("\n The sorted elements are:");
                display(a,n);
                return 0;
}                                                                                               
                     
                
