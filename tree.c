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
node_t *newNode(box_t *b){

    node_t *newNode = malloc(sizeof(node_t));

    newNode->box = b;
    newNode->left = newNode->right = NULL;
    return newNode;
}


node_t *_tree_insert(tree_t *tree, node_t *oldNode, node_t *newNode){

    if(oldNode == NULL){
        oldNode = newNode;
        tree->size++;
        printf("inserted id: %d into the tree\n", newNode->box->id);
        return oldNode;
    }

    if(tree->cmpfunc((void*)&oldNode->box->id, (void*)&newNode->box->id) > 0){
        oldNode->left = _tree_insert(tree, oldNode->left, newNode);
    }else{
        oldNode->right = _tree_insert(tree, oldNode->right, newNode);
    }
}


/*
    Inserts the given element into the tree (done recursively)
*/
void tree_insert(tree_t *tree, box_t *b){

    node_t *node = newNode(b);
    tree->root = _tree_insert(tree, tree->root, node);
    return;
}


void _tree_update(node_t *root){
    
    if(root == NULL)
        return;
    root->box->col(root->box);
    root->box->up(root->box);
    _tree_update(root->left);
    _tree_update(root->right);
}


void tree_update(tree_t *tree){
    _tree_update(tree->root);
}

void _tree_draw(node_t *root, renderer_t *r){
    if(root == NULL)
        return;

    SDL_RenderCopy(r->renderer, root->box->tex, &root->box->src, &root->box->dst);
    _tree_draw(root->left, r);
    _tree_draw(root->right, r);
}


void tree_draw(tree_t *tree, renderer_t *r){
    _tree_draw(tree->root, r);
}





void _tree_print(node_t *root){

    if(root == NULL)
        return;

    printf("%d\n", root->box->id);

    _tree_print(root->left);
    _tree_print(root->right);
}


void tree_print(tree_t *tree){
    _tree_print(tree->root);
}


