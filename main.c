#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define N 50

// Definition of a tree node
struct TreeNode {
    char name[N];       // Category name
    int expense[2];     // Maximum of two expenses per category
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function prototypes
struct TreeNode* CreateTree(void);
struct TreeNode* Insert(char name[], int x, struct TreeNode* t);
void DisplayTree(struct TreeNode*);
struct TreeNode* MakeEmpty(struct TreeNode* t);
struct TreeNode* searchCategory(char name[], struct TreeNode* t);
void AddExpense(struct TreeNode* node, int x);  // Function to add a second expense

int main() {
    struct TreeNode* myTree;
    int exit;
    char name[N];
    int x;
    struct TreeNode *p;
    char command;

    myTree = CreateTree();
    exit = FALSE;

    while (!exit) {
        // Menu for user commands
        printf("\nMenu:\n i)nitialize\n n)ew element \n e)xit\n s)search\n d)isplay\nEnter command: ");
        scanf(" %c", &command);

        switch(command) {
            case 'i': // Initialize tree (delete all nodes)
                myTree = MakeEmpty(myTree);
                break;

            case 'n': // Insert new category or add an expense
                printf("\nEnter the name: ");
                scanf("%s", name);
                printf("\nEnter the value: ");
                scanf("%d", &x);

                struct TreeNode* found = searchCategory(name, myTree);
                if (found != NULL) {
                    // If the category exists, try adding an expense
                    AddExpense(found, x);
                } else {
                    // If the category does not exist, insert a new one
                    myTree = Insert(name, x, myTree);
                }
                break;

            case 's': // Search for a category
                printf("\nEnter the name: ");
                scanf("%s", name);
                p = searchCategory(name, myTree);
                if (p != NULL) {
                    if (p->expense[1] != 0)
                        printf("\n%d %d", p->expense[0], p->expense[1]);
                    else
                        printf("\n%d ", p->expense[0]);
                } else {
                    printf("\nCategory not found.");
                }
                break;

            case 'd': // Display the entire tree
                DisplayTree(myTree);
                break;

            case 'e': // Exit the program
                exit = TRUE;
                break;

            default:
                printf("Command not recognized\n");
                break;
        }
    }

    printf("\n\n");
    system("PAUSE");
    return 0;
}

// Creates an empty tree
struct TreeNode* CreateTree(void) {
    return NULL;
}

// Deletes all nodes from the tree
struct TreeNode* MakeEmpty(struct TreeNode* t) {
    if (t != NULL) {
        MakeEmpty(t->left);
        MakeEmpty(t->right);
        free(t);
    }
    return NULL;
}

// Inserts a new category into the binary search tree
struct TreeNode* Insert(char name[], int x, struct TreeNode* t) {
    if (t == NULL) { // If the tree is empty, create a new node
        t = (struct TreeNode*) malloc(sizeof(struct TreeNode));
        if (t == NULL)
            printf("Out of memory space!!!\n");
        else {
            strcpy(t->name, name);
            t->expense[0] = x; // Store first expense
            t->expense[1] = 0; // No second expense yet
            t->left = t->right = NULL;
        }
    } else if (strcmp(name, t->name) < 0) {
        // If the new name is smaller, insert into the left subtree
        t->left = Insert(name, x, t->left);
    } else if (strcmp(name, t->name) > 0) {
        // If the new name is greater, insert into the right subtree
        t->right = Insert(name, x, t->right);
    }
    return t;
}

// Adds a second expense to an existing category (if possible)
void AddExpense(struct TreeNode* node, int x) {
    if (node->expense[1] == 0) {
        node->expense[1] = x; // Store second expense
    } else {
        printf("Error: Cannot add more than 2 expenses for a category.\n");
    }
}

// Displays the tree in-order (sorted order)
void DisplayTree(struct TreeNode* t) {
    if (t != NULL) {
        DisplayTree(t->left);
        if (t->expense[1] != 0)
            printf("%s %d %d\n", t->name, t->expense[0], t->expense[1]);
        else
            printf("%s %d\n", t->name, t->expense[0]);
        DisplayTree(t->right);
    }
}

// Searches for a category in the tree and returns a pointer to the node
struct TreeNode* searchCategory(char name[], struct TreeNode* t) {
    if (t == NULL)
        return NULL; // Category not found
    else if (strcmp(name, t->name) == 0)
        return t; // Category found
    else if (strcmp(name, t->name) > 0)
        return searchCategory(name, t->right); // Search in right subtree
    else
        return searchCategory(name, t->left);  // Search in left subtree
}
