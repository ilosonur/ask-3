#include "nodes.h"

class Node;
class List{
  private:
    Node *head;
  public:
    List();
    ~List();
    void addNextNode(string question, string A, string B, int index);
		void addDownNode(string question, string A, string B,int index);
};
