#include <iostream>
#include <stack>
using namespace std;

typedef int typeinfo;

struct Node
{
	int data;
	Node* link;
};
typedef Node* Nodeptr;

void init(Nodeptr& head);
Nodeptr makeNode(typeinfo x);
void release(Nodeptr& head);
void print(Nodeptr head);
bool isEmpty(Nodeptr head);
void addFirst(Nodeptr& head, typeinfo x);
Nodeptr findX(Nodeptr head, typeinfo x);
void addLast(Nodeptr& head, typeinfo x);
Nodeptr tronTangDan(Nodeptr& ds1, Nodeptr& ds2);
void swap(typeinfo& x, typeinfo &y);
void sapXepTangDan(Nodeptr& head);
void sapXepGiamDan(Nodeptr& head);

int length(Nodeptr head);
Nodeptr nodeIndex(Nodeptr head, int idx);
bool kt_doixung(Nodeptr head);