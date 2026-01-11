#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Queue Implementation
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    struct QueueNode* newQNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newQNode->treeNode = node;
    newQNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newQNode;
        return;
    }

    q->rear->next = newQNode;
    q->rear = newQNode;
}

struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL)
        return NULL;

    struct QueueNode* temp = q->front;
    struct Node* node = temp->treeNode;

    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return node;
}

int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

//Tree Node Creation
struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

// Standard Traversals
void reverseInorder(struct Node* root) {
    if (root == NULL)
        return;
    reverseInorder(root->right);
    printf("%d ", root->data);
    reverseInorder(root->left);
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Level Order
void levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        struct Node* current = dequeue(q);
        printf("%d ", current->data);

        if (current->left)
            enqueue(q, current->left);
        if (current->right)
            enqueue(q, current->right);
    }
}

//Spiral (Zig-Zag) Traversal
void spiralTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* s1[100]; // Left to Right
    struct Node* s2[100]; // Right to Left
    int top1 = -1, top2 = -1;

    s1[++top1] = root;

    while (top1 >= 0 || top2 >= 0) {
        while (top1 >= 0) {
            struct Node* temp = s1[top1--];
            printf("%d ", temp->data);

            if (temp->right)
                s2[++top2] = temp->right;
            if (temp->left)
                s2[++top2] = temp->left;
        }

        while (top2 >= 0) {
            struct Node* temp = s2[top2--];
            printf("%d ", temp->data);

            if (temp->left)
                s1[++top1] = temp->left;
            if (temp->right)
                s1[++top1] = temp->right;
        }
    }
}

//Left View
void leftView(struct Node* root) {
    if (root == NULL)
        return;

    struct Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        int n = 0;
        struct QueueNode* temp = q->front;

        // Count nodes in current level
        for (struct QueueNode* t = q->front; t != NULL; t = t->next)
            n++;

        for (int i = 1; i <= n; i++) {
            struct Node* node = dequeue(q);

            // Print the first node of this level
            if (i == 1)
                printf("%d ", node->data);

            if (node->left)
                enqueue(q, node->left);
            if (node->right)
                enqueue(q, node->right);
        }
    }
}

//Right View
void rightView(struct Node* root) {
    if (root == NULL)
        return;

    struct Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        int n = 0;
        for (struct QueueNode* t = q->front; t != NULL; t = t->next)
            n++;

        for (int i = 1; i <= n; i++) {
            struct Node* node = dequeue(q);

            // Print the last node of this level
            if (i == n)
                printf("%d ", node->data);

            if (node->left)
                enqueue(q, node->left);
            if (node->right)
                enqueue(q, node->right);
        }
    }
}

// Boundary Traversal

// Print left boundary excluding leaves
void printLeftBoundary(struct Node* root) {
    struct Node* curr = root->left;
    while (curr) {
        if (curr->left || curr->right)
            printf("%d ", curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

// Print right boundary excluding leaves (stored in reverse)
void printRightBoundary(struct Node* root) {
    struct Node* curr = root->right;
    int stack[100], top = -1;
    while (curr) {
        if (curr->left || curr->right)
            stack[++top] = curr->data;
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    while (top >= 0)
        printf("%d ", stack[top--]);
}

// Print all leaf nodes
void printLeaves(struct Node* root) {
    if (root == NULL)
        return;
    printLeaves(root->left);
    if (root->left == NULL && root->right == NULL)
        printf("%d ", root->data);
    printLeaves(root->right);
}

// Main boundary traversal function
void boundaryTraversal(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data); // root

    printLeftBoundary(root);
    printLeaves(root);
    printRightBoundary(root);
}

int main() {
    struct Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->left = newNode(6);
    root->right->right = newNode(8);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    printf("Reverse Inorder Traversal: ");
    reverseInorder(root);
    printf("\n");

    printf("Level Order Traversal: ");
    levelOrder(root);
    printf("\n");

    printf("Spiral Traversal: ");
    spiralTraversal(root);
    printf("\n");

    printf("Left View: ");
    leftView(root);
    printf("\n");

    printf("Right View: ");
    rightView(root);
    printf("\n");

    printf("Boundary Traversal: ");
    boundaryTraversal(root);
    printf("\n");

    return 0;
}
