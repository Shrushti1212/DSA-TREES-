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
-------------------------------------------------------------------------------------------------------------------------------------------------------------------

------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Hackerrank
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// Insert in BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Inorder traversal (no trailing space)
void inorder(struct Node* root, int *first) {
    if (root) {
        inorder(root->left, first);

        if (!(*first)) printf(" ");
        printf("%d", root->data);
        *first = 0;

        inorder(root->right, first);
    }
}

int main() {
    int n, x, insertVal;
    struct Node* root = NULL;

    scanf("%d", &n);

    // Check invalid input
    if (n == -1) {
        printf("Invalid input");
        return 0;
    }

    // Read n router IDs
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        if (x == -1) {
            printf("Invalid input");
            return 0;
        }

        root = insert(root, x);
    }

    // Read value to insert
    scanf("%d", &insertVal);

    if (insertVal == -1) {
        printf("Invalid input");
        return 0;
    }

    root = insert(root, insertVal);

    int first = 1;
    inorder(root, &first);

    return 0;
}

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int n, x, insertNode, deleteVal;
    struct Node* root = NULL;

    scanf("%d", &n);

    // Initial nodes
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    // Extra insertion
    scanf("%d", &insertNode);
    root = insert(root, insertNode);

    // Deletion
    scanf("%d", &deleteVal);
    root = deleteNode(root, deleteVal);

    printf("Current File Index sorted in ascending order: ");
    inorder(root);

    return 0;
}
