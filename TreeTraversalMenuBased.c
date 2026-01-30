#include <stdio.h>
#include <stdlib.h>
// Define the structure for a binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Function for inorder traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function for preorder traversal
void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function for postorder traversal
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
main()
{
      Node* root=NULL;
      int num, val, ch;
      printf("\n***************Creating a Binary Tree***************\n");
      printf("Enter the number of nodes in the tree: ");
      scanf("%d", &num);
    printf("\nEnter the root node value: ");
    scanf("%d", &val);
    root=createNode(val);
	root->left = createNode(50);
    root->right = createNode(30);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(70);
    root->right->right = createNode(60);
                  
      /* while(num-- >0)
      {
	  }*/
     do
      {
              printf("\n***************BINARY TREE TRAVERSAL MENU***************\n");
              printf("[1] Use Inorder Traversal for display\n");
              printf("[2] Use Preorder Traversal for display\n");
              printf("[3] Use Postorder Traversal for display\n");
              printf("[4] To Exit\n");
              printf("\nEnter Your Choice: ");
              scanf("%d", &ch);
              switch(ch)
              {
                        case 1:
                               printf("\nThe Inorder Traversal Sequence is: \n");
                               inorder(root);printf("\n");
                               break;
                        case 2:
                               printf("\nThe Preorder Traversal Sequence is: \n");
                               preorder(root);printf("\n");
                               break;
                        case 3:
                               printf("\nThe Postorder Traversal Sequence is: \n");
                               postorder(root);printf("\n");
                               break;
                        case 4:
                               exit(0);
                        default:
                               printf("\nWrong Choice!!!...Please Try Again... \n");
              }
      }while(ch<5);
}
