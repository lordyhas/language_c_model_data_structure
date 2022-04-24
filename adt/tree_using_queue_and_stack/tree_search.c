#include "tree_search.h"

Node findNode(Node tree, Node node){
    Node p = createNode(-1);
    memcpy(p,tree, sizeof(*p));
    if(tree == NULL || node == NULL) return NULL;

    //if(isSingleNode(tree)) return NULL;

    //node != tree
    while (tree != NULL){
        
        if(getValueNode(node) == getValueNode(tree)) 
            return tree;
        if(getValueNode(node) > getValueNode(tree)){
            tree = getNodeRight(tree);
        }else{
            tree = getNodeLeft(tree);
        }
    }
    return tree;
    
}

Node predecessor(Node node){

    Node x = getNodeRight(node);

}


Node successor(Node root){
    Node node = createNode(-1);
    memcpy(node,root, sizeof(*node));
    if(isSingleNode(node)) return node;
    

    Node x = getNodeRight(node);
    Node y = NULL;
    if(!isSingleNode(x))
        y = getNodeLeft(x);
    
    if(y==NULL)
        return x;
    return y;
}

void addNode(Node p, Node node){
   
    if(isSingleNode(p)){
        if(getValueNode(node) < getValueNode(p))
            addNodeLeft(p,node);
            
        else
            addNodeRight(p,node);
        return;
    } 


    while (p!=NULL){
        if(getValueNode(node) < getValueNode(p)){
            if(getNodeLeft(p)==NULL){
                addNodeLeft(p,node);
                return;
            }
            p = getNodeLeft(p);
        }
        else{
            if(getNodeRight(p)==NULL){
                addNodeRight(p,node);
                return;
            }
            p = getNodeRight(p);
        }

    }
   
}


void removeNode(Node root, Node node){
    if(root == NULL || node == NULL) return;
    Node nw;
    
    if (getValueNode(root) != getValueNode(node)){
        node = findNode(root,node);
        if(node == NULL) return;
    }
    nw = successor(node);
    setValueNode(node, getValueNode(nw));
    if(isSingleNode(nw)){
        setValueNode(nw, getValueNode(createNode(-1)));       
        //free(node);
        //nw = NULL;  
        return;
    }
    else if(getNodeLeft(nw)==NULL){
        nw = getNodeRight(nw);
    }
    else if(getNodeRight(nw)==NULL){
        nw = getNodeLeft(nw);
    } 
    else removeNode(nw,nw);
    
}

