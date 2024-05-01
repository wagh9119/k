#include<stdio.h>
#include<stdlib.h>
int hf(int key, int i)
{
return(key %10+1) %10;
}
void insert(int ht[10], int key)
{
int i, index;
for(int i=0;i<10;i++)
{
index=hf(key,i);
if(ht[index]==-1)
{
    ht[index]=key;
    return;
 }
 }
 printf("\n could not insert key %d", key);
}
int search(int ht[10], int key)
{
int i, index;
for(i=0;i<10;i++)
{
index=hf(key,i);
if(ht[index]==key)
return index;
}
return -1;
}

void delete_key(int ht[10], int key)
{
int index;
index=search(ht, key);
if(index==-1)
printf("key %d not found", key);
else
ht[index]=-1;
}
void showtable(int ht[10])
{
int i;
for(i=0;i<10;i++)
printf("%d [%d] \n", i, ht[i]);
}

int main()
{
int ht[10], choice, key, index;
for(int i=0;i<10;i++)
ht[i]=-1;
do
{
      printf("\n 1: Insert \n2: Search \n 3: delete \n 4: Exit");
      printf("\n enter your choice");
      scanf("%d", &choice);
      switch(choice)
      
      {
       case 1:
               printf("\n enter the key to be inserted");
               scanf("%d", &key);
               insert(ht, key);
               showtable(ht);
               break;
          
       case 2:
                printf("\n enter the key to be searched:");
                scanf("%d", &key);
                index=search(ht,key);
                if(index==-1)
                        printf("\n %d not found", key);
                        else
                        printf("%d found at position %d", key, index);
                break;
                
        case 3:
                printf("\n enter the key to be deleted");
                scanf("%d", &key);
                delete_key(ht, key);
                showtable(ht);
       }
  }while(choice!=4);
  return 0;
}
       
                                   
                  
               
