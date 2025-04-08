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

struct *preorder(struct * pt ){
    if(pt=! NULL){
        printf("%d" , root-> data);
        preorder(pt->left);
        preorder(pt->right);
    }
}

    struct *postorder(struct * pt ){
        if(pt=! NULL){
            postorder(pt->left);
            postorder(pt->right);
            printf("%d" , root-> data);
        }
}


struct *inorder(struct * pt ){
    if(pt=! NULL){
        inorder(pt->left);
        printf("%d" , root-> data);
        inorder(pt->right);
       
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