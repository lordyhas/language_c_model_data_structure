#include "tree.h"

Node createNode(Object o){
    Node node = (Node) malloc(sizeof(struct node));
    if(node == NULL){
        fprintf(stderr, "Alloction Error : Node is NULL ");
        return NULL;
    }
    node->value = o;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

Tree createTree(Object o){
    Tree tree = (Tree) malloc(sizeof(struct tree));
    return tree;
}
void addNodeLeft(Node p,Node node){
    if(p->left == NULL){
        p->left = node;
        node->parent = p->left;
    }
        
}
void addNodeRight(Node p,Node node){
    if(p->right == NULL){
        p->right = node;
        node->parent = p->right;
    }
       
}
void deleteNodeRight(Node node){
    free(node->right);
    node->right = NULL;
}
void deleteNodeLeft(Node node){
    free(node->left);
    node->left = NULL;
}
 
Node getNodeLeft(Node node){
    return node->left;
}
Node getNodeRight(Node node){
    return node->right;
}
Node getNodeParent(Node node){
    return node->parent;
}
void setNodeLeft(Node p,Node node){
    p->left = node;
}
void setNodeRight(Node p, Node node){
    p->right = node;
}
//void getNodeRightBrother(Node);
Bool isSingleNode(Node node){
    if(node->right == NULL && node->left == NULL)
        return True;
    return False;
}
Bool estFeuille(Node node){}

Object getValueNode(Node node){
    return node->value;
}
void setValueNode(Node node,Object o){
    node->value = o;
}

void destroyTree(Tree tree){
    free(tree);
    
}

void destroyNode(Node node){
    free(node);
}
