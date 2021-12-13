/**
 * @brief: algorithm to search a tree for a particular number.
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void add_node (struct node **root)