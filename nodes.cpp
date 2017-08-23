#include "nodes.h"

Node::Node(){}
Node::Node(string q,string a,string b){
    question=q;
    A=a;
    B=b;
    next=NULL;
    down=NULL;
}
