#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *create_bt() {
    struct node *p;
    p = (struct node *) malloc(sizeof(struct node));
    int key;
    printf("Enter the key value ");
    scanf("%d", &key);

    if (key == -1) {
        return NULL;
    }

    p->data = key;

    printf("Enter the left child of key %d: \n", key);
    p->left = create_bt();

    printf("Enter the right child of key %d: \n", key);
    p->right = create_bt();

    return p;
};

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int Countnodes(struct node *root)
{
    if(root==NULL)
        return 0;
    else
        return 1 + Countnodes(root->left) + Countnodes(root->right);
}

// counting no of leafcodes

int leaf_nodes(struct node*root){

    if(root==NULL)
        return 0;
    if(root->left==NULL&& root->right==NULL)
        return 1;
    return leaf_nodes(root->left)+leaf_nodes(root->right);
        }
// height of tree

int height(struct node*root){

    if(root==NULL)
      return -1;
    int leftheight = height(root->left);
    int rightheight = height(root->right);

    if(leftheight>rightheight)
        return 1+leftheight;
    else
        return 1+rightheight;
}
void main(){
    struct node*root;
    root = NULL;
    root = create_bt();
    printf("inorder traversal of tree\t");
    inorder(root);
    printf("\n");
    printf("preorder traversal of tree\t");
    preorder(root);
    printf("\n");
    printf("postorder traversal of tree\t");
    postorder(root);
    printf("\n");
    printf("Number of Nodes in tree %d",Countnodes(root));
    printf("\n");
     printf("Number of  Leaf Nodes in tree %d",leaf_nodes(root));
    printf("\n");
     printf("Height of the tree %d",height(root));
    printf("\n");
    }
