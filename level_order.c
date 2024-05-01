#include<stdio.h>
#include<stdlib.h>
#include "level_order.h"
#define MAXSIZE 20

void display();
void levelorder(NODE *root);

void main()
{
        int n,num,osum,esum,ch;
        NODE *root=NULL, *root1=NULL;
        printf("First create BST");
        root=createbst(root);
        root1=root;
        printf("\n Level order traversal is");
        levelorder(root);
}        

