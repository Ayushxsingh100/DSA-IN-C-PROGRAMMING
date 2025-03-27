#include<stdio.h>
#include<stdlib.h>

typedef struct tree {
    int data;
    tree* left;
    tree* right;
}tree;

tree* initT(tree* pt , int data){
    pt = (tree*)malloc(sizeof(tree));
    pt->data=data;
    pt->left = NULL;
    pt->right = NULL;
}

tree* createTnode(int data){
    tree* pt;
    pt = (tree*)malloc(sizeof(tree));
    pt->data=data;
    pt->left = NULL;
    pt->right = NULL;
    return pt;
}

tree* insertleft ( tree* pt , int data){
    pt -> left = createnode(data);
}

tree* insertright ( tree* pt , int data){
    pt -> right = createnode(data);
}

int main(){
    tree *mytree = NULL;
    mytree = initT(mytree , 100);
    insertleft(mytree,200);
    insertright(mytree,300);
    insertleft(mytree->left,400);
    insertleft(mytree->right,400);
    insertright(mytree->right,500);
}