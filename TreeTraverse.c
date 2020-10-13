#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *right,*left;
};
struct node *insert(int data){
    struct node* node=(struct node*)malloc(sizeof(struct node));
   node->data=data;
   node->left=NULL;
   node->right=NULL;

   return(node); 
}

int preorder(struct node* node){
    if(node==NULL){
        return;
    }

    printf("%d ",node->data);
    preorder(node->left);
    preorder(node->right);
}

int postorder(struct node* node){
    if(node==NULL){
        return;
    }

    postorder(node->left);
    postorder(node->right);
    printf("%d ",node->data);
}

int Inorder(struct node* node){
    if(node==NULL){
        return;
    }

    Inorder(node->left);
    printf("%d ",node->data);
    Inorder(node->right);
}

void main(){
    struct node *root = insert(1);
    root->left=insert(4);
    root->right=insert(5);
    root->left->right=insert(6);
    root->left->left=insert(9);
    root->right->left=insert(10);
    root->right->right=insert(15);
 
    printf("preorder traversal of tree is %d\n",preorder(root));
       printf("postorder traversal of tree is %d\n",postorder(root));
          printf("Inorder traversal of tree is %d\n",Inorder(root));
}