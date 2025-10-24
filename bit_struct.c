#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

void reverseInorder(struct Node* root) {
    if (root == NULL)
        return;
    reverseInorder(root->right);

    printf("%d ", root->data);

    reverseInorder(root->left);
}

int main() {
    struct Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->left = newNode(6);
    root->right->right = newNode(8);
	
	printf("Reverse Inorder Traversal: ");
    printf("Reverse Inorder Traversal: ");
    reverseInorder(root);

    return 0;
}
