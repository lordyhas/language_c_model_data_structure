#include "util.h"
typedef int Object;
typedef struct node *Node, Node_;

struct node{
    Object value;
    Node right, left, parent;
} ;


typedef struct tree
{
    Node root;
    Node key;
    int length;
    int height;

} *Tree;


Node createNode(Object);
Tree createTree(Object o);
void addNodeLeft(Node,Node);
void addNodeRight(Node,Node);
void deleteNodeRight(Node);
void deleteNodeLeft(Node);
 
Node getNodeLeft(Node);
Node getNodeRight(Node);
Node getNodeParent(Node);
void setNodeLeft(Node,Node);
void setNodeRight(Node, Node);
//void getNodeRightBrother(Node);
Bool isSingleNode(Node);
Bool estFeuille(Node);

Object getValueNode(Node);
void setValueNode(Node,Object);

void destroyTree(Tree);
void destroyNode(Node);





