typedef struct node
{
         struct node *left;
         int info;
         struct node *right;
}NODE;

NODE *createbst(NODE *root)
{ 
                  NODE *newnode, *temp;
                  int i, n, num;
                  printf("\n How many nodes to be inserted?");
                  scanf("%d", &n);
                  for(i=1;i<=n;i++)
                       {
                               newnode=(NODE*)malloc(sizeof(NODE));
                               printf("\n Enter the element:");
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
                                
NODE* Insertbst(NODE *root, int num)
{
     NODE *nn, *temp;
     nn=(NODE *)malloc(sizeof(NODE));
     nn->info=num;
     nn->left=nn->right=NULL;
     if(root==NULL)
          root=nn;
          else
          {
          temp=root;
          while(1)
          {
             if(num<temp->info)
             {
              if(temp->left==NULL)
              {
              temp->left==nn;
              break;
              }
              else
                 temp=temp->left;
               }
               else
                 if(temp->right==NULL)
                 {
                     temp->right=nn;
                     break;
                 }
                  else
                   temp=temp->right;
                 }
               }
             return(root);
}
 
 NODE* Search(NODE *root, int n)
{
             NODE *temp=root;
             while(temp!=NULL)
                            {
                                                 if(temp->info==n)
                                                               {
                                                                               printf("Element found");
                                                                               return temp;
                                                                }
                                                 if(n<temp->info)
                                                                temp=temp->left;
                                                 else
                                                                 temp=temp->right;
                             }
                  printf("Element not found \n");
}                                                                                                                                                                   
                
void preorder(NODE *root)
    {
               if(root!=NULL)
               {
                          printf("%d\t", root->info);
                          preorder(root->left);
                          preorder(root->right);
                }
     }
void inorder(NODE *root)
{
               if((root!=NULL))
               {
                           inorder(root->left);               
                           printf("%d\t", root->info);
                           inorder(root->right);                                                                                        
                }
}

void postorder(NODE *root)
{
                 if(root!=NULL)
                 {
                            postorder(root->left);
                            postorder(root->right);
                            printf("%d\t", root->info);
                 }
}

           
int count_nodes(NODE *root)
{
    static int count=0;
    NODE *temp=root;
    if(temp!=NULL)
    {
        count++;
        count_nodes(temp->left);
        count_nodes(temp->right);
    }
      return(count);
 }         
 
 int count_leaf_nodes(NODE *root)
   {
         static int count=0;
         NODE *temp=root;
         if(temp!=NULL)
                         {
                           if(temp->left==NULL && temp->right==NULL)
             ++count;
             count_leaf_nodes(temp->left);
             count_leaf_nodes(temp->right);
         }
            return(count);
   }             
            
NODE *treecopy(NODE* root)
{
  NODE *nn;
  if(root!=NULL)
  {
       nn=(NODE*)malloc(sizeof(NODE));
       nn->info=root->info;
       nn->left=treecopy(root->left);
       nn->right=treecopy(root->right);
  }
  else
    return (NULL);
  }              
  
int compare(NODE *root, NODE *root1)
{
    if(root==NULL && root1==NULL)
    return -1;
       else
          if(root!=NULL && root1!=NULL)
            if(root->info==root1->info)
              if(compare(root->left, root1->left))
                 return(compare(root->right, root1->right));
                 return 0;
}                   
        
 void mirror(NODE *root)
 {
     NODE *temp=root, *temp1;
     if(temp!=NULL)
     {
        if(temp->left!=NULL)
           mirror(temp->left);
        if(temp->right!=NULL)
            mirror(temp->right);
         temp1=temp->left;
         temp->left=temp->right;
         temp->right=temp1;
    }
}         
  
int sumOdd(NODE *node)
{
        int sum=0;
        if(node!=NULL)
        {
             if((node->info%2)!=0)
                   sum+=node->info;
                   sum+=sumOdd(node->left);
                   sum+=sumOdd(node->right);
        }
        return sum;
}                                         

int sumEven(NODE *node1)
{
    int sum=0;
    if(node1!=NULL)
    {
        printf("node:%d", node1->info);
        if((node1->info%2)==0)
            sum+=node1->info;
            sum+=sumEven(node1->left);
            sum+=sumEven(node1->right);
    }
    return sum;     
 }      
 
 NODE *Delete(NODE *root, int num)
 {
        NODE *temp=root, *parent=NULL, *r, *father;
        
        if((temp!=NULL)&&(temp->info==num))
        {
        if(temp->left==NULL && temp->right==NULL)
        {
                free(temp);
        }
  }
  else
  {
             while((temp!=NULL)&&(temp->info!=num))
             {
                     parent=temp;
                     if(num<temp->info)
                     temp=temp->left;
                     else
                     temp=temp->right;
             }
             
                if(temp==NULL)
                return root;
                if(temp->left==NULL)
                r=temp->right;
                    else
                if(temp->right==NULL)
                    r=temp->left;
                    else
                    {
                                 father=temp;
                                 r=father->right;
                                 while(r->left!=NULL)
                                 {
                                             father=r;
                                             r=r->left;
                                 }
                                 if(father!=temp)
                                 {
                                 father->left=r->right;
                                 r->right=temp->right;
                                 }
                                     r->left=temp->left;
                     }
                     
                     if(parent==NULL)
                                    root=r;
                     else
                                  if(parent->left==temp)
                                  parent->left=r;
                                  else
                                  parent->right=r;
                                  
                    free(temp);
                    return root;
               }
      }                                                                                               
