#define MAXSIZE 20

typedef struct node
{
            struct node *left;
            int info;
            struct node *right;
}NODE;

typedef struct
{
       NODE *data[MAXSIZE];
       int front, rear;
}QUEUE;

void initq(QUEUE *pq)
{
 
        pq->front=pq->rear=-1;
        
}
void addq(QUEUE *pq, NODE *treenode)
{
        pq->data[++pq->rear]=treenode;
}

NODE  *removeq(QUEUE *pq)
{
     return pq->data[++pq->front];
}
int isempty(QUEUE *pq)
{
     return(pq->front==pq->rear);
}

int isfull(QUEUE *pq)
{
     return(pq->rear==MAXSIZE-1);
}

void levelorder(NODE *root)
{
      int level=0;
      NODE  *temp, *marker=NULL;
          QUEUE q;
          initq(&q);
          
          addq(&q, root);
          addq(&q, marker);
          printf("\n Level %d--->", level);
          while(!isempty(&q))
               {
                          temp=removeq(&q);
                          if(temp==marker)
                          {
                                           level++;
                                           if(!isempty(&q))
                                           {
                                                         addq(&q, marker);
                                                         printf("\n level %d--->", level);
                                           }
                          }
                          else
                          {
                                            printf("%d\t", temp->info);
                                            if(temp->left)
                                                          addq(&q, temp->left);
                                            if(temp->right)
                                                           addq(&q, temp->right);
                          }
              }
}

NODE *createbst(NODE *root)
{
                NODE *newnode, *temp;
                int i,n, num;
                
                printf("\n How many node you want to insert? \n");
                scanf("%d", &n);
                
                for(i=1;i<=n;i++)
                {
                              newnode=(NODE*)malloc(sizeof(NODE));
                              printf("\n Enter the element: \t");
                              scanf("%d", &num);
                              newnode->info=num;
                              newnode->left=newnode->right=NULL;
                              if(root==NULL)
                              root=newnode;
                              else
                              { 
                                           temp=root;
                                         while(1)
                                               { 
                                                        if(num<temp->info)
                                                            {
                                                                        if(temp->left==NULL)
                                                                             {
                                                                                       temp->left=newnode;
                                                                                       break;
                                                                              }                                                                    
                                                                         else
                                                                             temp=temp->left;
                                                            }
                                                      else
                                                      if(temp->right==NULL)
                                                           {    
                                                                     temp->right=newnode;
                                                                     break;
                                                           }
                                                      else
                                                          temp=temp->right;
                                              }
                                     }                                                                                       
                            }
                         return(root);
}

void Display(NODE *root)
{
          if(root!=NULL)
                       {
                                           printf("\t%d", root->info);
                                           Display(root->left);
                                           Display(root->right);
                       }
}                                           
                                                                                                                                                                               
