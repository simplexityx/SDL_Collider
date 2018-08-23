#include <stdio.h>
#include <stdlib.h>


typedef int (*cmpfunc_t)(void *, void *);
typedef struct node node_t;

struct node{
    node_t *left, *right;
    int elem;
};

typedef struct tree {
    node_t *root;
    int size;
    cmpfunc_t cmpfunc;
} tree_t;


tree_t *tree_create(cmpfunc_t cmpfunc);

void tree_insert(tree_t *tree, int elem);

void tree_remove(tree_t *tree, void *elem);

void tree_purge(tree_t *tree, void *elem);

void tree_print(tree_t *tree);