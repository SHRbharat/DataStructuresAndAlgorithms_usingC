#include "tree.h"

int main() {

    nodeptr root = makeTree('A');
    setLeft(root, 'B');
    setRight(root, 'C');
    setLeft(root->left, 'D');
    setRight(root->left, 'E');
    setLeft(root->right, 'F');
    printTree(root, 0);
    return 0;
}