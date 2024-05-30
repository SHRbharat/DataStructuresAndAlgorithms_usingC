#include <stdio.h>
#include <stdlib.h>

struct Node {
  char info;
  struct Node *left;
  struct Node *right;
  struct Node *father;
};

typedef struct Node *nodeptr;

nodeptr getNode() {
  nodeptr q = (nodeptr)malloc(sizeof(struct Node));
  if (q == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }
  return q;
}

nodeptr makeTree(char x) {
  nodeptr q = getNode();
  q->info = x;
  q->right = q->left = NULL;
  q->father = NULL; // Initialize father as NULL
  return q;
}

void setLeft(nodeptr p, char x) {
  if (p == NULL) {
    printf("Cannot insert into null node\n");
    return;
  }
    
  if (p->left != NULL) {
    printf("Left child already exists\n");
    return; 
  }
  p->left = makeTree(x);
  p->left->father = p; // Set the father pointer
}

void setRight(nodeptr p, char x) {
  if (p == NULL) {
    printf("Cannot insert into null node\n");
    return; 
  }
  if (p->right != NULL) {
    printf("Right child already exists\n");
    return; 
  }
  p->right = makeTree(x);
  p->right->father = p; // Set the father pointer
}

void printTree(nodeptr root, int space) {
    if (root == NULL)
    {
        return;
    }
    space +=5;
    printTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++)
    {
        printf(" ");
    }
    printf("%c \n", root->info);

    printTree(root->left, space);
}
    

