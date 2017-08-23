#include <iostream>

using namespace std;

class Node{
friend class List;
private:
	string question;
	string A;
  string B;
	Node *next;
  Node *down;

public:
  Node();
	Node(string q,string a,string b);
};
