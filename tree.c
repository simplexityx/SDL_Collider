#include "tree.h"







tree_t *tree_create(cmpfunc_t cmpfunc){

    tree_t *newTree = malloc(sizeof(tree_t));
    
    newTree->cmpfunc = cmpfunc;
    newTree->root = NULL;
    newTree->size = 0;
    return newTree;
}

/*
    Helper function to create a given node, called by tree_insert()
*/
node_t *newNode(int elem){

    node_t *newNode = malloc(sizeof(node_t));

    newNode->elem = elem;
    newNode->left = newNode->right = NULL;
    return newNode;
}


node_t *_tree_insert(tree_t *tree, node_t *oldNode, node_t *newNode){

    if(oldNode == NULL){
        oldNode = newNode;
        tree->size++;
        return oldNode;
    }

    if(tree->cmpfunc((void*)&oldNode->elem, (void*)&newNode->elem) > 0){
        oldNode->left = _tree_insert(tree, oldNode->left, newNode);
    }else{
        oldNode->right = _tree_insert(tree, oldNode->right, newNode);
    }
}


/*
    Inserts the given element into the tree (done recursively)
*/
void tree_insert(tree_t *tree, int elem){

    node_t *node = newNode(elem);
    tree->root = _tree_insert(tree, tree->root, node);
    return;
}


void _tree_print(node_t *root){

    if(root == NULL)
        return;

    printf("%d\n", root->elem);

    _tree_print(root->left);
    _tree_print(root->right);
}


void tree_print(tree_t *tree){
    _tree_print(tree->root);
}


