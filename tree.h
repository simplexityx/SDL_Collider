#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include <stdlib.h>
#include "box.h"
#include "Renderer.h"
#include <pthread.h>


typedef struct renderer renderer_t;

typedef int (*cmpfunc_t)(void *, void *);
typedef struct node node_t;

struct node{
    node_t *left, *right;
    box_t *box;
};

typedef struct tree {
    node_t *root;
    int size;
    cmpfunc_t cmpfunc;
} tree_t;


tree_t *tree_create(cmpfunc_t cmpfunc);

void tree_insert(tree_t *tree, box_t *b);

void tree_update(tree_t *tree);

void tree_draw(tree_t *tree, renderer_t *r);

void tree_remove(tree_t *tree, void *elem);

void tree_purge(tree_t *tree, void *elem);

void tree_print(tree_t *tree);


#endif