/**
 * @brief: algorithm to search a tree for a particular number.
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *getNewNode(int data)
{
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    return newNode;
}

void addNode(struct node **root, int data)
{
    if (*root == NULL)
    {
        //empty tree
        *root = getNewNode(data);
    }

    else if (data <= (*root)->data)
    {
        addNode((&(*root)->left), data);
    }
    else
        addNode((&(*root)->right), data);
}

int search(struct node *root, int data)
{
    if (root == NULL)
        return 0;
    else if (root->data == data)
        return 1;
    else if (data <= root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

int main(void)
{
    struct node *root;
    root = NULL;
    int num;

    addNode(&root, 15);
    addNode(&root, 10);
    addNode(&root, 20);
    addNode(&root, 7);
    addNode(&root, 9);
    addNode(&root, 30);
    addNode(&root, 27);
    addNode(&root, 12);
    addNode(&root, 11);

    printf("Enter number to be searched: ");
    scanf("%d", &num);

    if (search(root, num))
        printf("Found!\n");
    else
        printf("Not found!\n");

    return 0;
}