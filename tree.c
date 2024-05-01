#include<stdio.h>
#include<stdlib.h>
#include "tree.h"

void main()
{
          int n,ch,num;
          NODE *root=NULL, *root1=NULL;
          do
          {     
                       printf("\n 1: For create");
                       printf("\n 2: insert");
                       printf("\n 3: search");                    
                       printf("\n 4: preorder");
                       printf("\n 5: inorder");
                       printf("\n 6: postorder");
                       printf("\n 7: count total nodes:");
                       printf("\n 8: count leaf nodes:");
                       printf("\n 9: copy:");
                       printf("\n 10: compare:");
                       printf("\n 11: mirror image of tree");
                       printf("\n 12: sumodd");
                       printf("\n 13: sumeven");
                       printf("\n 14: delete");
                      
                       
                      
                       
                    
                       
                       printf("\n Enter your choice:");
                       scanf("%d", &ch);
                       switch(ch)
                       { 
                                       case 1:           root=createbst(root);
                                                              break;
                       
                                       case 2:            printf("\n Enter element to be inserted:");
                                                               scanf("%d", &n);
                                                               Insertbst(root,n);
                                                               break;  
                        
                                       case 3:            printf("Enter element to be searched:");
                                                               scanf("%d", &n);
                                                               Search(root,n);
                                                               break;
                                                                                                                                                
                                       case 4:            printf("Preorder traversal:\t");			
                                                               preorder(root);
                                                               break;
                                                                                                                                                                                              
                                       case 5:             printf("Inorder traversal:\t");
                                                               inorder(root);
                                                               break;
                                                               
                                       case 6:             printf("Postorder traversal:\t");
                                                               postorder(root);
                                                               break;
                                   
                                       case 7:             printf("total no of nodes is %d", count_nodes(root));
                                                               break;
                                                               
                                       case 8:             printf("\n total no of leaf node is %d", count_leaf_nodes(root));
                                                                break;                        
                                                                                                                                                                                             
                                       case 9:            treecopy(root);
                                                               printf("\n copied");
                                                               preorder(root);
                                                               break;   
                                                               
                                       case 10:        
                                                              
                                                               printf("\n enter second tree node");
                                                               root1=createbst(root1);
                                                               
                                                               if(compare(root,root1))
                                                               printf("\n trees are not equal");
                                                               else
                                                               printf("\n trees are equal");
                                                               break;
                                                               
                                        case 11:          mirror(root);
                                                               inorder(root);
                                                               break;
                                        
                                        
                                        case 12:          printf("\n sum of odd no %d", sumOdd(root));
                                                                break;
                                                                
                                        case 13:          printf("\n sum of even no:%d",sumEven(root));
                                                                break;
                                                                
                                        case 14:          printf("\n enter the element you want to delete:");
                                                                scanf("%d", &num);
                                                                Delete(root,num);
                                                                preorder(root);
                                                                break;
                                                                                                                
                                                                                                                                        
                       }
              }                                              
            while(ch<=14);
}                                                                              
