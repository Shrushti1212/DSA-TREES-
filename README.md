//Binary Tree Node Structure

#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Add Node to the Left of a Given Node

int main() {
    struct Node* root = createNode(1);

    addLeft(root, 2);   // add 2 as left child of root
    addLeft(root->left, 4); // add 4 as left child of node 2

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Add node to left of a given node
void addLeft(struct Node* parent, int value) {
    if (parent == NULL) {
        printf("Parent node is NULL\n");
        return;
    }

    parent->left = createNode(value);
}
.
